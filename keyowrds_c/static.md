# `static` Keyword in C 

## Overview

The `static` keyword in C controls:
- Variable lifetime
- Variable visibility (scope)
- Function visibility (linkage)

It is heavily used in **Embedded Linux, kernel code, and drivers** to manage memory and avoid symbol conflicts.

---

# 1. Types of `static`

There are **3 major uses**:

1. Static local variable
2. Static global variable (file scope)
3. Static function (internal linkage)

---

# 2. Static Local Variable

## Definition

A variable inside a function that:
- Retains its value between function calls
- Is initialized only once

---

## Example

```c
#include <stdio.h>

void counter() {
    static int count = 0;
    count++;
    printf("Count = %d\n", count);
}

int main() {
    counter();
    counter();
    counter();
}
``` id="st1"

---

## Output
````

Count = 1
Count = 2
Count = 3

````

---

## Key Point

- Stored in **data segment (not stack)**
- Lifetime = entire program execution

---

# 3. Static Global Variable (File Scope)

## Definition

A global variable restricted to a single file.

---

## Example

```c
static int shared_value = 10;
``` id="st2"

---

## Behavior

- Accessible only inside same `.c` file
- Not visible to other files during linking

---

## Why use it?

- Encapsulation
- Prevent external modification
- Avoid naming conflicts

---

# 4. Static Function (Internal Linkage)

## Definition

A function accessible only within the same file.

---

## Example

```c
static void helper_function() {
    printf("Internal helper\n");
}
``` id="st3"

---

## Usage

```c
int main() {
    helper_function();
}
````

---

## Restriction

* Cannot be called from other `.c` files

---

# 5. Linkage Concept

## Without static

````
Function is globally visible across files
``` id="lk1"

## With static

````

Function visible only inside same file

````id="lk2"

---

# 6. Memory Behavior of Static

| Type | Storage Area |
|------|--------------|
| static variable | Data segment |
| local variable | Stack |
| global variable | Data segment |

---

# 7. Static vs Global Variable

| Feature | static global | normal global |
|--------|--------------|--------------|
| Scope | File only | Whole program |
| Visibility | Hidden | Visible |
| Linkage | Internal | External |

---

# 8. Static vs Automatic Variable

| Feature | static | auto (normal local) |
|--------|--------|---------------------|
| Lifetime | Entire program | Function scope |
| Storage | Data segment | Stack |
| Retains value | Yes | No |

---

# 9. Static in Embedded Systems

## Common Uses

- Driver private variables
- Hardware state tracking
- File-level encapsulation
- Interrupt counters
- Cache variables

---

## Example (Embedded Driver)

```c
static int irq_count = 0;

void irq_handler() {
    irq_count++;
}
``` id="st4"

---

# 10. Static in Kernel Code

Kernel uses static heavily:

## Example

```c
static int device_initialized = 0;
``` id="st5"

---

## Why?

- Prevent symbol export
- Reduce global namespace pollution
- Improve modularity

---

# 11. Static Functions in Kernel

```c
static void init_device(void)
{
    // internal setup
}
``` id="st6"

---

## Benefit

- Not visible outside file
- Safer modular design
- Better optimization

---

# 12. Static vs Inline vs Macro

| Feature | static | inline | macro |
|--------|--------|--------|-------|
| Type safety | Yes | Yes | No |
| Debuggable | Yes | Yes | No |
| Scope control | Yes | Yes | No |
| Performance | Normal | Fast | Fast |

---

# 13. Common Mistakes

## 13.1 Forgetting static for helper functions

❌ Bad:
```c
void helper() {}
````

✔ Better:

```c
static void helper() {}
```

---

## 13.2 Using static when sharing is needed

* Leads to linker errors if used across files

---

# 14. Static in Multi-file Projects

## file1.c

```c
static int value = 10;
```

## file2.c

```
Cannot access value → linker error
```

---

# 15. Debugging Static Variables

Static variables:

* Do NOT appear on stack traces
* Persist across calls

Use debugger:

```
gdb → print variable
```

---

# 16. Summary

* `static` controls lifetime and visibility
* Local static → persistent variable
* Global static → file-private variable
* Static function → internal linkage
* Widely used in embedded and kernel development

---


