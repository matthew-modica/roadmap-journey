# Road‑Map: Embedded Systems + Linux + Edge‑AI (≈ 18 months)

## Current Phase

    Phase 0: Ground-Zero Setup

> **Goal:** Build hire‑ready skills across bare‑metal firmware, embedded‑Linux, and edge‑AI by completing a year‑long, week‑by‑week curriculum.
>
> **Structure:** 8 phases • 52 weeks • public repo with code (`src/` → `bin/`, `obj/`) and learning logs (`logs/week_XX.md`).

---

## 📅 Weekly Deliverables (High‑Level)

*Granular day‑to‑day notes live in the matching `logs/week_XX.md` files.*

| Week | Phase / Theme | High‑Level Deliverable |
|------|---------------|------------------------|
| **01** | 0 • Ground‑Zero Setup | Install tool‑chain (<sup>gcc, make, gdb, valgrind, clang‑tidy, cppcheck</sup>); Git + SSH; `hello.c` + Makefile builds to `bin/hello` |
| **02** |                | Skim TLPI ch 1‑3 • demos (`fork`, `mmap`) • first log file |
| **03** | 1 • Core C & Linux | Re‑implement basic `ls` |
| **04** |                | Extend `ls` with `-l -a` & colours |
| **05** |                | Mini `cat` + `grep` clones |
| **06** |                | Mini‑shell v1 (prompt, `fork/execvp`) |
| **07** |                | Mini‑shell v2 (pipes `\|`, redirect`>`) |
| **08** |                | Single‑file cooperative scheduler (`timerfd`, fn‑ptr tasks) |
| **09** | 2 • Bare‑Metal MCU | STM32 blinky (bare‑metal) |
| **10** |                | UART `printf` + button ISR |
| **11** |                | FreeRTOS boots three dummy tasks |
| **12** |                | Queues / semaphores; heartbeat LED shows load |
| **13** |                | Thread‑aware GDB + OpenOCD session |
| **14** |                | Measure context‑switch time via DWT |
| **15** |                | UART CLI ↔ LED blink‑rate demo |
| **16** |                | Mini‑project video + write‑up |
| **17** | 3 • Embedded‑Linux | Build custom 5.x Pi kernel |
| **18** |                | Enable custom GPIO overlay; boot verified |
| **19** |                | User‑space LED bit‑bang driver (`libgpiod`/`/dev/mem`) |
| **20** |                | Yocto/Buildroot minimal rootfs builds |
| **21** |                | SD‑card boots BusyBox + SSH + driver autostart |
| **22** |                | Blog post: kernel→rootfs workflow |
| **23** | 4 • ML Fundamentals | Finish 3B1B linear‑algebra series |
| **24** |                | Probability minisheet |
| **25** |                | PyTorch MNIST (≥ 98 %; ≤ 120 LOC) |
| **26** |                | CIFAR‑10 toy CNN |
| **27** |                | Apply quantisation; size/latency table |
| **28** |                | Prune 20 % weights & compare |
| **29** |                | Float32 vs int8 inference benchmark |
| **30** |                | Mid‑phase reflection log |
| **31** | 5 • TinyML on MCU | TFLite‑Micro “Hello World” sine‑blink |
| **32** |                | Collect “yes/no” audio dataset |
| **33** |                | Train Edge‑Impulse keyword‑spotter; deploy to STM32 |
| **34** |                | Baseline accuracy vs RAM/Flash |
| **35** |                | Rewrite inference loop in pure C |
| **36** |                | Integrate CMSIS‑NN kernels |
| **37** |                | int8 quantisation; update benchmark |
| **38** |                | LUT activations; update benchmark |
| **39** |                | 50 % sparsity experiment |
| **40** |                | Final RAM/Flash vs accuracy matrix |
| **41** |                | TinyML project README + build steps |
| **42** |                | Demo clip + blog post |
| **43** | 6 • Edge‑AI Boards | Flash Jetson Orin Nano/Coral; verify GPIO |
| **44** |                | Port keyword‑spotter; live camera demo |
| **45** |                | Benchmark TensorRT vs CPU‑only |
| **46** |                | Publish results & power‑draw table |
| **47** | 7 • Capstone | Design doc + GitHub project board |
| **48** |                | Assemble HW (STM32 + MEMS mic + LoRa) |
| **49** |                | Firmware: DMA audio → inference → compress → LoRa |
| **50** |                | Gateway: Pi daemon logs LoRa to SQLite |
| **51** |                | Jetson edge‑CNN on selected events |
| **52** |                | Final demo video • docs • résumé bullet |

---

## 🏗️ Build & Run

```bash
make          # builds to bin/
./bin/hello   # example during Week 1
make clean    # purge obj/ and bin/
```

---
