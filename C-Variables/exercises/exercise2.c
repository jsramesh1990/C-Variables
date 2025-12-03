#include <stdio.h>
#include "../include/utils.h"

int main() {
    printSeparator();
    printf("EXERCISE 2: VARIABLE OPERATIONS\n");
    printSeparator();
    
    /* Exercise Instructions:
       1. Work with different variable operations
       2. Practice type conversions
       3. Work with arrays and pointers
       4. Solve practical problems
    */
    
    printf("Part 1: Arithmetic Operations\n");
    printf("=============================\n");
    
    // TODO 1: Create a program that converts Celsius to Fahrenheit
    // Formula: F = (C × 9/5) + 32
    // Use float variables for precision
    
    
    printf("\nPart 2: Increment/Decrement Operations\n");
    printf("======================================\n");
    
    // TODO 2: Demonstrate pre-increment and post-increment
    // Start with x = 5
    // Show the difference between x++ and ++x
    
    
    printf("\nPart 3: Compound Assignment\n");
    printf("===========================\n");
    
    // TODO 3: Start with balance = 1000.00
    // Use compound operators to:
    // - Add 500.00
    // - Subtract 200.00
    // - Multiply by 1.05 (5% interest)
    // - Divide by 2
    // Print balance after each operation
    
    
    printf("\nPart 4: Type Casting\n");
    printf("====================\n");
    
    // TODO 4: Given integer variables: total = 17, count = 4
    // Calculate and print:
    // - Integer division result
    // - Float division result (with casting)
    // - The average as float
    
    
    printf("\nPart 5: Working with Arrays\n");
    printf("===========================\n");
    
    // TODO 5: Create an array of 5 integers
    // Initialize with values 10, 20, 30, 40, 50
    // Calculate and print:
    // - Sum of all elements
    // - Average of elements
    // - Maximum element
    // - Minimum element
    
    
    printf("\nPart 6: Character Operations\n");
    printf("============================\n");
    
    // TODO 6: Create a program that:
    // 1. Takes a lowercase letter
    // 2. Converts it to uppercase
    // 3. Converts it to the next letter
    // 4. Converts it to a digit if it's '0'-'9'
    // Hint: ASCII values: 'a'=97, 'A'=65, '0'=48
    
    
    printf("\nPart 7: Bitwise Operations\n");
    printf("==========================\n");
    
    // TODO 7: Given two numbers a=12 (binary: 1100) and b=10 (binary: 1010)
    // Calculate and print:
    // - a & b (bitwise AND)
    // - a | b (bitwise OR)
    // - a ^ b (bitwise XOR)
    // - ~a (bitwise NOT)
    // - a << 2 (left shift)
    // - a >> 1 (right shift)
    
    
    printf("\nPart 8: Pointer Operations\n");
    printf("==========================\n");
    
    // TODO 8: Create an integer variable value = 42
    // Create a pointer to it
    // Use the pointer to:
    // - Print the value
    // - Change the value to 99
    // - Print the address
    
    
    printf("\nPart 9: Swapping Values\n");
    printf("=======================\n");
    
    // TODO 9: Swap values of two variables without using a third variable
    // Use arithmetic operations to swap
    
    
    printf("\nPart 10: Complex Expression\n");
    printf("===========================\n");
    
    // TODO 10: Given: x = 5, y = 3, z = 2
    // Calculate: result = (x * y) + (y / z) - (x % z)
    // Print the result with proper type handling
    
    
    // Sample solution (comment out when implementing)
    printf("\n--- Sample Solution ---\n");
    
    // Part 1
    float celsius = 25.0;
    float fahrenheit = (celsius * 9/5) + 32;
    printf("Temperature Conversion:\n");
    printf("%.1f°C = %.1f°F\n", celsius, fahrenheit);
    
    // Part 2
    int x = 5;
    printf("\nIncrement Operations:\n");
    printf("Initial x = %d\n", x);
    printf("x++ returns: %d, x becomes: %d\n", x++, x);
    x = 5;  // Reset
    printf("++x returns: %d, x becomes: %d\n", ++x, x);
    
    // Part 3
    float balance = 1000.00;
    printf("\nCompound Assignment:\n");
    printf("Initial balance: $%.2f\n", balance);
    balance += 500.00;
    printf("After adding $500: $%.2f\n", balance);
    balance -= 200.00;
    printf("After subtracting $200: $%.2f\n", balance);
    balance *= 1.05;
    printf("After 5%% interest: $%.2f\n", balance);
    balance /= 2;
    printf("After dividing by 2: $%.2f\n", balance);
    
    // Part 4
    int total = 17, count = 4;
    printf("\nType Casting:\n");
    printf("Integer division: %d / %d = %d\n", total, count, total / count);
    printf("Float division: %d / %d = %.2f\n", total, count, (float)total / count);
    printf("Average: %.2f\n", (float)total / count);
    
    // Part 5
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum = 0, max = numbers[0], min = numbers[0];
    
    for(int i = 0; i < 5; i++) {
        sum += numbers[i];
        if(numbers[i] > max) max = numbers[i];
        if(numbers[i] < min) min = numbers[i];
    }
    
    printf("\nArray Operations:\n");
    printf("Numbers: ");
    for(int i = 0; i < 5; i++) printf("%d ", numbers[i]);
    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / 5);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    
    // Part 6
    char lowercase = 'd';
    printf("\nCharacter Operations:\n");
    printf("Lowercase: %c\n", lowercase);
    printf("Uppercase: %c\n", lowercase - 32);
    printf("Next letter: %c\n", lowercase + 1);
    
    char digit_char = '7';
    printf("\nCharacter '%c' to digit: %d\n", digit_char, digit_char - '0');
    
    // Part 7
    int a_bit = 12, b_bit = 10;
    printf("\nBitwise Operations:\n");
    printf("a = %d (binary: 1100), b = %d (binary: 1010)\n", a_bit, b_bit);
    printf("a & b = %d\n", a_bit & b_bit);
    printf("a | b = %d\n", a_bit | b_bit);
    printf("a ^ b = %d\n", a_bit ^ b_bit);
    printf("~a = %d\n", ~a_bit);
    printf("a << 2 = %d\n", a_bit << 2);
    printf("a >> 1 = %d\n", a_bit >> 1);
    
    // Part 8
    int value = 42;
    int *ptr = &value;
    printf("\nPointer Operations:\n");
    printf("Original value: %d\n", *ptr);
    *ptr = 99;
    printf("Changed through pointer: %d\n", value);
    printf("Address: %p\n", (void*)ptr);
    
    // Part 9
    int num1 = 15, num2 = 25;
    printf("\nSwapping without third variable:\n");
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    
    // Swap using arithmetic
    num1 = num1 + num2;  // num1 becomes 40
    num2 = num1 - num2;  // num2 becomes 15
    num1 = num1 - num2;  // num1 becomes 25
    
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    
    // Part 10
    int x_val = 5, y_val = 3, z_val = 2;
    float result = (x_val * y_val) + ((float)y_val / z_val) - (x_val % z_val);
    printf("\nComplex Expression:\n");
    printf("(%d * %d) + (%d / %d) - (%d %% %d)\n", x_val, y_val, y_val, z_val, x_val, z_val);
    printf("Result: %.2f\n", result);
    
    printSeparator();
    printf("End of Exercise 2\n");
    printSeparator();
    
    return 0;
}
