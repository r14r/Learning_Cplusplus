# Learning C++

This repository contains a beginner-friendly walkthrough of the most common C++
language features. It is organised as a single executable that prints concise
examples of core syntax, the standard library and modern programming patterns.

## Project layout

```
.
├── CMakeLists.txt        # Build configuration
├── include/              # Shared headers
├── src/                  # Demonstration code grouped by topic
└── README.md             # This guide
```

## Prerequisites

- A C++20-compatible compiler (GCC 10+, Clang 10+, MSVC 2019+)
- [CMake](https://cmake.org) 3.16 or newer

## Building

```bash
cmake -S . -B build
cmake --build build
```

## Running the demo

```bash
./build/learning_cpp
```

You will see output organised into three sections:

1. **Language basics** – variables, containers, algorithms and lambdas.
2. **Object-oriented programming** – classes, inheritance and polymorphism.
3. **Modern C++ features** – templates, smart pointers, exceptions, concurrency
   and file system utilities.

Each example prints a short description and the result so you can follow along
while reading the source code in the `src/` directory.
