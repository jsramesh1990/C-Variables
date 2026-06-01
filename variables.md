# Variables (C Programming / Embedded Systems)

## Table of Contents

1. [Introduction](#introduction)
2. [What is a Variable?](#what-is-a-variable)
3. [Why Do We Use Variables?](#why-do-we-use-variables)
4. [How Variables Work in Memory](#how-variables-work-in-memory)
5. [Types of Variables](#types-of-variables)
6. [Local Variables](#local-variables)
7. [Global Variables](#global-variables)
8. [Static Variables](#static-variables)
9. [External Variables (extern)](#external-variables-extern)
10. [Register Variables](#register-variables)
11. [Scope of Variables](#scope-of-variables)
12. [Lifetime of Variables](#lifetime-of-variables)
13. [Storage Classes vs Variables](#storage-classes-vs-variables)
14. [Real-Time Embedded Examples](#real-time-embedded-examples)
15. [Advantages and Disadvantages](#advantages-and-disadvantages)
16. [Interview Questions](#interview-questions)
17. [Conclusion](#conclusion)

---

# Introduction

Variables are the **basic building blocks of any programming language**.

In embedded systems, variables are used to:

* Store sensor data
* Control hardware states
* Maintain system status
* Communicate between modules

---

# What is a Variable?

### Definition

> A variable is a named memory location used to store data that can change during program execution.

---

## Example

```c
int temperature = 25;
```

Here:

* `temperature` → variable name
* `int` → data type
* `25` → value stored in memory

---

## Interview Answer

A variable is a named memory location used to store data that can be modified during program execution.

---

# Why Do We Use Variables?

Without variables:

```text
Hard-coded values → No flexibility
```

With variables:

```text
Dynamic data storage → Flexible programs
```

---

## Example

```c
int speed = 60;
```

Speed can change during runtime.

---

# How Variables Work in Memory

## Example

```c
int x = 10;
```

---

## Memory Representation

```text
RAM
----------------
| x = 10       |
----------------
```

---

## Execution Flow

```text
Program Starts
     ↓
Memory Allocated
     ↓
Value Stored (10)
     ↓
Used in Computation
     ↓
Program Ends (or destroyed if local)
```

---

# Types of Variables

```text
Variables
│
├── Local Variable
├── Global Variable
├── Static Variable
├── External Variable
└── Register Variable
```

---

# Local Variables

## Definition

Declared inside a function or block.

---

## Example

```c
void func()
{
    int a = 10;  // local variable
}
```

---

## Characteristics

| Property      | Value              |
| ------------- | ------------------ |
| Scope         | Inside function    |
| Lifetime      | Function execution |
| Memory        | Stack              |
| Default Value | Garbage            |

---

## Interview Answer

Local variables exist only inside a function and are destroyed after function execution.

---

# Global Variables

## Definition

Declared outside all functions.

---

## Example

```c
int speed = 100;

void display()
{
    printf("%d", speed);
}
```

---

## Characteristics

| Property      | Value             |
| ------------- | ----------------- |
| Scope         | Entire program    |
| Lifetime      | Program execution |
| Memory        | Data segment      |
| Default Value | 0                 |

---

## Interview Answer

Global variables are accessible throughout the program and exist until the program terminates.

---

# Static Variables

## Definition

Retains value between function calls.

---

## Example

```c
void counter()
{
    static int count = 0;
    count++;
    printf("%d\n", count);
}
```

---

## Output

```text
1
2
3
```

---

## Key Behavior

```text
Initialized once
Value preserved
```

---

## Interview Answer

Static variables retain their value throughout program execution but have limited scope.

---

# External Variables (extern)

## Definition

Used to access variables from another file.

---

## Example

### File1.c

```c
int speed = 100;
```

### File2.c

```c
extern int speed;
```

---

## Characteristics

| Property | Value          |
| -------- | -------------- |
| Scope    | Multiple files |
| Lifetime | Full program   |
| Memory   | Data segment   |

---

## Interview Answer

Extern variables allow sharing global variables across multiple source files.

---

# Register Variables

## Definition

Suggests storing variable in CPU register.

---

## Example

```c
register int i;
```

---

## Key Point

* Faster access
* Address cannot be taken

---

## Interview Answer

Register variables are stored in CPU registers for faster access, if available.

---

# Scope of Variables

## Definition

Scope defines where a variable can be accessed.

---

## Types

### Local Scope

Inside function

### Global Scope

Entire program

### Block Scope

Inside `{ }`

---

## Example

```c
if(1)
{
    int x = 10; // block scope
}
```

---

# Lifetime of Variables

| Type     | Lifetime           |
| -------- | ------------------ |
| Local    | Function execution |
| Global   | Program execution  |
| Static   | Program execution  |
| Register | Function execution |

---

# Storage Classes vs Variables

| Feature  | Variable    | Storage Class        |
| -------- | ----------- | -------------------- |
| Meaning  | Data holder | Behavior of variable |
| Controls | Value       | Scope + Lifetime     |
| Examples | int x       | static, auto, extern |

---

# Real-Time Embedded Examples

## 1. Sensor Data

```c
int temperature = read_sensor();
```

---

## 2. Motor Control

```c
int speed = 120;
```

---

## 3. Interrupt Counter

```c
static int irq_count;
```

---

## 4. Shared System Data

```c
extern int system_status;
```

---

# Advantages

✔ Easy data storage

✔ Improves program readability

✔ Enables hardware control

✔ Supports modular programming

---

# Disadvantages

✘ Improper use causes bugs

✘ Global variables reduce safety

✘ Memory misuse possible

✘ Hard debugging in large systems

---

# Interview Questions

### What is a Variable?

A variable is a named memory location used to store data that can change during program execution.

---

### What are Types of Variables?

* Local
* Global
* Static
* External
* Register

---

### Difference Between Local and Global Variables?

| Local           | Global           |
| --------------- | ---------------- |
| Inside function | Outside function |
| Temporary       | Permanent        |
| Stack           | Data segment     |

---

### What is a Static Variable?

A variable that retains its value between function calls.

---

### What is the use of extern?

To access variables defined in another file.

---

### Where are variables stored in memory?

* Stack → Local
* Data segment → Global/static
* Register → CPU registers (if used)

---

# Most Asked Interview Question

### Explain Variables in C.

Variables are named memory locations used to store data that can change during program execution. They are classified into local, global, static, extern, and register variables. Each type differs in scope, lifetime, and memory location. Variables are essential in embedded systems for handling sensor data, controlling hardware, and managing system states.

---

# Quick Revision

```text
Variable = Memory Location + Name + Value

Types:
Local → Temporary
Global → Whole Program
Static → Persistent
Extern → Shared Across Files
Register → Fast Access
```

---

# Conclusion

Variables are the foundation of programming and embedded systems. They represent memory locations used to store and manipulate data. Understanding variable types, scope, lifetime, and storage classes is essential for writing efficient, reliable, and optimized embedded firmware, especially in real-time and automotive systems.


