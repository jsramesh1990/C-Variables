#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"

int main() {
    printSeparator();
    printf("EXAMPLE 6: MEMORY ALLOCATION\n");
    printSeparator();
    
    // 1. Stack vs Heap Memory
    printSection("1. Stack Memory Allocation");
    
    int stack_var = 42;           // Allocated on stack
    char stack_array[100];        // Allocated on stack
    float stack_float = 3.14;
    
    printf("Stack variables:\n");
    printf("stack_var: %d at %p\n", stack_var, (void*)&stack_var);
    printf("stack_array: 100 bytes at %p\n", (void*)stack_array);
    printf("stack_float: %.2f at %p\n", stack_float, (void*)&stack_float);
    
    // 2. Heap Memory Allocation
    printSection("2. Heap Memory Allocation (Dynamic)");
    
    // Allocate single integer
    int *heap_int = (int*)malloc(sizeof(int));
    if(heap_int == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    *heap_int = 100;
    printf("Heap integer: %d at %p\n", *heap_int, (void*)heap_int);
    
    // Allocate array of integers
    int *heap_array = (int*)malloc(5 * sizeof(int));
    if(heap_array) {
        for(int i = 0; i < 5; i++) {
            heap_array[i] = i * 10;
        }
        printf("Heap array: ");
        for(int i = 0; i < 5; i++) {
            printf("%d ", heap_array[i]);
        }
        printf("at %p\n", (void*)heap_array);
    }
    
    // 3. Calloc - Allocates and Initializes to Zero
    printSection("3. Calloc - Allocated and Zero-initialized");
    
    int *calloc_array = (int*)calloc(10, sizeof(int));
    if(calloc_array) {
        printf("Calloc array (all zeros): ");
        for(int i = 0; i < 10; i++) {
            printf("%d ", calloc_array[i]);
        }
        printf("\n");
    }
    
    // 4. Realloc - Resize Allocated Memory
    printSection("4. Realloc - Resizing Memory");
    
    int *dynamic_array = (int*)malloc(3 * sizeof(int));
    if(dynamic_array) {
        for(int i = 0; i < 3; i++) {
            dynamic_array[i] = i + 1;
        }
        
        printf("Original array (size 3): ");
        for(int i = 0; i < 3; i++) printf("%d ", dynamic_array[i]);
        printf("\n");
        
        // Resize to 6 elements
        int *temp = (int*)realloc(dynamic_array, 6 * sizeof(int));
        if(temp) {
            dynamic_array = temp;
            // Initialize new elements
            for(int i = 3; i < 6; i++) {
                dynamic_array[i] = (i + 1) * 10;
            }
            
            printf("Resized array (size 6): ");
            for(int i = 0; i < 6; i++) printf("%d ", dynamic_array[i]);
            printf("\n");
        }
    }
    
    // 5. Memory Leak Demonstration
    printSection("5. Memory Leak Prevention");
    
    int *leaky = (int*)malloc(sizeof(int));
    *leaky = 42;
    printf("Allocated memory at %p\n", (void*)leaky);
    
    // This would cause memory leak if we don't free it
    free(leaky);  // Correct: free the memory
    printf("Memory freed (no leak)\n");
    
    // 6. Dangling Pointer Example
    printSection("6. Dangling Pointer Prevention");
    
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 99;
    
    printf("Before free: *ptr = %d\n", *ptr);
    free(ptr);  // Memory is freed
    
    // ptr is now a dangling pointer
    ptr = NULL;  // Good practice: set to NULL after freeing
    printf("After free and setting to NULL: ptr = %p\n", (void*)ptr);
    
    // 7. String Allocation
    printSection("7. String Memory Allocation");
    
    // Stack string
    char stack_string[] = "Hello, Stack!";
    
    // Heap string
    char *heap_string = (char*)malloc(50 * sizeof(char));
    if(heap_string) {
        strcpy(heap_string, "Hello, Heap!");
        printf("Stack string: %s\n", stack_string);
        printf("Heap string: %s\n", heap_string);
    }
    
    // 8. 2D Array Allocation
    printSection("8. 2D Array Dynamic Allocation");
    
    int rows = 3, cols = 4;
    
    // Allocate array of pointers (rows)
    int **matrix = (int**)malloc(rows * sizeof(int*));
    if(matrix) {
        // Allocate each row
        for(int i = 0; i < rows; i++) {
            matrix[i] = (int*)malloc(cols * sizeof(int));
            if(matrix[i]) {
                for(int j = 0; j < cols; j++) {
                    matrix[i][j] = i * 10 + j;
                }
            }
        }
        
        printf("2D Matrix (%dx%d):\n", rows, cols);
        for(int i = 0; i < rows; i++) {
            printf("Row %d: ", i);
            for(int j = 0; j < cols; j++) {
                printf("%2d ", matrix[i][j]);
            }
            printf("\n");
        }
        
        // Free 2D array
        for(int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
    
    // 9. Memory Alignment
    printSection("9. Memory Alignment");
    
    struct AlignTest {
        char a;      // 1 byte
        int b;       // 4 bytes
        short c;     // 2 bytes
        double d;    // 8 bytes
    };
    
    struct AlignTest test;
    printf("Structure sizes:\n");
    printf("sizeof(char): %zu\n", sizeof(char));
    printf("sizeof(int): %zu\n", sizeof(int));
    printf("sizeof(short): %zu\n", sizeof(short));
    printf("sizeof(double): %zu\n", sizeof(double));
    printf("sizeof(struct): %zu (with padding)\n", sizeof(struct AlignTest));
    
    // 10. Memory Pool Example
    printSection("10. Memory Pool Allocation");
    
    #define POOL_SIZE 1000
    static char memory_pool[POOL_SIZE];
    static size_t pool_index = 0;
    
    // Simple memory pool allocation
    void* pool_alloc(size_t size) {
        if(pool_index + size > POOL_SIZE) {
            return NULL;
        }
        void* ptr = &memory_pool[pool_index];
        pool_index += size;
        return ptr;
    }
    
    int *pool_int = (int*)pool_alloc(sizeof(int));
    float *pool_float = (float*)pool_alloc(sizeof(float));
    
    if(pool_int && pool_float) {
        *pool_int = 777;
        *pool_float = 3.14159;
        printf("Pool int: %d at %p\n", *pool_int, (void*)pool_int);
        printf("Pool float: %.5f at %p\n", *pool_float, (void*)pool_float);
    }
    
    // 11. Stack Overflow Demonstration
    printSection("11. Stack Overflow Risk");
    
    printf("Large stack allocation can cause stack overflow\n");
    printf("Uncomment the following to see the risk:\n");
    printf("// char huge_array[10000000];  // 10MB on stack - DANGER!\n");
    printf("Use heap allocation for large data:\n");
    
    // Safe: use heap for large data
    char *large_buffer = (char*)malloc(10000000);  // 10MB on heap
    if(large_buffer) {
        printf("Allocated 10MB safely on heap at %p\n", (void*)large_buffer);
        free(large_buffer);
    }
    
    // 12. Memory Usage Best Practices
    printSection("12. Memory Management Best Practices");
    
    printf("1. Always check malloc/calloc/realloc return value\n");
    printf("2. Always free allocated memory\n");
    printf("3. Set pointers to NULL after freeing\n");
    printf("4. Use sizeof() with types, not variables\n");
    printf("5. Consider memory alignment\n");
    printf("6. Use stack for small, short-lived data\n");
    printf("7. Use heap for large or dynamic data\n");
    
    // Clean up all heap allocations
    printSection("Cleanup");
    
    if(heap_int) free(heap_int);
    if(heap_array) free(heap_array);
    if(calloc_array) free(calloc_array);
    if(dynamic_array) free(dynamic_array);
    if(heap_string) free(heap_string);
    
    printf("All heap memory freed successfully\n");
    
    printSeparator();
    printf("End of Memory Allocation Example\n");
    printSeparator();
    
    return 0;
}
