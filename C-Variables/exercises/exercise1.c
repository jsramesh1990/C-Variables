#include <stdio.h>
#include "../include/utils.h"

int main() {
    printSeparator();
    printf("EXERCISE 1: VARIABLE BASICS\n");
    printSeparator();
    
    /* Exercise Instructions:
       1. Declare variables of different types
       2. Initialize them with appropriate values
       3. Perform operations
       4. Print results
    */
    
    printf("Part 1: Variable Declaration and Initialization\n");
    printf("===============================================\n");
    
    // TODO 1: Declare an integer variable named 'score' and initialize it to 85
    
    
    // TODO 2: Declare a float variable named 'temperature' and initialize it to 98.6
    
    
    // TODO 3: Declare a char variable named 'grade' and initialize it to 'A'
    
    
    // TODO 4: Declare a double variable named 'pi' and initialize it to 3.1415926535
    
    
    printf("\nPart 2: Basic Operations\n");
    printf("========================\n");
    
    // TODO 5: Create two integer variables a=10 and b=3
    // Calculate and print:
    // - Sum (a + b)
    // - Difference (a - b)
    // - Product (a * b)
    // - Quotient (a / b) as float
    // - Remainder (a % b)
    
    
    printf("\nPart 3: Type Conversion\n");
    printf("======================\n");
    
    // TODO 6: Create an integer variable 'count' with value 7
    // Create a float variable 'average' 
    // Calculate average of count and 3 as float
    // Print the result
    
    
    printf("\nPart 4: Character Operations\n");
    printf("============================\n");
    
    // TODO 7: Create a char variable 'letter' with value 'D'
    // Print:
    // - The character
    // - Its ASCII value
    // - The next character in alphabet
    // - The previous character in alphabet
    
    
    printf("\nPart 5: Multiple Variables\n");
    printf("==========================\n");
    
    // TODO 8: Calculate area and perimeter of a rectangle
    // length = 12.5, width = 8.3
    // Print both results
    
    
    printf("\nPart 6: Variable Modifiers\n");
    printf("===========================\n");
    
    // TODO 9: Create:
    // - An unsigned integer 'distance' with value 50000
    // - A constant float 'TAX_RATE' with value 0.075
    // - A short integer 'small_num' with value 32767
    // Print all three
    
    
    printf("\nPart 7: Memory Information\n");
    printf("==========================\n");
    
    // TODO 10: Declare variables of different types
    // Print their sizes using sizeof()
    // Print their memory addresses
    
    
    // Sample solution (comment out when implementing)
    printf("\n--- Sample Solution ---\n");
    
    // Part 1
    int score = 85;
    float temperature = 98.6;
    char grade = 'A';
    double pi = 3.1415926535;
    
    printf("score = %d\n", score);
    printf("temperature = %.1f\n", temperature);
    printf("grade = %c\n", grade);
    printf("pi = %.10f\n", pi);
    
    // Part 2
    int a = 10, b = 3;
    printf("\na + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %.2f\n", (float)a / b);
    printf("a %% b = %d\n", a % b);
    
    // Part 3
    int count = 7;
    float average = (count + 3) / 2.0;
    printf("\nAverage of %d and 3 = %.2f\n", count, average);
    
    // Part 4
    char letter = 'D';
    printf("\nLetter: %c\n", letter);
    printf("ASCII value: %d\n", letter);
    printf("Next letter: %c\n", letter + 1);
    printf("Previous letter: %c\n", letter - 1);
    
    // Part 5
    float length = 12.5, width = 8.3;
    float area = length * width;
    float perimeter = 2 * (length + width);
    printf("\nRectangle: length=%.1f, width=%.1f\n", length, width);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
    
    // Part 6
    unsigned int distance = 50000;
    const float TAX_RATE = 0.075;
    short small_num = 32767;
    printf("\nDistance: %u\n", distance);
    printf("Tax Rate: %.3f\n", TAX_RATE);
    printf("Small number: %hd\n", small_num);
    
    // Part 7
    printf("\nMemory Information:\n");
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Address of score: %p\n", (void*)&score);
    printf("Address of temperature: %p\n", (void*)&temperature);
    
    printSeparator();
    printf("End of Exercise 1\n");
    printSeparator();
    
    return 0;
}
