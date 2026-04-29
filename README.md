# Cpp_Programming_Journey 🏎️

This repository tracks my progress in C++ and software engineering, focusing on mathematical modeling and performance-oriented code.

## 🧮 Scientific Calculus Engine (`calculus_engine.cpp`)

A command-line tool built to perform numerical analysis on functions (currently x^2). This project bridges my studies in **Calculus** and **Software Engineering** at Ankara University.

### 🛠 Features
* **Numerical Integration**: Implemented using **Riemann Sums** with high sensitivity (10^7 steps).
* **Numerical Differentiation**: Calculates the instantaneous rate of change using the limit definition: [f(x+h) - f(x)] / h.
* **Limit Approximation**: Evaluates function continuity by approaching a point from both the left and right sides.

### 🔧 Technical Details
* **Language**: C++
* **Precision**: Uses `double` for high-accuracy floating-point calculations.
* **Robustness**: Includes `cin.fail()` handling to prevent crashes during invalid user input.

---

## 🔧 Polymorphic Car Diagnostics (`polymorphic_car_diagnostics.cpp`)

A diagnostic system designed to simulate pre-race hardware checks for an F1 car (RB20). This project demonstrates advanced memory management by testing different hardware components through a single unified interface.

### 🛠 Features
* **Automated Testing Loop**: Iterates through an array of vehicle components to run specific diagnostic checks (Engine RPM, Gearbox synchronizers).
* **Polymorphic Arrays**: Utilizes an array of base class pointers (`CarPart* components[]`) to store and manage dynamically allocated derived objects (`engine`, `gearBox`).
* **Strict Memory Safety**: Implements precise deletion sequences to completely eliminate memory leaks.

### 🔧 Technical Details
* **Concepts Used**: Polymorphism, Inheritance, Initializer Lists.
* **Modern C++ Practices**: Leverages `virtual` destructors and the `override` keyword to ensure safe and predictable derived class behavior.
* **Memory Allocation**: 100% Heap-based architecture using `new` and `delete`.

---

## 📡 Dynamic Sensor Board (`dynamic_sensor_board.cpp`)

An interactive telemetry dashboard simulating pit-wall data collection. It dynamically swaps and manages different types of car sensors based on real-time user input.

### 🛠 Features
* **Runtime Object Assignment**: Instantiates different sensor types (Temperature, Pressure) on the fly based on user selection.
* **Manager Class Architecture**: Employs a `telemetryBoard` class that acts as a wrapper, containing an `activeSensor` pointer to bridge the dashboard with the hardware.
* **Segfault Prevention**: Carefully allocates memory for both the container object and the nested pointer, ensuring safe memory access.

### 🔧 Technical Details
* **Dynamic Binding**: Uses `virtual` functions to resolve the correct `readData()` method at runtime.
* **Pointer Nesting**: Demonstrates safe chaining and dereferencing (`->`) from a manager object to a dynamically allocated component.
* **Cleanup Hierarchy**: Cascading memory deallocation (deleting the inner sensor before the outer board).

## 📻 F1 Radio Log System (`f1_radio_linked_list.cpp`)

A dynamic data structure implementation designed to store and manage F1 driver radio messages. This project is built from scratch to demonstrate the fundamental principles of linked lists without relying on standard C++ libraries like `<vector>` or `<list>`.

### 🛠 Features
* **Dynamic Sizing**: Implements a singly linked list to add new messages dynamically, eliminating the constraints of fixed-size arrays.
* **Node Traversal**: Uses pointer iteration to navigate through the linked nodes and display chronological radio logs.
* **Safe Memory Deallocation**: Features a custom memory cleanup algorithm that safely disconnects and deletes each node step-by-step, ensuring zero memory leaks upon program termination.

### 🔧 Technical Details
* **Data Structure**: Singly Linked List (Node-based architecture).
* **Memory Management**: Manual allocation using `new` and systematic deallocation using `delete`.
* **Pointers**: Utilizes struct/class pointers for node linking and data retrieval.

---
*Future goal: Adapting these algorithms and OOP structures for real-time F1 telemetry and simulation data.* 🏁