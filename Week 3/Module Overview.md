# Week 3 Module Overview

## What is multicore programming

Multicore programming refers to writing software that can run on multiple CPU cores simultaneously to improve performance and efficiency. In a single-threaded process, only one thread of execution runs at a time, while a multithreaded process allows multiple threads to run concurrently within the same program. Multithreading also requires proper synchronization to avoid conflicts when threads share data.

## What is the difference between single and multithread processes?

A single-threaded process has only one thread of execution, meaning it performs one task at a time, while a multithreaded process contains multiple threads that can run concurrently within the same program. Multithreaded processes share the same memory space and resources, which allows better performance and responsiveness, especially on multicore systems. However, sharing resources also increases the need for synchronization to avoid conflicts. Single-threaded processes are simpler but may be slower when handling multiple tasks.

## What is a critical section?

A critical section in an operating system is a part of the program where shared data or resources are accessed. Only one thread or process should execute the critical section at a time to prevent race conditions and inconsistent results. If multiple threads enter this section simultaneously, it can cause errors or unpredictable behavior. Synchronization tools like mutexes and semaphores are used to protect the critical section.

## How to run the Pthreads function?

To run a Pthreads function, you first include the pthread library and create a thread using the pthread_create() function. This function requires a thread identifier, thread attributes, the function to execute, and its arguments. After creating threads, you typically use pthread_join() to wait for them to finish execution. Finally, you compile the program with the -pthread flag to link the pthread library properly.
