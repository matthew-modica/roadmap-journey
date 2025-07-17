# Phase 1 — Core C & Linux Systems Programming

**Duration:** ~6 weeks  
**Goal:** Master fundamental Unix/Linux programming concepts and build practical system programming skills

---

## Essential Reading

### Study Progress
- [ ] *The Linux Programming Interface* Ch. 4-5 (File I/O: The Universal I/O Model, File I/O: Further Details)
- [ ] *The Linux Programming Interface* Ch. 24-25 (Process Creation, Process Termination)
- [ ] *The Linux Programming Interface* Ch. 20-21 (Signals: Fundamental Concepts, Signal Handlers)
- [ ] *The Linux Programming Interface* Ch. 44 (Pipes and FIFOs)
- [ ] *The Linux Programming Interface* Ch. 23 (Timers and Sleeping)
- [ ] *The Linux Programming Interface* Ch. 18 (Directories and Links)

### Reading Notes

#### Chapter 4-5: File I/O
*Notes on file operations, file descriptors, error handling*

#### Chapter 24-25: Process Creation & Termination
*Notes on fork(), exec(), wait(), process lifecycle*

#### Chapter 20-21: Signals
*Notes on signal handling, signal masks, signal handlers*

#### Chapter 44: Pipes and FIFOs
*Notes on pipe(), unnamed pipes, named pipes*

#### Chapter 23: Timers
*Notes on timerfd, alarm(), interval timers*

#### Chapter 18: Directories and Links
*Notes on opendir(), readdir(), directory traversal*

---

## Project 1: Unix Tools Recreation

### Implementation Tasks
- [ ] **my_ls** - Directory listing tool
  - [ ] Basic directory reading with `opendir()`/`readdir()`
  - [ ] Command-line argument parsing
  - [ ] File stat information display
  - [ ] Error handling and edge cases
  - [ ] Memory management and cleanup

- [ ] **my_cat** - File concatenation tool
  - [ ] File reading with proper buffering
  - [ ] Multiple file handling
  - [ ] stdin support when no files specified
  - [ ] Error handling for file access
  - [ ] Performance optimization

- [ ] **my_cp** - File copying tool
  - [ ] Source to destination file copying
  - [ ] Preserve file permissions and timestamps
  - [ ] Directory copying support
  - [ ] Progress indication for large files
  - [ ] Error handling and rollback

- [ ] **my_grep** - Pattern matching tool
  - [ ] Basic string searching
  - [ ] Line number output (-n flag)
  - [ ] Case-insensitive search (-i flag)
  - [ ] Multiple file support
  - [ ] Memory-efficient line processing

### Testing & Validation
- [ ] Unit tests for each tool
- [ ] Comparison with original Unix tools
- [ ] Memory leak detection with `valgrind`
- [ ] Static analysis with `clang-tidy` and `cppcheck`
- [ ] Performance benchmarking

---

## Project 2: Mini-Shell Development

### Core Shell Implementation
- [ ] **Command Parser**
  - [ ] Tokenize input into commands and arguments
  - [ ] Handle quotes and escape sequences
  - [ ] Parse pipe operators and redirections
  - [ ] Built-in command detection

- [ ] **Process Execution**
  - [ ] Fork and exec for external commands
  - [ ] Built-in commands (`cd`, `pwd`, `exit`, `help`)
  - [ ] Process waiting and status collection
  - [ ] Background process support (`&`)

- [ ] **Pipe Implementation**
  - [ ] Create pipes between processes
  - [ ] Handle multi-stage pipelines
  - [ ] Proper file descriptor management
  - [ ] Error handling in pipe chains

- [ ] **I/O Redirection**
  - [ ] Output redirection (`>`, `>>`)
  - [ ] Input redirection (`<`)
  - [ ] Error redirection (`2>`, `2>>`)
  - [ ] File descriptor duplication

- [ ] **Signal Handling**
  - [ ] SIGINT (Ctrl+C) - interrupt foreground process
  - [ ] SIGTSTP (Ctrl+Z) - suspend foreground process
  - [ ] SIGCHLD - clean up zombie processes
  - [ ] Signal masking and restoration

### Advanced Features
- [ ] **Job Control**
  - [ ] Job list management
  - [ ] `jobs` command implementation
  - [ ] `fg` and `bg` commands
  - [ ] Process group management

