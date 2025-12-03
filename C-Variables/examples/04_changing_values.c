#include <stdio.h>
#include "../include/utils.h"

int main() {
    printSeparator();
    printf("EXAMPLE 4: CHANGING VARIABLE VALUES\n");
    printSeparator();
    
    // 1. Basic Value Assignment
    printSection("1. Basic Value Assignment");
    
    int count = 0;
    printf("Initial value: count = %d\n", count);
    
    count = 10;  // Change value
    printf("After assignment: count = %d\n", count);
    
    // 2. Arithmetic Operations
    printSection("2. Changing Values with Arithmetic");
    
    int a = 5, b = 3;
    printf("Initial: a = %d, b = %d\n", a, b);
    
    a = a + b;      // a becomes 8
    b = a - b;      // b becomes 5
    a = a - b;      // a becomes 3
    
    printf("After swapping (no temp): a = %d, b = %d\n", a, b);
    
    // 3. Compound Assignment Operators
    printSection("3. Compound Assignment Operators");
    
    int total = 0;
    printf("Initial total: %d\n", total);
    
    total += 10;    // total = total + 10
    printf("After total += 10: %d\n", total);
    
    total -= 3;     // total = total - 3
    printf("After total -= 3: %d\n", total);
    
    total *= 2;     // total = total * 2
    printf("After total *= 2: %d\n", total);
    
    total /= 4;     // total = total / 4
    printf("After total /= 4: %d\n", total);
    
    total %= 3;     // total = total % 3
    printf("After total %%= 3: %d\n", total);
    
    // 4. Increment and Decrement
    printSection("4. Increment and Decrement Operators");
    
    int counter = 5;
    printf("Initial counter: %d\n", counter);
    
    printf("counter++ (post-increment): %d\n", counter++);
    printf("After post-increment: %d\n", counter);
    
    printf("++counter (pre-increment): %d\n", ++counter);
    printf("After pre-increment: %d\n", counter);
    
    printf("counter-- (post-decrement): %d\n", counter--);
    printf("After post-decrement: %d\n", counter);
    
    printf("--counter (pre-decrement): %d\n", --counter);
    printf("After pre-decrement: %d\n", counter);
    
    // 5. Type Conversion During Assignment
    printSection("5. Type Conversion During Assignment");
    
    int int_val = 10;
    float float_val = 3.14;
    double double_val;
    char char_val = 'A';
    
    // Implicit conversions
    double_val = int_val;        // int to double
    printf("int %d -> double %.2f\n", int_val, double_val);
    
    double_val = float_val;      // float to double
    printf("float %.2f -> double %.2f\n", float_val, double_val);
    
    int_val = float_val;         // float to int (truncation)
    printf("float %.2f -> int %d (truncated)\n", float_val, int_val);
    
    int_val = char_val;          // char to int (ASCII)
    printf("char '%c' -> int %d (ASCII)\n", char_val, int_val);
    
    // 6. Changing Array Elements
    printSection("6. Changing Array Elements");
    
    int numbers[5] = {1, 2, 3, 4, 5};
    
    printf("Original array: ");
    for(int i = 0; i < 5; i++) printf("%d ", numbers[i]);
    printf("\n");
    
    numbers[2] = 99;      // Change third element
    numbers[4] = numbers[0] * 2;  // Change based on other element
    
    printf("Modified array: ");
    for(int i = 0; i < 5; i++) printf("%d ", numbers[i]);
    printf("\n");
    
    // 7. Changing String Characters
    printSection("7. Changing String Characters");
    
    char message[] = "Hello";
    printf("Original string: %s\n", message);
    
    message[0] = 'J';     // Change first character
    printf("After message[0] = 'J': %s\n", message);
    
    // 8. Changing Values Through Pointers
    printSection("8. Changing Values Through Pointers");
    
    int x = 100;
    int *ptr = &x;
    
    printf("Original x: %d\n", x);
    
    *ptr = 200;  // Change value through pointer
    printf("After *ptr = 200: x = %d\n", x);
    
    // Pointer arithmetic to change array elements
    int arr[3] = {10, 20, 30};
    printf("Original array via pointer: ");
    for(int i = 0; i < 3; i++) printf("%d ", *(arr + i));
    printf("\n");
    
    *(arr + 1) = 99;  // Change second element
    printf("After *(arr + 1) = 99: ");
    for(int i = 0; i < 3; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // 9. Changing Multiple Variables Simultaneously
    printSection("9. Changing Multiple Variables Simultaneously");
    
    int p = 1, q = 2, r = 3;
    printf("Before: p=%d, q=%d, r=%d\n", p, q, r);
    
    // Multiple assignment
    p = q = r = 42;
    printf("After p = q = r = 42: p=%d, q=%d, r=%d\n", p, q, r);
    
    // 10. Swapping Values
    printSection("10. Swapping Variable Values");
    
    int first = 77, second = 88;
    printf("Before swap: first=%d, second=%d\n", first, second);
    
    // Using temporary variable
    int temp = first;
    first = second;
    second = temp;
    
    printf("After swap: first=%d, second=%d\n", first, second);
    
    // 11. Conditional Changes
    printSection("11. Conditional Value Changes");
    
    int age = 17;
    printf("Age: %d\n", age);
    
    // Conditional increment
    if(age < 18) {
        printf("Not eligible to vote. ");
        age++;  // Birthday!
        printf("After birthday: %d\n", age);
    }
    
    // Ternary operator for conditional assignment
    int marks = 65;
    char result = (marks >= 50) ? 'P' : 'F';
    printf("Marks: %d, Result: %c\n", marks, result);
    
    // 12. Looping Changes
    printSection("12. Changing Values in Loops");
    
    int sum = 0;
    printf("Sum before loop: %d\n", sum);
    
    for(int i = 1; i <= 5; i++) {
        sum += i;  // Change sum in each iteration
        printf("After adding %d: sum = %d\n", i, sum);
    }
    
    printf("Final sum: %d\n", sum);
    
    printSeparator();
    printf("End of Changing Values Example\n");
    printSeparator();
    
    return 0;
}
