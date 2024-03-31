use tokio::signal::unix::{signal, SignalKind};
use std::time::Duration;

const LOG_FILE: &str = "signals.log";

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> { 
    let mut sigint = signal(SignalKind::interrupt())?;

    match sigint.recv().await {
	Some(()) => println!("Received SIGINT signal"),
	None => eprintln!("Stream terminated before receiving SIGINT signal"),
    }


    // let mut sigquit = signal(SignalKind::
    
    let five_seconds = Duration::new(5,0);
    assert_eq!(five_seconds.as_secs(), 5);

    
    Ok(())
}


    // // Create a file to log signals.
    // let mut file = OpenOptions::new()
    //     .create(true)
    //     .write(true)
    //     .truncate(true)
    //     .open(LOG_FILE)
    //     .unwrap();
    // let mut log_file = BufWriter::new(&file);

    // // Install signal handlers to log signals to the file.
    // let sigset = SigSet::empty()
    //     .intersect(&SigSet::sigmask(Signal::SIGTERM))
    //     .intersect(&SigSet::sigmask(Signal::SIGINT));
    // let handler = move || {
    //     writeln!(log_file, "Received signal: {}", Signal::SIGTERM).unwrap();
    // };
    // sigaction(Signal::SIGTERM, SigAction::handler(handler), None).unwrap();
    // sigaction(Signal::SIGINT, SigAction::handler(handler), None).unwrap();

    // // Block SIGTERM and SIGINT signals in the current thread.
    // sigset.block().unwrap();

    // // Create a new thread that runs for 10 seconds.
    // let start_time = Instant::now();
    // thread::spawn(|| {
    //     let duration = Duration::from_secs(10);
    //     while start_time.elapsed() < duration {
    //         // Sleep for a short period of time before checking the elapsed time again.
    //         thread::sleep(Duration::from_millis(100));
    //     }
    // });

    // // Run the process in the main thread, unblocking signals after it's spawned.
    // let pid = match std::process::Command::new("your-command")
    //     .arg("your-args")
    //     .spawn()
    // {
    //     Ok(p) => p.id(),
    //     Err(e) => {
    //         eprintln!("Error starting process: {}", e);
    //         return;
    //     }
    // };
    // sigset.unblock().unwrap();

    // // Wait for the process to finish and log any captured signals while waiting.
    // match process::wait() {
    //     Ok(status) => {
    //         if status.success() {
    //             println!("Process finished successfully");
    //         } else {
    //             eprintln!(
    //                 "Process exited with non-zero exit code: {}",
    //                 status.code().unwrap_or(1)
    //             );
    //         }
    //     }
    //     Err(e) => eprintln!("Error waiting for process: {}", e),
    // }