- [ ] **Command History**
  - [ ] History storage and retrieval
  - [ ] History expansion
  - [ ] Command editing capabilities

### Testing & Validation
- [ ] Interactive testing with various commands
- [ ] Automated test suite
- [ ] Signal handling verification
- [ ] Memory leak detection
- [ ] Stress testing with complex pipelines

---

## Project 3: Cooperative Scheduler

### Scheduler Implementation
- [ ] **Task Structure Design**
  - [ ] Function pointer-based task system
  - [ ] Task state management
  - [ ] Priority levels and scheduling policies
  - [ ] Task data and context storage

- [ ] **Timer-Based Scheduling**
  - [ ] `timerfd` setup and configuration
  - [ ] Periodic task execution
  - [ ] Task timing and deadline management
  - [ ] Scheduler main loop

- [ ] **Task Management**
  - [ ] Task creation and destruction
  - [ ] Task queue management
  - [ ] Task switching and context
  - [ ] Resource sharing and synchronization

### Example Tasks
- [ ] **Periodic File Monitor**
  - [ ] Monitor file changes in directory
  - [ ] Log file modifications
  - [ ] Configurable monitoring interval

- [ ] **System Resource Monitor**
  - [ ] CPU usage tracking
  - [ ] Memory usage monitoring
  - [ ] Periodic status reporting

- [ ] **Network Connection Checker**
  - [ ] Periodic network connectivity tests
  - [ ] Connection status logging
  - [ ] Retry logic for failed connections

### Testing & Validation
- [ ] Multi-task execution verification
- [ ] Timing accuracy testing
- [ ] Resource usage monitoring
- [ ] Single-file implementation constraint
- [ ] Performance profiling

---

## Integration & Documentation

### Final Integration
- [ ] **Unified Build System**
  - [ ] Comprehensive Makefile
  - [ ] Dependency management
  - [ ] Debug and release configurations
  - [ ] Cross-platform compatibility

- [ ] **Code Quality**
  - [ ] Consistent coding style
  - [ ] Comprehensive error handling
  - [ ] Memory leak elimination
  - [ ] Static analysis compliance

### Documentation
- [ ] **README Documentation**
  - [ ] Project overview and goals
  - [ ] Build and installation instructions
  - [ ] Usage examples and demos
  - [ ] Design decisions and architecture

- [ ] **Code Documentation**
  - [ ] Function and structure documentation
  - [ ] Algorithm explanations
  - [ ] Performance considerations
  - [ ] Known limitations and future work

---

## Success Criteria

### Technical Milestones
- [ ] All Unix tools pass comparison tests with original versions
- [ ] Mini-shell handles complex command pipelines correctly
- [ ] Cooperative scheduler runs multiple tasks reliably
- [ ] All code is memory-leak free (valgrind clean)
- [ ] Static analysis shows no warnings or errors

### Skills Demonstrated
- [ ] Proficient with file I/O operations
- [ ] Understanding of process creation and management
- [ ] Signal handling and job control
- [ ] Inter-process communication (pipes)
- [ ] Timer-based programming
- [ ] Memory management and debugging

---

## Project Structure

```
phase1/
├── src/
│   ├── tools/
│   │   ├── my_ls.c
│   │   ├── my_cat.c
│   │   ├── my_cp.c
│   │   └── my_grep.c
│   ├── shell/
│   │   ├── shell.c
│   │   ├── parser.c
│   │   ├── executor.c
│   │   └── signals.c
│   └── scheduler/
│       └── scheduler.c
├── include/
│   ├── tools.h
│   ├── shell.h
│   └── scheduler.h
├── tests/
│   ├── test_tools.sh
│   ├── test_shell.sh
│   └── test_scheduler.sh
├── docs/
│   ├── README.md
│   ├── DESIGN.md
│   └── API.md
└── Makefile
```

---

## Resources & References

### Essential Tools
- **Debugging:** `gdb`, `valgrind`, `strace`
- **Analysis:** `clang-tidy`, `cppcheck`, `static-analyzer`
- **Profiling:** `perf`, `time`, `htop`
- **Testing:** Shell scripting, custom test harnesses

### Reference Materials
- Linux manual pages (`man 2 fork`, `man 3 opendir`)
- POSIX standards documentation
- GNU C Library documentation
- System programming best practices guides