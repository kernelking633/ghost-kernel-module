# 👻 ghost-kernel-module (v0.66-alpha)

```text
[TYPE] : Loadable Kernel Module (LKM)
[TARGET]: Linux x86_64 (Kernel 6.x)
[GOAL] : VFS Persistence & KASLR Bypass
```

### 🛠️ Overview
This repository contains a Proof-of-Concept (PoC) for a **Virtual File System (VFS)** persistence primitive. The goal is to hook specific syscalls (`read`, `write`, `getdents64`) to hide files and processes in a stealthy manner.

> [!WARNING]
> **UNSTABLE CODE.** This module directly manipulates the system call table. Improper usage will cause an immediate **Kernel Panic** (Oops). 

---

### 🚨 EMERGENCY UPDATE: 2026-03-19
I've temporarily **suspended** development on the `main` branch. During the last test session, the heap overflow primitive caused a massive memory corruption. 

**IMPORTANT NOTES:**
* The current `main` branch contains a sanitized, non-crashing version of the source.
* **[!] DATA LEAK:** I accidentally pushed the raw, unscrubbed memory logs to the **`pwn-poc-vault`** branch. 
* That branch contains a **heap dump** of the system state during the crash. 
* **DO NOT** merge that branch into `main` until I manually scrub the hardcoded master keys from the memory segments.

---

### 🏗️ Build & Install
```bash
# Prepare the build environment
make clean

# Compile the module (requires kernel headers)
make -j$(nproc)

# Load the module (ONLY IN A VM!)
sudo insmod ghost_mod.ko
```

### 🔍 Research Logs
- `[DONE]` Syscall table hooking via `cr0` register manipulation.
- `[DONE]` Basic file hiding logic (skipping entries in `getdents64`).
- `[TODO]` Implement proper KASLR offset discovery (currently hardcoded).
- `[TODO]` Clean up the `pwn-poc-vault` branch before public release.

---
*"In the kernel, nobody can hear your system scream."*
