# Programming Labs in C++
Study at university (autumn-winter 2023)

Welcome to the repository of programming labs in C++. This repository contains solutions to tasks that will help you master the basics and advanced concepts of programming in C++, including working with algorithms, data structures, graphical interfaces, and object-oriented programming.

## Table of contents

### Lab work 1
1. **Task 1** Generating a random mumber
2. **Task 2** Building a histogram of random numbers
3. **Task 3** Generating random numbers in different ranges
4. **Task 4** Dice game

### Lab work 2
1. **Task 1** Developing array sorting algorithms
2. **Task 2** Checking sorting correctness
3. **Task 3** Comparing quick sort and bucket sort algorithms

### Lab work 3
1. **Task 1** Quick sort with and without recursion
2. **Task 2** Quick sort with and without recursion, with n=50
3. **Task 3** Comparing two quick sort methods with different array sizes

### Lab work 4
1. **Task 1.1** Implementing Dijkstra's algorithm for finding shortest paths in a graph. Used for analyzing and comparing the algorithm's runtime with another method.

    **Task 1.2** Implementing Floyd's algorithm for finding shortest paths between all pairs of vertices in a graph.
2. **Task 2** Determining the minimum cost of travel between cities using Floyd's algorithm.
3. **Task 3** Finding the shortest path in a randomly generated lake
4. **Task 4** Generating a 100-character string with characters "A", "B", and "C", ensuring no two identical adjacent substrings
5. **Task 5** Finding the shortest path in a randomly generated maze

### Lab work 5
1. **Task 1** Implementing a binary tree and finding the closest value below a given number
2. **Task 2** Implementing a B+ tree with n = 14 nodes and degree m = 5. building and finding values based on proximity below
3. **Task 3** Implementing Kruskal's algorithm for finding a minimum spanning tree in a graph
4. **Task 4** Implementing Prim's algorithm for finding a minimum spanning tree in a graph

### Lab work 6
Implementing and demonstrating the principles of encapsulation and polymorphism using classes `TransportVehicle`, `Car`, `Train`, and `Express`.

Demonstrates encapsulation by restricting access to class data and methods, and shows polymorphism through the use of base class pointers to call overridden methods in derived classes. In `main()`, objects of different classes are created and methods are called through base class pointers, showing how different types of objects can be used through a unified interface.

### Lab work 7
Developing a graphical interface using GDI in the windows API. The project includes classes `House`, `Lake`, `Tree`, and `Surname` for displaying graphical objects such as houses, lakes, and trees. The interface allows selecting actions to display various scenes and clear the screen. The program demonstrates working with the Windows API to draw graphical elements on the screen.

### Lab work 8
**Project**: Implementing basic classes and polymorphism using inheritance and abstract classes.
**Classes**:
   - **Transport**: Abstract base class representing a transport vehicle with virtual functions for movement and getting speed and capacity.
   - **Car**: Derived class from `Transport`, representing a car with a model and implementation of the `move()` method.
   - **PassengerCar**: Derived class from `Car`, representing a passenger car with additional destination information.
   - **Truck**: Derived class from `Transport`, representing a truck with cargo type information and implementation of the `move()` method.

### Lab work 10
**Project**: Determining the maximum sum of squares of two array elements satisfying a specific condition.
**Program**:
   - Asks for the number of array elements.
   - Generates an array of random numbers.
   - Calculates the maximum sum of squares of two elements that meet the condition.
   - Measures and displays the execution time.

### Lab work 10 (more efficient)
**Project**: Optimizing the calculation of the maximum sum of squares of two array elements.
- Improved performance by using two maximum values, significantly reducing execution time compared to the previous implementation.
- The program now uses a static array to simplify code and reduce memory usage.

## How to use

1. **Clone the repository**:
    ```bash
    git clone https://github.com/account_username/repository_name.git
    ```

2. **Navigate to the project directory**:
    ```bash
    cd repository_name
    ```

3. **Run the program**:

    Labs requiring Visual Studio:

    - **lab7.cpp**
    - **lab10.cpp**
    - **lab10_more_eff.cpp**

    These labs are recommended to be run and debugged in **Visual Studio** for convenient use of debugging and build features.

    Other labs were written using **Visual Studio Code**. 

4. **Follow the console instructions for input and results**


## Notes

- Make sure all dependencies and libraries are installed before compiling the programs.
- The program may require additional input data, which should be provided in the console when prompted.
