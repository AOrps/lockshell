use std::io::Error;
use std::thread;
// use std::sync::Arc;
// use std::sync::atomic::{AtomicBool, Ordering};
use signal_hook::{consts::SIGINT, iterator::Signals};

fn main() -> Result<(), Error> {

    println!("Hello, world!");

    let mut running = 1;
    // let mut text = String::new();
    
    let mut signals = Signals::new(&[SIGINT])?;

    while running > 0 {
    
	thread::spawn(move || 	    
	    for sig in signals.forever() {
		println!("caught signal: {:?}", sig);
	    });
    }

    Ok(())
}
