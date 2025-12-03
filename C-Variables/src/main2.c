#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"

// Global variable for demonstration
int global_demo = 0;

// Function prototypes
void runExample1();
void runExample2();
void runExample3();
void runExample4();
void runExample5();
void runExample6();
void runExercise1();
void runExercise2();
void runExercise3();
void demonstrateAllConcepts();

int main(int argc, char *argv[]) {
    printSeparator();
    printf("C VARIABLES TUTORIAL - COMPREHENSIVE PROJECT\n");
    printSeparator();
    
    printf("Author: C Programming Tutorial\n");
    printf("Description: Complete guide to C variables with examples and exercises\n");
    printf("Compiled: %s %s\n", __DATE__, __TIME__);
    printSeparator();
    
    // Check command line arguments
    if(argc > 1) {
        char *option = argv[1];
        
        if(strcmp(option, "example1") == 0) runExample1();
        else if(strcmp(option, "example2") == 0) runExample2();
        else if(strcmp(option, "example3") == 0) runExample3();
        else if(strcmp(option, "example4") == 0) runExample4();
        else if(strcmp(option, "example5") == 0) runExercise5();
        else if(strcmp(option, "example6") == 0) runExample6();
        else if(strcmp(option, "exercise1") == 0) runExercise1();
        else if(strcmp(option, "exercise2") == 0) runExercise2();
        else if(strcmp(option, "exercise3") == 0) runExercise3();
        else if(strcmp(option, "all") == 0) demonstrateAllConcepts();
        else if(strcmp(option, "help") == 0) {
            printf("\nAvailable options:\n");
            printf("  example1    - Basic variables\n");
            printf("  example2    - Variable initialization\n");
            printf("  example3    - Accessing variables\n");
            printf("  example4    - Changing values\n");
            printf("  example5    - Using variables\n");
            printf("  example6    - Memory allocation\n");
            printf("  exercise1   - Basic exercises\n");
            printf("  exercise2   - Operation exercises\n");
            printf("  exercise3   - Advanced exercises\n");
            printf("  all         - Run all demonstrations\n");
            printf("  help        - Show this help\n");
        }
        else {
            printf("Unknown option: %s\n", option);
            printf("Use 'help' for available options.\n");
        }
        
        printSeparator();
        printf("Program completed successfully.\n");
        printSeparator();
        return 0;
    }
    
    // Interactive menu
    int choice;
    do {
        printf("\nMAIN MENU\n");
        printf("=========\n");
        printf("1. Basic Variables Example\n");
        printf("2. Variable Initialization Example\n");
        printf("3. Accessing Variables Example\n");
        printf("4. Changing Values Example\n");
        printf("5. Using Variables Example\n");
        printf("6. Memory Allocation Example\n");
        printf("7. Exercise 1: Variable Basics\n");
        printf("8. Exercise 2: Variable Operations\n");
        printf("9. Exercise 3: Advanced Concepts\n");
        printf("10. Demonstrate All Concepts\n");
        printf("11. Show Variable Rules\n");
        printf("12. Exit\n");
        printf("\nEnter your choice (1-12): ");
        
        // In a real program, you'd use scanf, but for simplicity:
        choice = 12; // Default to exit
        
        // Simulate user input for demonstration
        static int demo_counter = 0;
        if(demo_counter < 10) {
            choice = (demo_counter % 10) + 1;
            demo_counter++;
            printf("%d (auto-selected for demo)\n", choice);
        } else {
            break;
        }
        
        switch(choice) {
            case 1: runExample1(); break;
            case 2: runExample2(); break;
            case 3: runExample3(); break;
            case 4: runExample4(); break;
            case 5: runExample5(); break;
            case 6: runExample6(); break;
            case 7: runExercise1(); break;
            case 8: runExercise2(); break;
            case 9: runExercise3(); break;
            case 10: demonstrateAllConcepts(); break;
            case 11:
                printSeparator();
                printf("VARIABLE RULES SUMMARY\n");
                printSeparator();
                demonstrateTypeSizes();
                demonstrateTypeRanges();
                demonstrateMemoryAddresses();
                break;
            case 12: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
        
        if(choice != 12) {
            printf("\nPress Enter to continue...\n");
            // In real program: getchar();
        }
        
    } while(choice != 12 && demo_counter < 10);
    
    printSeparator();
    printf("Thank you for using C Variables Tutorial!\n");
    printf("All examples and exercises completed.\n");
    printSeparator();
    
    return 0;
}

// Example runners (simplified versions)
void runExample1() {
    printf("\nRunning Example 1: Basic Variables\n");
    // Include the core concepts from 01_basic_variables.c
    demonstrateTypeSizes();
    demonstrateTypeRanges();
}

void runExample2() {
    printf("\nRunning Example 2: Variable Initialization\n");
    // Core concepts would be included here
    stackMemoryDemo();
    heapMemoryDemo();
}

void runExample3() {
    printf("\nRunning Example 3: Accessing Variables\n");
    demonstrateMemoryAddresses();
    scopeDemo();
}

void runExample4() {
    printf("\nRunning Example 4: Changing Values\n");
    demonstrateTypeConversion();
    demonstrateCasting();
}

void runExample5() {
    printf("\nRunning Example 5: Using Variables\n");
    // Include practical examples
}

void runExample6() {
    printf("\nRunning Example 6: Memory Allocation\n");
    stackMemoryDemo();
    heapMemoryDemo();
    memoryLayoutDemo();
}

void runExercise1() {
    printf("\nRunning Exercise 1: Variable Basics\n");
    // Include exercise solutions
}

void runExercise2() {
    printf("\nRunning Exercise 2: Variable Operations\n");
    // Include exercise solutions
}

void runExercise3() {
    printf("\nRunning Exercise 3: Advanced Concepts\n");
    // Include exercise solutions
}

void demonstrateAllConcepts() {
    printSeparator();
    printf("DEMONSTRATING ALL VARIABLE CONCEPTS\n");
    printSeparator();
    
    // 1. Basic Types and Sizes
    demonstrateTypeSizes();
    demonstrateTypeRanges();
    
    // 2. Memory Concepts
    demonstrateMemoryAddresses();
    stackMemoryDemo();
    heapMemoryDemo();
    memoryLayoutDemo();
    
    // 3. Type Operations
    demonstrateTypeConversion();
    demonstrateCasting();
    
    // 4. Scope and Lifetime
    scopeDemo();
    
    printSeparator();
    printf("ALL CONCEPTS DEMONSTRATED\n");
    printSeparator();
}
