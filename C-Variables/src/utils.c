#include "../include/utils.h"

int global_usage = 0;

void printSeparator() {
    printf("\n========================================\n");
}

void printSection(const char* title) {
    printf("\n%s\n", title);
    for(int i = 0; i < strlen(title); i++) printf("=");
    printf("\n");
}

void printVariableInfo(const char* name, void* address, size_t size, const char* type) {
    printf("%-15s: Address = %p, Size = %zu bytes, Type = %s\n", 
           name, address, size, type);
}

void demonstrateTypeSizes() {
    printSection("Data Type Sizes");
    
    printf("char           : %zu byte\n", sizeof(char));
    printf("short          : %zu bytes\n", sizeof(short));
    printf("int            : %zu bytes\n", sizeof(int));
    printf("long           : %zu bytes\n", sizeof(long));
    printf("long long      : %zu bytes\n", sizeof(long long));
    printf("float          : %zu bytes\n", sizeof(float));
    printf("double         : %zu bytes\n", sizeof(double));
    printf("long double    : %zu bytes\n", sizeof(long double));
}

void demonstrateTypeRanges() {
    printSection("Data Type Ranges");
    
    printf("char           : %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char  : 0 to %u\n", UCHAR_MAX);
    printf("short          : %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int            : %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int   : 0 to %u\n", UINT_MAX);
    printf("long           : %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("float          : %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double         : %e to %e\n", DBL_MIN, DBL_MAX);
}

void demonstrateMemoryAddresses() {
    printSection("Memory Address Demonstration");
    
    int a = 10;
    float b = 3.14;
    char c = 'A';
    double d = 2.71828;
    
    printVariableInfo("int a", &a, sizeof(a), "int");
    printVariableInfo("float b", &b, sizeof(b), "float");
    printVariableInfo("char c", &c, sizeof(c), "char");
    printVariableInfo("double d", &d, sizeof(d), "double");
}

void stackMemoryDemo() {
    printSection("Stack Memory Demo");
    
    int stack_var1 = 100;
    int stack_var2 = 200;
    
    printf("Stack Variable 1: %d at %p\n", stack_var1, &stack_var1);
    printf("Stack Variable 2: %d at %p\n", stack_var2, &stack_var2);
    printf("Difference in addresses: %ld bytes\n", 
           (char*)&stack_var2 - (char*)&stack_var1);
}

void heapMemoryDemo() {
    printSection("Heap Memory Demo");
    
    int* heap_var1 = (int*)malloc(sizeof(int));
    int* heap_var2 = (int*)malloc(sizeof(int));
    
    if(heap_var1 && heap_var2) {
        *heap_var1 = 300;
        *heap_var2 = 400;
        
        printf("Heap Variable 1: %d at %p\n", *heap_var1, heap_var1);
        printf("Heap Variable 2: %d at %p\n", *heap_var2, heap_var2);
        
        free(heap_var1);
        free(heap_var2);
    }
}

void memoryLayoutDemo() {
    printSection("Memory Layout Demo");
    
    static int static_var = 500;
    const int const_var = 600;
    register int reg_var = 700;
    
    printf("Static variable: %d\n", static_var);
    printf("Constant variable: %d\n", const_var);
    printf("Register variable: %d (no address available)\n", reg_var);
}

void demonstrateTypeConversion() {
    printSection("Implicit Type Conversion");
    
    int i = 10;
    float f = 3.5;
    double d;
    
    d = i + f;  // i is converted to float, then to double
    printf("int i = %d, float f = %.2f\n", i, f);
    printf("d = i + f = %.2f (implicit conversion)\n", d);
    
    char c = 'A';
    int ascii = c;  // char to int conversion
    printf("char '%c' -> int %d\n", c, ascii);
}

void demonstrateCasting() {
    printSection("Explicit Type Casting");
    
    float f = 3.14159;
    int i;
    
    i = (int)f;  // Explicit cast - truncates decimal part
    printf("float f = %.5f\n", f);
    printf("(int)f = %d (truncated)\n", i);
    
    int a = 5, b = 2;
    float result;
    
    result = (float)a / b;  // Cast a to float before division
    printf("%d / %d = %.2f (with casting)\n", a, b, result);
    printf("%d / %d = %d (without casting)\n", a, b, a / b);
}

void scopeDemo() {
    printSection("Variable Scope Demo");
    
    int global_demo = 999;  // Function scope
    
    {
        int block_var = 888;  // Block scope
        printf("Inside block - block_var: %d\n", block_var);
        printf("Inside block - can access global_demo: %d\n", global_demo);
    }
    
    // block_var is not accessible here
    printf("Outside block - only global_demo: %d\n", global_demo);
}
