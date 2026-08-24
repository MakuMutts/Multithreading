# C++ Concurrency in Action — Practice

This repository contains my practical exercises while studying **C++ multithreading** with the book **"C++ Concurrency in Action" by Anthony Williams**.

I am studying the topic independently and using this repository to practice the concepts from each chapter.

## 📚 Chapters

### Chapter 2 — Managing Threads

Topics:

* `std::thread`
* `join()`
* `detach()`
* Passing arguments to threads
* Thread ownership
* `std::move()`
* Thread IDs
* Running multiple threads

Practice:

* [x] Creating a thread
* [x] Passing arguments to a thread
* [x] Working with strings in threads
* [x] `join()` and `detach()`
* [x] Passing thread ownership
* [x] Working with several threads
* [x] Calculating a sum using multiple threads
* [ ] Parallel file processing

---

### Chapter 3 — Sharing Data Between Threads

Topics:

* Shared data
* Race conditions
* Data races
* `std::mutex`
* `std::lock_guard`
* `std::unique_lock`
* Deadlocks

Practice:

* [ ] Shared counter
* [ ] Creating a data race
* [ ] Fixing a data race with `mutex`
* [ ] Thread-safe class
* [ ] Deadlock example
* [ ] Fixing a deadlock

---

### Chapter 4 — Synchronizing Threads

Topics:

* `std::condition_variable`
* Producer/Consumer
* `std::future`
* `std::promise`
* `std::async`

Practice:

* [ ] Producer/Consumer
* [ ] Thread-safe queue
* [ ] Waiting for a task
* [ ] Using `future`
* [ ] Using `promise`
* [ ] Using `async`

---

### Chapter 5 — Memory Model and Atomic Operations

Topics:

* C++ memory model
* `std::atomic`
* Memory ordering
* Acquire/Release
* Happens-before

Practice:

* [ ] Atomic counter
* [ ] Compare atomic and mutex
* [ ] Atomic flag
* [ ] Memory ordering experiments

---

### Chapter 6 — Lock-Free Programming

Topics:

* Atomic operations
* Compare-and-exchange
* Lock-free data structures
* Lock-free stack

Practice:

* [ ] `compare_exchange`
* [ ] Lock-free counter
* [ ] Lock-free stack
* [ ] Test with multiple threads

---

### Chapter 7 — Designing Concurrent Code

Topics:

* Designing multithreaded programs
* Parallel algorithms
* Dividing work between threads
* Performance

Practice:

* [ ] Parallel search
* [ ] Parallel data processing
* [ ] Compare different numbers of threads
* [ ] Measure performance

---

## 🎯 Goal

My goal is to understand how multithreading works in modern C++ and learn how to apply it in practice.

I use this repository to:

* practice after reading each topic;
* experiment with different approaches;
* make mistakes and understand them;
* track my progress.

**Currently studying:** Chapter 2 — Managing Threads.
