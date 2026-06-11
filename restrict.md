# `restrict` Keyword in C

## Table of Contents

1. What is `restrict`?
2. Why Do We Need It?
3. Syntax
4. How `restrict` Works
5. Without `restrict`
6. With `restrict`
7. What Happens When Code Hits It?
8. Compiler Optimization
9. Real-Time Embedded Examples
10. Rules of `restrict`
11. Advantages and Disadvantages
12. `restrict` vs `const`
13. `restrict` vs Pointer
14. Interview Questions
15. Quick Revision
16. Interview Answer (2 Minutes)

---

# What is `restrict`?

## Definition

`restrict` is a C keyword (introduced in **C99**) that tells the compiler:

> "For the lifetime of this pointer, only this pointer will be used to access the object it points to."

---

Syntax:

```c
int *restrict ptr;
```

Meaning:

```text
ptr is the only pointer
used to access that memory.
```

This allows the compiler to generate faster code.

---

# Why Do We Need It?

Compilers are conservative.

Consider:

```c
void add(int *a, int *b)
{
    *a = *a + *b;
}
```

Compiler does not know:

```text
Can a and b point
to the same memory?
```

Example:

```c
add(&x, &x);
```

Possible.

So compiler must be careful.

This limits optimization.

---

# Syntax

```c
type *restrict pointer_name;
```

Example:

```c
int *restrict p;
```

or

```c
void copy(
    int *restrict dst,
    int *restrict src
);
```

---

# How `restrict` Works

Example:

```c
void copy(
    int *restrict dst,
    int *restrict src,
    int n)
{
    for(int i=0;i<n;i++)
    {
        dst[i] = src[i];
    }
}
```

Compiler assumes:

```text
dst and src
never overlap
```

Therefore:

```text
Aggressive Optimization Allowed
```

---

# Without `restrict`

```c
void add(
    int *a,
    int *b)
{
    *a += *b;
}
```

Compiler assumes:

```text
a and b
might point
to same memory
```

Example:

```c
int x = 10;

add(&x, &x);
```

Valid.

Because aliasing is possible:

```text
Optimization Limited
```

---

# With `restrict`

```c
void add(
    int *restrict a,
    int *restrict b)
{
    *a += *b;
}
```

Compiler assumes:

```text
a and b
never refer
to same object
```

Now:

```text
Better Optimization
```

possible.

---

# What Happens When Code Hits It?

Example:

```c
void sum(
    int *restrict a,
    int *restrict b,
    int *restrict c)
{
    *a = *b + *c;
}
```

Call:

```c
sum(&x,&y,&z);
```

---

### Compiler View

Without `restrict`:

```text
Could a == b ?
Could a == c ?
Could b == c ?
```

Need extra checks.

---

With `restrict`:

```text
a != b
a != c
b != c
```

Compiler assumes no overlap.

---

### Generated Code

Compiler can:

```text
Keep Values In Registers
Reduce Memory Reads
Vectorize Loops
Reorder Instructions
```

---

### Interview Answer

**What happens when code hits a `restrict` pointer?**

The compiler assumes that the memory referenced through that pointer is not accessed through any other pointer during its lifetime. This eliminates aliasing concerns and allows more aggressive optimizations such as register caching, instruction reordering, and loop vectorization.

---

# Compiler Optimization Example

Without `restrict`

```c
void func(int *a, int *b)
{
    *a = 10;
    *b = 20;

    printf("%d", *a);
}
```

Compiler must reload:

```c
*a
```

because:

```text
b may point to same memory
```

---

With `restrict`

```c
void func(
    int *restrict a,
    int *restrict b)
{
    *a = 10;
    *b = 20;

    printf("%d", *a);
}
```

Compiler knows:

```text
a and b different
```

Can keep:

```c
*a
```

in a register.

Faster.

---

# Real-Time Embedded Examples

## Example 1: DMA Buffer Copy

```c
void dma_copy(
    uint8_t *restrict dst,
    uint8_t *restrict src,
    uint32_t len)
{
    for(uint32_t i=0;i<len;i++)
    {
        dst[i] = src[i];
    }
}
```

Compiler may generate highly optimized copy code.

---

## Example 2: DSP Algorithms

```c
void fir_filter(
    float *restrict output,
    float *restrict input,
    float *restrict coeffs
);
```

Used in:

```text
Audio Processing
Radar
Signal Processing
```

---

## Example 3: Image Processing

```c
void grayscale(
    uint8_t *restrict out,
    uint8_t *restrict in
);
```

Vectorization possible.

---

## Example 4: Automotive ECU

