# Week 3 Module Overview

## What is multicore programming

Multicore programming refers to writing software that can run on multiple CPU cores simultaneously to improve performance and efficiency. In a single-threaded process, only one thread of execution runs at a time, while a multithreaded process allows multiple threads to run concurrently within the same program. Multithreading also requires proper synchronization to avoid conflicts when threads share data.

## What is the difference between single and multithread processes?

A single-threaded process has only one thread of execution, meaning it performs one task at a time, while a multithreaded process contains multiple threads that can run concurrently within the same program. Multithreaded processes share the same memory space and resources, which allows better performance and responsiveness, especially on multicore systems. However, sharing resources also increases the need for synchronization to avoid conflicts. Single-threaded processes are simpler but may be slower when handling multiple tasks.

## What is a critical section?

A critical section in an operating system is a part of the program where shared data or resources are accessed. Only one thread or process should execute the critical section at a time to prevent race conditions and inconsistent results. If multiple threads enter this section simultaneously, it can cause errors or unpredictable behavior. Synchronization tools like mutexes and semaphores are used to protect the critical section.

## How to run the Pthreads function?

To run a Pthreads function, you first include the pthread library and create a thread using the pthread_create() function. This function requires a thread identifier, thread attributes, the function to execute, and its arguments. After creating threads, you typically use pthread_join() to wait for them to finish execution. Finally, you compile the program with the -pthread flag to link the pthread library properly.

## What is critical race section?

A critical (race) section is a part of a program where multiple threads or processes access shared data at the same time, which can lead to a race condition. A race condition happens when the final result depends on the order of execution of threads, causing unpredictable or incorrect outcomes. To prevent this, only one thread should be allowed to execute the critical section at a time. Synchronization mechanisms are used to ensure safe access to shared resources.

## What is the Too Much Milk problem?

Yes, I understand the “Too Much Milk Program,” which is a classic example used to explain race conditions and synchronization problems. In this example, two processes check if there is no milk and both decide to buy milk at the same time, resulting in buying too much milk. It demonstrates how lack of proper synchronization can cause incorrect behavior. The example is often used to introduce solutions like locks or other synchronization tools.

The solution to the problem is simply to put a post it note on the board representing a lock, and if you see the post it note then don't buy milk.

## What is a mutex vs semaphore?

Sort of like the rubber chicken, the only person who holds it can talk.

A mutex is a mutual exclusion lock that allows only one thread to access a critical section at a time, and it must be unlocked by the same thread that locked it.

A semaphore handles counting.

A semaphore is a signaling mechanism that can allow multiple threads to access a resource depending on its count value. The main difference is that a mutex is strictly for mutual exclusion with ownership, while a semaphore can manage multiple resource instances without strict ownership.

## What is Deadlock?

Deadlock is a situation where two or more processes are waiting for each other to release resources, causing all of them to stop executing indefinitely.
