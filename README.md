# Data Structures and Algorithms in C++

This repository contains implementations of various data structures and algorithms in C++. Each data structure is organized into its own folder within the `src` directory.

## Directory Structure

```
data-structures-algorithms-cpp
├── src
│   ├── arrays
│   │   └── arrays.cpp          # Implementation of array operations
│   ├── linked_lists
│   │   └── linked_lists.cpp    # Implementation of singly linked list
│   ├── stacks
│   │   └── stacks.cpp          # Implementation of stack data structure
│   ├── queues
│   │   └── queues.cpp          # Implementation of queue data structure
│   ├── trees
│   │   └── trees.cpp           # Implementation of binary trees
│   ├── graphs
│   │   └── graphs.cpp          # Implementation of graph data structures
│   └── sorting
│       └── sorting.cpp         # Implementation of sorting algorithms
├── CMakeLists.txt              # CMake configuration file
└── README.md                   # Project documentation
```

## Overview

This project provides a comprehensive collection of data structures and algorithms implemented in C++. The following data structures are included:

- **Arrays**: Functions for insertion, deletion, and searching.
- **Linked Lists**: A singly linked list with methods for insertion, deletion, and traversal.
- **Stacks**: A stack implementation with methods for push, pop, and checking if empty.
- **Queues**: A queue implementation with methods for enqueue, dequeue, and checking if empty.
- **Trees**: Binary tree implementation with insertion, deletion, and traversal methods.
- **Graphs**: Graph implementation using adjacency lists and matrices, with search methods.
- **Sorting**: Various sorting algorithms including bubble sort, selection sort, and quicksort.

## Usage

To build the project, navigate to the project directory and run:

```
mkdir build
cd build
cmake ..
make
```

After building, you can run the individual implementations as needed.

## Examples

Refer to the respective source files for usage examples and function descriptions. Each implementation contains comments and examples to help you understand how to use the data structures and algorithms effectively.