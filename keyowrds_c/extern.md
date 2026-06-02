# `extern` Keyword in C 

## Overview

The `extern` keyword is used to **declare a variable or function that is defined in another file**.

It tells the compiler:

> “This symbol exists somewhere else — just trust me.”

It is essential for **multi-file C programs, embedded systems, and Linux kernel development**.

---

# 1. Why `extern` is Needed

In multi-file projects:

- One file defines a variable
- Other files use it

Without `extern`, the linker will throw errors.

---

# 2. Basic Concept

## Declaration vs Definition

| Type | Meaning |
|------|--------|
| Declaration | Tells compiler variable exists |
| Definition | Allocates memory |

---

# 3. Simple Example

## file1.c (Definition)

```c
int global_value = 10;
``` id="ex1"

---

## file2.c (Declaration using extern)

```c
extern int global_value;

void print_value() {
    printf("%d\n", global_value);
}
``` id="ex2"

---

## Output

````

10

```id="out1"

---

# 4. How extern Works

```

file1.c → defines variable in memory
file2.c → accesses same memory using extern

````id="flow1"

---

# 5. extern for Functions

Functions are **extern by default** in C.

## Example

```c
extern void test_function();
````

But this is equivalent to:

````c
void test_function();
``` id="fn1"

---

# 6. extern with Global Variables

## file_a.c
```c
int count = 5;
``` id="g1"

---

## file_b.c
```c
extern int count;

void update() {
    count++;
}
``` id="g2"

---

# 7. extern vs static

| Feature | extern | static |
|--------|--------|--------|
| Visibility | Global (multi-file) | File only |
| Memory | Shared | Private |
| Linkage | External | Internal |

---

# 8. Linker Behavior

## Without extern

````

Undefined reference error

```id="err1"

---

## With extern

```

Linker connects symbol across files

````id="lk1"

---

# 9. extern in Embedded Systems

Used for:

- Sharing hardware registers
- Global system state
- Driver communication
- RTOS shared variables

---

## Example (Embedded Driver)

## gpio.h
```c
extern int gpio_status;
``` id="emb1"

---

## gpio.c
```c
int gpio_status = 0;
``` id="emb2"

---

## main.c
```c
#include "gpio.h"

void app() {
    gpio_status = 1;
}
``` id="emb3"

---

# 10. extern with Header Files

## Best Practice

### header file (.h)

```c
#ifndef GPIO_H
#define GPIO_H

extern int gpio_status;

#endif
``` id="hdr1"

---

### source file (.c)

```c
int gpio_status = 0;
``` id="src1"

---

# 11. Common Mistakes

## 11.1 Missing definition

```c
extern int x;
````

❌ Error:

```
undefined reference to x
```

---

## 11.2 Multiple definitions

````c
int x = 10;
int x = 20;
``` id="err2"

❌ Causes linker error

---

## Fix:
Use extern in headers, definition in one file only.

---

# 12. extern in Memory Terms

| Type | Storage |
|------|--------|
| extern variable | External data segment |
| static variable | Private data segment |
| local variable | Stack |

---

# 13. extern and Compilation Flow

````

file1.c → object1.o (defines symbol)
file2.c → object2.o (uses extern symbol)

Linker:
object1.o + object2.o → executable

````id="flow2"

---

# 14. extern with Functions (Linkage)

Functions are:

- Extern by default
- Globally visible unless static

---

## Example

```c
void foo(); // implicitly extern
``` id="fn2"

---

# 15. Embedded Linux Use Cases

- Sharing driver state across files
- Kernel subsystem communication
- Global configuration variables
- Hardware abstraction layers

---

## Example (Driver)

```c
extern struct device_state dev_state;
``` id="emb4"

---

# 16. extern vs static vs global

| Type | Scope | Visibility | Linkage |
|------|------|------------|---------|
| extern | global | multiple files | external |
| static | file only | private | internal |
| global (no keyword) | global | multiple files | external |

---

# 17. Debugging extern Issues

## Problem: undefined reference

### Cause:
- Missing definition file in build

### Fix:
- Ensure all `.c` files are compiled and linked

````

gcc file1.c file2.c -o app

```id="dbg1"

---

# 18. Summary

- `extern` declares variables defined elsewhere
- Enables cross-file sharing
- Essential for multi-file embedded projects
- Works with linker, not compiler
- Must be used carefully to avoid conflicts

---

