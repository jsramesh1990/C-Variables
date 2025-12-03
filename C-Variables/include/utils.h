#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

// Global variable for extern demonstration
extern int global_usage;

// Function prototypes
void printSeparator();
void printSection(const char* title);
void printVariableInfo(const char* name, void* address, size_t size, const char* type);
void demonstrateTypeSizes();
void demonstrateTypeRanges();
void demonstrateMemoryAddresses();

// Memory demonstration functions
void stackMemoryDemo();
void heapMemoryDemo();
void memoryLayoutDemo();

// Type conversion functions
void demonstrateTypeConversion();
void demonstrateCasting();

// Scope demonstration
void scopeDemo();

#endif // UTILS_H
