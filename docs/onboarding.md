# :bullettrain_side: Onboarding
- Minimize time to ramp up on repo

## :monocle_face: State Diagram
<!-- https://mermaid.js.org/syntax/stateDiagram.html -->
```mermaid

```


## :technologist: Nice to haves / Features to implement
- [x] Logging
  - Eventually to be picked up from a SIEM
  - Writes to [./losh.log], however segfault when writing to a area that doesn't exist
- [ ] Constraints 
  - Time constraint to prevent generating a bunch of useless files running this program
- [ ] VM / Container Isolation
  - Prevent Shell Escape
- [ ] Taunting art (like flipper or pwnagochi)
  - Bc funny (and c graphics seems cool)
- [ ] Interactivity
  - Get threat information from how an adversary uses the shell
  - Playback functionality
- [ ] Testing / Assertions
  - To validate that program runs as intended (for the most part)
- [ ] Analytics
  - Research findings on whether or not pooling resources is more efficient
- [ ] Custom Config File
  - Setup Configurations to keep compiliation size (and exploitablity low)

## :book: Resources
- https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/#
- https://developerinsider.co/simple-and-static-assertion-assert-in-c-programming-language/
