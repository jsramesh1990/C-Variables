#include <stdio.h>
#include "../include/utils.h"

int main() {
    printSeparator();
    printf("EXAMPLE 2: VARIABLE INITIALIZATION\n");
    printSeparator();
    
    // 1. Different Initialization Methods
    printSection("1. Different Initialization Methods");
    
    // Method 1: Declaration then assignment
    int a;
    a = 10;
    printf("Method 1 - Separate: a = %d\n", a);
    
    // Method 2: Declaration with initialization
    int b = 20;
    printf("Method 2 - Combined: b = %d\n", b);
    
    // Method 3: Multiple initialization
    int c = 30, d = 40, e = 50;
    printf("Method 3 - Multiple: c=%d, d=%d, e=%d\n", c, d, e);
    
    // 2. Zero Initialization
    printSection("2. Zero Initialization");
    
    int zero_int = 0;
    float zero_float = 0.0;
    char zero_char = '\0';
    double zero_double = 0.0;
    
    printf("Zero int: %d\n", zero_int);
    printf("Zero float: %.1f\n", zero_float);
    printf("Zero char: '%c' (ASCII: %d)\n", zero_char, zero_char);
    printf("Zero double: %.1f\n", zero_double);
    
    // 3. Default Values (Uninitialized variables - DANGEROUS!)
    printSection("3. Uninitialized Variables (Garbage Values)");
    
    int uninit_int;
    float uninit_float;
    char uninit_char;
    
    printf("WARNING: Uninitialized variables contain garbage values!\n");
    printf("uninit_int: %d (garbage)\n", uninit_int);
    printf("uninit_float: %f (garbage)\n", uninit_float);
    printf("uninit_char: '%c' (garbage, ASCII: %d)\n", uninit_char, uninit_char);
    
    // 4. Constant Variables
    printSection("4. Constant Variables (const)");
    
    const int MAX_SIZE = 100;
    const float PI = 3.14159;
    const char NEWLINE = '\n';
    
    printf("Constant MAX_SIZE: %d\n", MAX_SIZE);
    printf("Constant PI: %.5f\n", PI);
    printf("Constant NEWLINE: ASCII %d\n", NEWLINE);
    
    // 5. Static Variables
    printSection("5. Static Variables");
    
    static int static_counter = 0;
    static_counter++;
    printf("Static counter: %d (persists between calls)\n", static_counter);
    
    // 6. Register Variables
    printSection("6. Register Variables (Hint to compiler)");
    
    register int fast_counter;
    for(fast_counter = 0; fast_counter < 5; fast_counter++) {
        printf("Register variable iteration: %d\n", fast_counter);
    }
    
    // 7. External Variables (simulation)
    printSection("7. External Variables (extern)");
    
    extern int external_var;  // Declaration only
    printf("External variable declared (would be defined in another file)\n");
    
    // 8. Array Initialization
    printSection("8. Array Initialization");
    
    int numbers[5] = {1, 2, 3, 4, 5};
    float temperatures[] = {36.5, 37.0, 36.8, 37.2}; // Size inferred
    char name[] = "John";
    
    printf("Integer array: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("Float array: ");
    for(int i = 0; i < 4; i++) {
        printf("%.1f ", temperatures[i]);
    }
    printf("\n");
    
    printf("Character array (string): %s\n", name);
    
    // 9. Partial Array Initialization
    printSection("9. Partial Array Initialization");
    
    int partial[10] = {1, 2, 3};  // First 3 initialized, rest to 0
    printf("Partial array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", partial[i]);
    }
    printf("\n");
    
    // 10. Designated Initializers (C99 feature)
    printSection("10. Designated Initializers");
    
    int designated[10] = {[0]=10, [5]=50, [9]=90};
    printf("Designated array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", designated[i]);
    }
    printf("\n");
    
    printSeparator();
    printf("End of Variable Initialization Example\n");
    printSeparator();
    
    return 0;
}
