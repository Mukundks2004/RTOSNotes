# Week 2 Module Overview

## What are the concepts of Process state, CPU switch, and Thread?

### Process State

What is a process?

A process is a program in execution, which includes the program code, its current activity, and allocated resources like memory and I/O.

What is a core?

A core is a single processing unit within a CPU (central processing unit) that can independently execute instructions. Modern CPUs may have multiple cores, allowing them to process multiple tasks simultaneously, improving performance, especially for multi-threaded applications.

Process state refers to the various stages that a process (an executing program or task) can go through during its life cycle.

Example states are:
- `new`: the initial state when a process is first created
- `ready`: the process is loaded into memory and waiting to be executed by the CPU
- `running`: the process is currently being executed by the CPU (only one process can be in this state on a single core at a given time)
- `blocked`: the process cannot execute because it is waiting for an event
- `terminated`: the process has completed its execution either successfully or due to error. OS frees resources allocated to the process.

Other states may be `zombie` or `suspended`.

If only one process can run at once, how come when I open task manager there are hundreds of processes listed?

The operating system rapidly switches between processes, so it appears as though multiple processes are running simultaneously. This is done through context switching, where the CPU saves the state of one process and loads the state of another in quick succession.

### CPU Switch

A CPU switch refers to the process where the operating system changes the active process running on the CPU. This typically happens during a context switch, where the CPU switches from executing one process to another, saving the state of the current process and loading the state of the next one.

Context switches are essential for multitasking and allow the operating system to manage multiple processes effectively, giving the illusion of simultaneous execution on a single-core CPU or sharing time on multi-core systems.

#### CPU Switch vs Context Switch

A context switch is the core operating system mechanism that saves the state (registers, program counter) of a running task and loads the state of a new one, enabling multitasking. A CPU switch refers generally to the hardware switching execution from one task to another, which is achieved through context switching

### Thread

A thread is the smallest unit of execution within a process. It represents a single sequence of instructions that can be scheduled and executed by the CPU.

Thread vs Process?

A process is an independent, executing instance of a program. It contains its own memory space, code, and resources (like file handles). Processes are isolated from each other by the operating system.

A thread is a smaller unit of execution within a process. Threads share the same memory space and resources as other threads within the same process.

Each process has its own memory space while threads share global memory and heap memory. Processes are isolated and if one crashes it does not affect other processes. But for threads, if one thread has a bug it may crash the program.

Communication between processes requires IPC like pipes or message queues. Threads can communicate easily by accessing shared memory.

Each tab in a web browser may be a process. A web server may suse threads to handle multiple requests concurrently.

## How the fork system call works?

Fork creates a duplicate of the calling process (the parent), which then begins executing independently.

When a process calls fork(), the operating system creates a new child process that is a copy of the parent process. The child process gets a unique process ID (PID) but has most of the same attributes as the parent process like the same code, data, and stack.

`fork()` syscall returns twice, returns the PID of the child process which is a positive integer in the parent process, and returns `0` for the child process. You can use this to distinguish between the two processes immediately.

Initially, the parent and child share the same memory space. However, they don't copy all of the memory immediately. Instead, they use a technique called Copy-on-Write (COW). With COW, the operating system only creates separate copies of memory when either the parent or child modifies it. So `fork` is memory efficient.

Child has its own `PCB` which is a data structure for tracking process information e.g. PID, PPID, state, etc.

After fork, both the parent and child processes are placed in the ready queue of the process scheduler. Then they are scheduled.

### Example

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // This block runs in the child process
        printf("Hello from the child process (PID: %d)\n", getpid());
    } else {
        // This block runs in the parent process
        printf("Hello from the parent process (PID: %d), Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
```

## How to describe the process scheduling, process creation and termination.

### Process Scheduling

the mechanism by which an operating system decides which process (or thread) gets to use the CPU at any given time. The objective is to make efficient use of CPU resources and ensure fairness between processes.

The components:
- scheduler: component of the operating system responsible for selecting which process should run next
- ready queue: list of processes that are ready and waiting for CPU time. These processes are in the ready state
- CPU burst: time a process spends using the CPU before either being interrupted or completing its task

Scheduling can either be preemptive (the OS interrupts a running process to give CPU time to another process) or non preemptive (the process runs until it voluntarily gives up control).

### Process Creation

The procedure where the operating system creates a new process.

Can happen through:
- raw fork
- fork and exec
- clone (different to fork)