/**
 * C Variables Tutorial - Unified Main Program
 * Demonstrates all concepts in one comprehensive program
 */

#include <stdio.h>
#include <string.h>
#include "utils.h"

// Function declarations
void demonstrate_basic_variables();
void demonstrate_initialization();
void demonstrate_accessing_variables();
void demonstrate_changing_values();
void demonstrate_using_variables();
void demonstrate_memory_allocation();
void demonstrate_variable_rules();
void run_exercises();

int main() {
    printf("\n========================================\n");
    printf("      C VARIABLES TUTORIAL PROGRAM      \n");
    printf("========================================\n\n");
    
    int choice;
    
    do {
        printf("\n📚 MAIN MENU\n");
        printf("=============\n");
        printf("1. Basic Variables\n");
        printf("2. Variable Initialization\n");
        printf("3. Accessing Variables\n");
        printf("4. Changing Values\n");
        printf("5. Using Variables in Expressions\n");
        printf("6. Memory Allocation\n");
        printf("7. Variable Naming Rules\n");
        printf("8. Run Exercises\n");
        printf("9. Run All Demonstrations\n");
        printf("0. Exit\n");
        printf("\nEnter your choice (0-9): ");
        
        scanf("%d", &choice);
        clear_input_buffer();
        
        printf("\n");
        
        switch(choice) {
            case 1:
                demonstrate_basic_variables();
                break;
            case 2:
                demonstrate_initialization();
                break;
            case 3:
                demonstrate_accessing_variables();
                break;
            case 4:
                demonstrate_changing_values();
                break;
            case 5:
                demonstrate_using_variables();
                break;
            case 6:
                demonstrate_memory_allocation();
                break;
            case 7:
                demonstrate_variable_rules();
                break;
            case 8:
                run_exercises();
                break;
            case 9:
                printf("🏃 Running all demonstrations...\n");
                printf("========================================\n\n");
                demonstrate_basic_variables();
                demonstrate_initialization();
                demonstrate_accessing_variables();
                demonstrate_changing_values();
                demonstrate_using_variables();
                demonstrate_memory_allocation();
                demonstrate_variable_rules();
                break;
            case 0:
                printf("👋 Exiting program. Goodbye!\n");
                break;
            default:
                printf("❌ Invalid choice. Please try again.\n");
        }
        
        if (choice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while (choice != 0);
    
    return 0;
}

void demonstrate_basic_variables() {
    printf("🎯 1. BASIC VARIABLES DEMONSTRATION\n");
    printf("========================================\n\n");
    
    // Integer variable
    int age = 20;
    
    // Floating-point variable
    float height = 5.7;
    
    // Character variable
    char grade = 'A';
    
    // Double precision floating-point
    double pi = 3.1415926535;
    
    // Multiple variables in one line
    int x = 10, y = 20, z = 30;
    
    printf("Different types of variables:\n");
    printf("-----------------------------\n");
    printf("int age = %d\n", age);
    printf("float height = %.1f\n", height);
    printf("char grade = '%c'\n", grade);
    printf("double pi = %.10f\n", pi);
    printf("Multiple variables: x=%d, y=%d, z=%d\n\n", x, y, z);
    
    printf("Variable names act as labels for memory locations.\n");
    printf("Each variable has a specific type that determines:\n");
    printf("  - The size of memory allocated\n");
    printf("  - The format for storing values\n");
    printf("  - The operations that can be performed\n");
}

void demonstrate_initialization() {
    printf("🎯 2. VARIABLE INITIALIZATION\n");
    printf("========================================\n\n");
    
    printf("Method 1: Initialization at declaration\n");
    printf("----------------------------------------\n");
    int initialized = 100;
    printf("int initialized = %d;\n", initialized);
    printf("Value: %d\n\n", initialized);
    
    printf("Method 2: Declaration first, then assignment\n");
    printf("--------------------------------------------\n");
    int declared_later;
    declared_later = 200;
    printf("int declared_later;\n");
    printf("declared_later = %d;\n", declared_later);
    printf("Value: %d\n\n", declared_later);
    
    printf("Method 3: Multiple initialization\n");
    printf("---------------------------------\n");
    int a = 1, b = 2, c = 3;
    printf("int a = %d, b = %d, c = %d;\n", a, b, c);
    printf("Values: a=%d, b=%d, c=%d\n\n", a, b, c);
    
    printf("⚠️  Important: Uninitialized variables contain garbage values!\n");
    int garbage;
    printf("Uninitialized variable: %d (garbage value)\n", garbage);
}

void demonstrate_accessing_variables() {
    printf("🎯 3. ACCESSING VARIABLES\n");
    printf("========================================\n\n");
    
    int score = 95;
    float temperature = 36.6;
    char initial = 'J';
    
    printf("Variables can be accessed by name:\n");
    printf("----------------------------------\n");
    printf("score = %d\n", score);
    printf("temperature = %.1f\n", temperature);
    printf("initial = '%c'\n\n", initial);
    
    printf("Variables can be used in calculations:\n");
    printf("--------------------------------------\n");
    int bonus = 5;
    int total_score = score + bonus;
    printf("score (%d) + bonus (%d) = total_score (%d)\n\n", score, bonus, total_score);
    
    printf("Variables can control program flow:\n");
    printf("-----------------------------------\n");
    if (score >= 90) {
        printf("Grade: A (Excellent!)\n");
    } else if (score >= 80) {
        printf("Grade: B (Good)\n");
    } else {
        printf("Grade: Needs improvement\n");
    }
}

void demonstrate_changing_values() {
    printf("🎯 4. CHANGING VARIABLE VALUES\n");
    printf("========================================\n\n");
    
    printf("Initial value:\n");
    int counter = 10;
    printf("counter = %d\n\n", counter);
    
    printf("Direct assignment:\n");
    counter = 20;
    printf("counter = 20;\n");
    printf("counter is now: %d\n\n", counter);
    
    printf("Using arithmetic operations:\n");
    counter = counter + 5;
    printf("counter = counter + 5;\n");
    printf("counter is now: %d\n\n", counter);
    
    printf("Shortcut operators:\n");
    printf("counter += 10;  // Add 10\n");
    counter += 10;
    printf("counter is now: %d\n\n", counter);
    
    printf("counter *= 2;   // Multiply by 2\n");
    counter *= 2;
    printf("counter is now: %d\n\n", counter);
    
    printf("Increment and decrement:\n");
    printf("counter++;      // Increment\n");
    counter++;
    printf("counter is now: %d\n\n", counter);
    
    printf("counter--;      // Decrement\n");
    counter--;
    printf("counter is now: %d\n", counter);
}

void demonstrate_using_variables() {
    printf("🎯 5. USING VARIABLES IN EXPRESSIONS\n");
    printf("========================================\n\n");
    
    printf("Variables substitute for values in expressions:\n");
    printf("----------------------------------------------\n");
    
    int width = 15;
    int height = 8;
    int area = width * height;
    
    printf("Rectangle calculation:\n");
    printf("width = %d, height = %d\n", width, height);
    printf("area = width * height = %d * %d = %d\n\n", width, height, area);
    
    printf("Complex mathematical expression:\n");
    printf("--------------------------------\n");
    float radius = 5.0;
    float circle_area = 3.14159 * radius * radius;
    float circumference = 2 * 3.14159 * radius;
    
    printf("radius = %.1f\n", radius);
    printf("circle_area = π * radius² = %.5f\n", circle_area);
    printf("circumference = 2 * π * radius = %.5f\n\n", circumference);
    
    printf("Variables in logical expressions:\n");
    printf("---------------------------------\n");
    int x = 25, y = 30;
    printf("x = %d, y = %d\n", x, y);
    printf("x > y: %s\n", x > y ? "true" : "false");
    printf("x == y: %s\n", x == y ? "true" : "false");
    printf("x != y: %s\n", x != y ? "true" : "false");
}

void demonstrate_memory_allocation() {
    printf("🎯 6. MEMORY ALLOCATION\n");
    printf("========================================\n\n");
    
    printf("Different data types use different amounts of memory:\n");
    printf("----------------------------------------------------\n");
    
    int integer_var = 42;
    float float_var = 3.14;
    char char_var = 'X';
    double double_var = 2.718281828459045;
    long long long_long_var = 123456789012345;
    
    printf("Data Type          Variable       Size (bytes)\n");
    printf("----------------------------------------------\n");
    printf("int                integer_var    %zu\n", sizeof(integer_var));
    printf("float              float_var      %zu\n", sizeof(float_var));
    printf("char               char_var       %zu\n", sizeof(char_var));
    printf("double             double_var     %zu\n", sizeof(double_var));
    printf("long long          long_long_var  %zu\n", sizeof(long_long_var));
    
    printf("\nMemory addresses:\n");
    printf("-----------------\n");
    printf("&integer_var    = %p\n", (void*)&integer_var);
    printf("&float_var      = %p\n", (void*)&float_var);
    printf("&char_var       = %p\n", (void*)&char_var);
    printf("&double_var     = %p\n", (void*)&double_var);
    
    printf("\n⚠️  Note: Addresses will differ each time program runs.\n");
}

void demonstrate_variable_rules() {
    printf("🎯 7. VARIABLE NAMING RULES\n");
    printf("========================================\n\n");
    
    printf("✅ VALID VARIABLE NAMES:\n");
    printf("------------------------\n");
    printf("int age;                    // Letters only\n");
    printf("float _height;              // Starts with underscore\n");
    printf("char student_name;          // Letters and underscore\n");
    printf("double test1;               // Letters and digits\n");
    printf("int myVariable123;          // Mixed case and digits\n\n");
    
    printf("❌ INVALID VARIABLE NAMES:\n");
    printf("--------------------------\n");
    printf("int 1st_value;              // Starts with digit\n");
    printf("float my height;            // Contains space\n");
    printf("char float;                 // Reserved keyword\n");
    printf("int a-b;                    // Contains hyphen\n");
    printf("double my.name;             // Contains dot\n");
    printf("int user@name;              // Contains @ symbol\n\n");
    
    printf("📝 BEST PRACTICES:\n");
    printf("------------------\n");
    printf("1. Use descriptive names (student_count vs s)\n");
    printf("2. Follow consistent naming convention:\n");
    printf("   - snake_case: student_age\n");
    printf("   - camelCase: studentAge\n");
    printf("3. Avoid single letters except for loop counters\n");
    printf("4. Use ALL_CAPS for constants: #define MAX_SIZE 100\n");
    printf("5. Make names meaningful and self-documenting\n");
}

void run_exercises() {
    printf("🎯 8. PRACTICE EXERCISES\n");
    printf("========================================\n\n");
    
    printf("Exercise 1: Basic Variable Operations\n");
    printf("-------------------------------------\n");
    
    // Simulate exercise 1
    int score = 85;
    float temperature;
    char initial = 'J';
    
    printf("Task 1: int score = %d;\n", score);
    printf("Task 3: char initial = '%c';\n", initial);
    
    temperature = 36.5;
    printf("Task 5: temperature = %.1f;\n\n", temperature);
    
    printf("Exercise 2: Variable Operations\n");
    printf("-------------------------------\n");
    
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);
    printf("Sum: %d + %d = %d\n", a, b, a + b);
    printf("Difference: %d - %d = %d\n", a, b, a - b);
    printf("Product: %d * %d = %d\n", a, b, a * b);
    printf("Quotient: %d / %d = %d (integer division)\n\n", a, b, a / b);
    
    // Swap without third variable
    printf("Swapping without third variable:\n");
    printf("Before swap: a=%d, b=%d\n", a, b);
    a = a + b;  // a becomes 30
    b = a - b;  // b becomes 10
    a = a - b;  // a becomes 20
    printf("After swap: a=%d, b=%d\n", a, b);
}
