#include <stdio.h>
#include "../include/utils.h"

int main() {
    printSeparator();
    printf("EXAMPLE 1: BASIC VARIABLES\n");
    printSeparator();
    
    // 1. Variable Declaration
    printSection("1. Variable Declaration");
    
    int age;            // Declaration without initialization
    float temperature;
    double salary;
    char grade;
    
    printf("Variables declared but not initialized:\n");
    printf("int age;\n");
    printf("float temperature;\n");
    printf("double salary;\n");
    printf("char grade;\n");
    
    // 2. Variable Definition with Initialization
    printSection("2. Variable Definition with Initialization");
    
    int score = 95;              // Integer variable
    float pi = 3.14159;          // Floating point
    double interest_rate = 4.25; // Double precision
    char initial = 'M';          // Character
    unsigned int count = 100;    // Unsigned integer
    
    printf("Initialized variables:\n");
    printf("score = %d\n", score);
    printf("pi = %.5f\n", pi);
    printf("interest_rate = %.2f\n", interest_rate);
    printf("initial = %c\n", initial);
    printf("count = %u\n", count);
    
    // 3. Multiple Variable Declaration
    printSection("3. Multiple Variable Declaration");
    
    int x = 10, y = 20, z = 30;
    float a = 1.1, b = 2.2, c = 3.3;
    
    printf("Multiple integers: x=%d, y=%d, z=%d\n", x, y, z);
    printf("Multiple floats: a=%.1f, b=%.1f, c=%.1f\n", a, b, c);
    
    // 4. Different Integer Types
    printSection("4. Different Integer Types");
    
    short small_number = 32767;          // 2 bytes
    int normal_number = 2147483647;      // 4 bytes
    long large_number = 2147483647L;     // 4 or 8 bytes
    long long very_large = 9223372036854775807LL; // 8 bytes
    
    printf("short: %hd\n", small_number);
    printf("int: %d\n", normal_number);
    printf("long: %ld\n", large_number);
    printf("long long: %lld\n", very_large);
    
    // 5. Unsigned Variables
    printSection("5. Unsigned Variables");
    
    unsigned short us = 65535;
    unsigned int ui = 4294967295U;
    unsigned long ul = 4294967295UL;
    
    printf("unsigned short: %hu\n", us);
    printf("unsigned int: %u\n", ui);
    printf("unsigned long: %lu\n", ul);
    
    // 6. Character Variables
    printSection("6. Character Variables");
    
    char letter = 'A';
    char digit = '9';
    char symbol = '$';
    
    printf("letter: %c (ASCII: %d)\n", letter, letter);
    printf("digit: %c (ASCII: %d)\n", digit, digit);
    printf("symbol: %c (ASCII: %d)\n", symbol, symbol);
    
    // 7. Boolean Simulation
    printSection("7. Boolean Simulation");
    
    int is_true = 1;    // True
    int is_false = 0;   // False
    int is_valid = 1;
    
    printf("is_true: %d (True)\n", is_true);
    printf("is_false: %d (False)\n", is_false);
    printf("is_valid: %d (True)\n", is_valid);
    
    // 8. Size of Variables
    printSection("8. Memory Size of Variables");
    
    printf("Size of char: %zu byte\n", sizeof(char));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    
    // 9. Memory Addresses
    printSection("9. Memory Addresses");
    
    printf("Address of score: %p\n", (void*)&score);
    printf("Address of pi: %p\n", (void*)&pi);
    printf("Address of initial: %p\n", (void*)&initial);
    
    printSeparator();
    printf("End of Basic Variables Example\n");
    printSeparator();
    
    return 0;
}