```c
void process_can(
    uint8_t *restrict tx,
    uint8_t *restrict rx
);
```

Compiler can optimize buffer handling.

---

# Rules of `restrict`

Very Important Interview Topic.

---

## Rule 1

If pointer is declared restrict:

```c
int *restrict p;
```

then object must be accessed only through:

```c
p
```

during that scope.

---

## Rule 2

Violating `restrict` causes:

```text
Undefined Behavior
```

---

Bad Example:

```c
int x;

int *restrict p = &x;
int *q = &x;

*p = 10;
*q = 20;
```

Violation.

---

# Undefined Behavior Example

```c
int x = 5;

int *restrict p = &x;
int *restrict q = &x;
```

Illegal.

Compiler assumptions break.

Results unpredictable.

---

# Advantages

## Faster Code

```text
Less Memory Access
```

---

## Better Register Usage

```text
More Values In CPU Registers
```

---

## Loop Vectorization

SIMD optimizations possible.

---

## Useful in Embedded Systems

DSP

Automotive

Image Processing

Networking

---

# Disadvantages

## Programmer Responsibility

Compiler trusts you.

---

## Easy To Misuse

Violations create:

```text
Undefined Behavior
```

---

## Hard To Debug

Optimization bugs may appear.

---

# `restrict` vs `const`

Many interviewers ask this.

---

### `const`

```c
const int *p;
```

Means:

```text
Cannot Modify Data
```

---

### `restrict`

```c
int *restrict p;
```

Means:

```text
No Aliasing
```

---

Comparison:

| Feature              | const | restrict |
| -------------------- | ----- | -------- |
| Read Only            | Yes   | No       |
| Optimization         | No    | Yes      |
| Prevent Modification | Yes   | No       |
| Prevent Aliasing     | No    | Yes      |

---

# `restrict` vs Normal Pointer

Normal:

```c
int *p;
```

Compiler assumes aliasing possible.

---

Restrict:

```c
int *restrict p;
```

Compiler assumes no aliasing.

---

# Interview Questions

## What is `restrict`?

`restrict` is a C keyword that tells the compiler that a pointer is the sole reference used to access a particular memory object during its lifetime.

---

## Why Use `restrict`?

To allow the compiler to perform better optimizations by eliminating pointer aliasing concerns.

---

## Is `restrict` Available in C++?

Officially:

```text
No
```

It is a C99 feature.

Some compilers support extensions such as:

```cpp
__restrict
__restrict__
```

---

## What Happens When Code Hits a Restrict Pointer?

The compiler assumes no other pointer accesses the same memory, enabling aggressive optimization.

---

## What Happens If Restrict Rules Are Violated?

```text
Undefined Behavior
```

---

# Most Asked Interview Question

## Difference Between `const` and `restrict`

```c
const int *p;
```

means:

```text
Data Cannot Be Modified
```

---

```c
int *restrict p;
```

means:

```text
No Other Pointer Accesses Same Data
```

---

They solve completely different problems.

---

# Interview Answer (2 Minutes)

The `restrict` keyword was introduced in C99 and is used with pointers to indicate that the pointed-to object will only be accessed through that pointer during its lifetime. This guarantees to the compiler that no aliasing occurs, allowing more aggressive optimizations such as keeping values in registers, reducing memory accesses, and vectorizing loops. `restrict` is commonly used in high-performance applications such as DSP algorithms, image processing, networking, and embedded systems. However, the programmer must ensure that the no-aliasing guarantee is respected; otherwise, the behavior becomes undefined.

---

# Quick Revision

```text
restrict Keyword

Purpose:
Remove Pointer Aliasing

Syntax:

int *restrict p;

Meaning:

Only p accesses
that memory

Benefits:
✔ Faster Code
✔ Better Optimization
✔ SIMD Vectorization
✔ Fewer Memory Reads

Compiler Assumes:

p != q

Important:

Violation
     ↓
Undefined Behavior

Difference:

const
  ↓
Read Only

restrict
  ↓
No Aliasing

Embedded Usage:
✔ DSP
✔ DMA
✔ CAN
✔ Ethernet
✔ Image Processing

Most Important:

restrict =
Compiler Optimization Hint
For Non-Overlapping Memory
```

---

# Conclusion

The `restrict` keyword is a powerful optimization feature introduced in C99 that helps the compiler generate faster code by eliminating aliasing assumptions. It is particularly useful in performance-critical applications such as embedded firmware, DSP algorithms, networking stacks, automotive ECUs, and image processing systems. Understanding `restrict`, pointer aliasing, optimization opportunities, and the consequences of violating the no-aliasing contract is a valuable topic for Embedded C and systems programming interviews.
