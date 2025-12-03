#include <stdio.h>
#include "../include/utils.h"

// Global variable for demonstration
int global_counter = 0;

void demonstrateLocalAccess() {
    printSection("Local Variable Access");
    
    int local_var = 100;
    printf("Inside function: local_var = %d\n", local_var);
    printf("Can access global_counter: %d\n", global_counter);
    
    // Modify global
    global_counter++;
}

void demonstrateBlockScope() {
    printSection("Block Scope Access");
    
    int outer = 50;
    printf("Outer block - outer: %d\n", outer);
    
    {
        int inner = 99;
        printf("Inner block - inner: %d\n", inner);
        printf("Inner block - can access outer: %d\n", outer);
    }
    
    // inner is not accessible here
    printf("Back to outer block - outer: %d\n", outer);
}

void demonstrateStatic() {
    printSection("Static Variable Access");
    
    static int static_count = 0;
    static_count++;
    printf("Static count: %d\n", static_count);
}

int main() {
    printSeparator();
    printf("EXAMPLE 3: ACCESSING VARIABLES\n");
    printSeparator();
    
    // 1. Direct Access
    printSection("1. Direct Variable Access");
    
    int score = 95;
    float average = 87.5;
    char grade = 'A';
    
    printf("Direct access using variable names:\n");
    printf("Score: %d\n", score);
    printf("Average: %.1f\n", average);
    printf("Grade: %c\n", grade);
    
    // 2. Memory Address Access
    printSection("2. Memory Address Access");
    
    printf("Using address-of operator (&):\n");
    printf("Address of score: %p\n", (void*)&score);
    printf("Address of average: %p\n", (void*)&average);
    printf("Address of grade: %p\n", (void*)&grade);
    
    // 3. Pointer Access
    printSection("3. Pointer Access");
    
    int value = 42;
    int *ptr = &value;  // Pointer to value
    
    printf("Original value: %d\n", value);
    printf("Pointer contains address: %p\n", (void*)ptr);
    printf("Dereferenced pointer: %d\n", *ptr);
    
    // Modify through pointer
    *ptr = 99;
    printf("After modification through pointer: %d\n", value);
    
    // 4. Array Element Access
    printSection("4. Array Element Access");
    
    int numbers[] = {10, 20, 30, 40, 50};
    
    printf("Array access methods:\n");
    printf("numbers[0]: %d\n", numbers[0]);      // Index notation
    printf("*(numbers): %d\n", *(numbers));      // Pointer notation
    printf("*(numbers + 2): %d\n", *(numbers + 2)); // Pointer arithmetic
    
    // 5. Structure Access
    printSection("5. Structure Member Access");
    
    struct Student {
        char name[20];
        int age;
        float gpa;
    };
    
    struct Student student1 = {"Alice", 20, 3.8};
    
    printf("Structure access:\n");
    printf("Dot operator: %s, %d, %.1f\n", 
           student1.name, student1.age, student1.gpa);
    
    struct Student *student_ptr = &student1;
    printf("Arrow operator: %s, %d, %.1f\n", 
           student_ptr->name, student_ptr->age, student_ptr->gpa);
    
    // 6. Scope Demonstrations
    demonstrateLocalAccess();
    demonstrateBlockScope();
    
    // 7. Static Variable Access
    demonstrateStatic();
    demonstrateStatic();  // Call again to show persistence
    
    // 8. Register Variable Access
    printSection("6. Register Variable Access");
    
    register int reg_var = 777;
    printf("Register variable value: %d\n", reg_var);
    // Note: Cannot take address of register variable: &reg_var is invalid
    
    // 9. Volatile Variable Access
    printSection("7. Volatile Variable Access");
    
    volatile int volatile_var = 123;
    printf("Volatile variable: %d\n", volatile_var);
    
    // 10. Constant Variable Access
    printSection("8. Constant Variable Access");
    
    const int MAX = 100;
    printf("Constant: %d\n", MAX);
    // MAX = 200;  // This would cause compile error
    
    // 11. Access through Different Representations
    printSection("9. Access Through Different Representations");
    
    int num = 255;
    printf("Decimal: %d\n", num);
    printf("Hexadecimal: 0x%x\n", num);
    printf("Octal: 0%o\n", num);
    printf("Character (if valid): %c\n", (char)num);
    
    // 12. Type Aliases
    printSection("10. Type Aliases (typedef)");
    
    typedef int Score;
    typedef float Temperature;
    
    Score math_score = 85;
    Temperature body_temp = 36.5;
    
    printf("Using type aliases:\n");
    printf("Math Score: %d\n", math_score);
    printf("Body Temperature: %.1f\n", body_temp);
    
    printSeparator();
    printf("End of Accessing Variables Example\n");
    printSeparator();
    
    return 0;
}
