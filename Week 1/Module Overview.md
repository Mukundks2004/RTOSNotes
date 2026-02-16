# Week 1 Module Overview

## What are the operating system services?

## What is the standard C library, API system call on OS?

## What are the following processes: fork, wait, kill and exit processes?

Fork: The fork() system call creates a new, independent process (child) by duplicating the existing one (parent). The child is an exact copy, inheriting memory, file descriptors, and code, but has a unique process ID (PID). After forking, both processes execute concurrently from the same point, with the call returning 0 to the child and the child's PID to the parent.

The child does not inherit memory locks.

Question: I understand that fork is a function and it returns a result to the parent but how does it return anything to the child?

Answer: Because it is the same code running, the fork happens "twice" you can imagine it as a timeline where the code runs as one process up to that point and two from them on.

Question: What are memory locks?

Answer: TODO

Wait: the wait sys call suspends execution until one or all child processes change state (e.g., terminate or stop). This allows the parent to obtain information about the child's exit status and permits the operating system to release the child's resources, preventing "zombie" processes.

If given a pid or job ID, it waits for that specific process.

If no pid is provided, it waits for all currently active background child processes known to the shell to terminate.

Kill: The kill process in unix refers to the CL util used to send a signal to a running process, generally to terminate it. The command's primary function is process management, allowing admins and users to gracefully shut down unresponsive programs or forcefully terminate rogue ones.

A user can only kill their own processes. Terminating processes owned by other users or system processes requires superuser (root) privileges.

Exit: The command causes the shell or program to terminate. If performed within an interactive command shell, the user is logged out of their current session, and/or user's current console or terminal connection is disconnected.

## What does POSIX mean?

POSIX is an OS standard to ensure compatibility between unix like operating systems (such as Linux, macOS, and BSD). It defines standard API, shell, and CLIs, allowing software developed on one system to be easily ported and run on another.