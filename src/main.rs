use std::fs::{File, OpenOptions};
use std::io::{BufWriter, Write};
use std::os::unix::io::AsRawFd;
use std::process;
use std::thread;
use std::time::{Duration, Instant};
use nix::sys::signal::{Signal, SigSet, sigaction, SignalHandler};
use nix::sys::signal::SigAction;

const LOG_FILE: &str = "signals.log";

fn main() {
    // Create a file to log signals.
    let mut file = OpenOptions::new()
        .create(true)
        .write(true)
        .truncate(true)
        .open(LOG_FILE)
        .unwrap();
    let mut log_file = BufWriter::new(&file);

    // Install signal handlers to log signals to the file.
    let sigset = SigSet::empty()
        .intersect(&SigSet::sigmask(Signal::SIGTERM))
        .intersect(&SigSet::sigmask(Signal::SIGINT));
    let handler = move || {
        writeln!(log_file, "Received signal: {}", Signal::SIGTERM).unwrap();
    };
    sigaction(Signal::SIGTERM, SigAction::handler(handler), None).unwrap();
    sigaction(Signal::SIGINT, SigAction::handler(handler), None).unwrap();

    // Block SIGTERM and SIGINT signals in the current thread.
    sigset.block().unwrap();

    // Create a new thread that runs for 10 seconds.
    let start_time = Instant::now();
    thread::spawn(|| {
        let duration = Duration::from_secs(10);
        while start_time.elapsed() < duration {
            // Sleep for a short period of time before checking the elapsed time again.
            thread::sleep(Duration::from_millis(100));
        }
    });

    // Run the process in the main thread, unblocking signals after it's spawned.
    let pid = match std::process::Command::new("your-command")
        .arg("your-args")
        .spawn()
    {
        Ok(p) => p.id(),
        Err(e) => {
            eprintln!("Error starting process: {}", e);
            return;
        }
    };
    sigset.unblock().unwrap();

    // Wait for the process to finish and log any captured signals while waiting.
    match process::wait() {
        Ok(status) => {
            if status.success() {
                println!("Process finished successfully");
            } else {
                eprintln!(
                    "Process exited with non-zero exit code: {}",
                    status.code().unwrap_or(1)
                );
            }
        }
        Err(e) => eprintln!("Error waiting for process: {}", e),
    }
}


// use std::io::Error;
// use std::thread;
// // use std::sync::Arc;
// // use std::sync::atomic::{AtomicBool, Ordering};
// use signal_hook::{consts::SIGINT, iterator::Signals};

// fn main() -> Result<(), Error> {

//     println!("Hello, world!");

//     let mut running = 1;
//     // let mut text = String::new();
    
//     let mut signals = Signals::new(&[SIGINT])?;

//     while running > 0 {
    
// 	thread::spawn(move || 	    
// 	    for sig in signals.forever() {
// 		println!("caught signal: {:?}", sig);
// 	    });
//     }

//     Ok(())
// }
