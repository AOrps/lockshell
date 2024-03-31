# :bullettrain_side: Onboarding
- Minimize time to ramp up on repo

## :monocle_face: State Diagram
<!-- https://mermaid.js.org/syntax/stateDiagram.html -->

### Log Architecture
```mermaid

```

### Program Architecture
```mermaid
---
title: Simple sample
---
stateDiagram-v2
    [*] --> Main
    Still --> [*]

    Still --> Moving
    Moving --> Still
    Moving --> Crash
    Crash --> [*]
```

## :target: Goals
- The goal to get a running beta (MVP) for some tool utility are the following:
  - [ ] Logging to a `/var/log/` area
  - [ ] Playback Functionality


## :technologist: Nice to haves / Features to implement
- [ ] Logging
- [ ] Constraints 
  - [x] Time constraint to prevent generating a bunch of useless files running this program
- [ ] Interactivity
  - Get threat information from how an adversary uses the shell
  - Playback functionality (like cowrie or script or scriptreplay)
  - read for playback: https://github.com/util-linux/util-linux/tree/master/term-utils , https://github.com/util-linux/util-linux/blob/master/term-utils/script.c#L757 , https://github.com/util-linux/util-linux/blob/master/term-utils/scriptreplay.c
- [ ] OpenSSF Best Practices Badge Program
  - https://www.bestpractices.dev/en

## :book: Resources
- General:
  - **https://blog.logrocket.com/guide-signal-handling-rust/#signal-handling-with-tokio**
  - https://rust-cli.github.io/book/in-depth/signals.html
  - https://docs.rs/signal-hook/latest/signal_hook/#modules
  - https://tokio.rs/tokio/tutorial/hello-tokio
- Library Internals:
  - https://github.com/tokio-rs/tokio/blob/master/tokio/src/signal/unix.rs
