#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"

int main() {
    printSeparator();
    printf("EXERCISE 3: ADVANCED VARIABLE CONCEPTS\n");
    printSeparator();
    
    /* Exercise Instructions:
       1. Work with dynamic memory allocation
       2. Practice with structures
       3. Work with different storage classes
       4. Solve real-world problems
    */
    
    printf("Part 1: Dynamic Memory Allocation\n");
    printf("=================================\n");
    
    // TODO 1: Dynamically allocate an array of 10 integers
    // Initialize with values 1 through 10
    // Calculate the sum
    // Free the memory
    
    
    printf("\nPart 2: Structure Operations\n");
    printf("============================\n");
    
    // TODO 2: Create a Student structure with:
    // - name (char array)
    // - age (int)
    // - gpa (float)
    // Create an instance, initialize it, and print values
    
    
    printf("\nPart 3: Storage Classes\n");
    printf("=======================\n");
    
    // TODO 3: Demonstrate different storage classes:
    // - auto (local)
    // - static
    // - register
    // - extern (simulate with global)
    // Show their behavior
    
    
    printf("\nPart 4: Type Definitions\n");
    printf("========================\n");
    
    // TODO 4: Use typedef to create:
    // - Distance (float) for distances in meters
    // - Age (int) for ages
    // - Flag (int) for boolean flags
    // Create variables using these types
    
    
    printf("\nPart 5: Enumeration Types\n");
    printf("==========================\n");
    
    // TODO 5: Create an enum for days of week
    // Create a variable of this type
    // Use switch to print day name
    
    
    printf("\nPart 6: Union Type\n");
    printf("==================\n");
    
    // TODO 6: Create a union that can hold:
    // - an integer
    // - a float
    // - a character
    // Demonstrate how they share memory
    
    
    printf("\nPart 7: Memory Management\n");
    printf("=========================\n");
    
    // TODO 7: Create a program that:
    // 1. Dynamically allocates memory for a string
    // 2. Copies a string into it
    // 3. Reallocates to make room for additional text
    // 4. Appends more text
    // 5. Frees the memory
    
    
    printf("\nPart 8: Function Pointers\n");
    printf("=========================\n");
    
    // TODO 8: Create function pointers for:
    // - A function that adds two numbers
    // - A function that multiplies two numbers
    // Use the function pointers to call the functions
    
    
    printf("\nPart 9: Command Line Arguments\n");
    printf("==============================\n");
    
    // TODO 9: Write main to accept command line arguments
    // Convert arguments to integers and calculate their sum
    // Note: For this exercise, simulate with hardcoded values
    
    
    printf("\nPart 10: Real-World Problem\n");
    printf("===========================\n");
    
    // TODO 10: Create a simple bank account system
    // Use structures to represent accounts
    // Implement functions to:
    // - Create account
    // - Deposit money
    // - Withdraw money (check balance)
    // - Display account info
    
    
    // Sample solution (comment out when implementing)
    printf("\n--- Sample Solution ---\n");
    
    // Part 1
    printf("Dynamic Memory Allocation:\n");
    int *dynamic_array = (int*)malloc(10 * sizeof(int));
    if(dynamic_array) {
        int sum = 0;
        for(int i = 0; i < 10; i++) {
            dynamic_array[i] = i + 1;
            sum += dynamic_array[i];
        }
        printf("Array: ");
        for(int i = 0; i < 10; i++) printf("%d ", dynamic_array[i]);
        printf("\nSum: %d\n", sum);
        free(dynamic_array);
        printf("Memory freed successfully\n");
    }
    
    // Part 2
    printf("\nStructure Operations:\n");
    struct Student {
        char name[50];
        int age;
        float gpa;
    };
    
    struct Student student1;
    strcpy(student1.name, "Alice Johnson");
    student1.age = 20;
    student1.gpa = 3.8;
    
    printf("Student Information:\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n", student1.gpa);
    
    // Part 3
    printf("\nStorage Classes:\n");
    
    auto int auto_var = 10;  // Default, could omit 'auto'
    static int static_var = 0;
    register int reg_var = 999;
    extern int global_usage;  // Declared in utils.h
    
    static_var++;
    global_usage++;
    
    printf("Auto variable: %d\n", auto_var);
    printf("Static variable (call count): %d\n", static_var);
    printf("Register variable: %d\n", reg_var);
    printf("Global usage counter: %d\n", global_usage);
    
    // Part 4
    printf("\nType Definitions:\n");
    typedef float Distance;
    typedef int Age;
    typedef int Flag;
    
    Distance home_to_work = 15.5;  // kilometers
    Age user_age = 25;
    Flag is_active = 1;
    
    printf("Distance to work: %.1f km\n", home_to_work);
    printf("Age: %d years\n", user_age);
    printf("Account active: %s\n", is_active ? "Yes" : "No");
    
    // Part 5
    printf("\nEnumeration Types:\n");
    enum Days {MON, TUE, WED, THU, FRI, SAT, SUN};
    enum Days today = WED;
    
    printf("Today is: ");
    switch(today) {
        case MON: printf("Monday\n"); break;
        case TUE: printf("Tuesday\n"); break;
        case WED: printf("Wednesday\n"); break;
        case THU: printf("Thursday\n"); break;
        case FRI: printf("Friday\n"); break;
        case SAT: printf("Saturday\n"); break;
        case SUN: printf("Sunday\n"); break;
    }
    
    // Part 6
    printf("\nUnion Type (shared memory):\n");
    union Data {
        int i;
        float f;
        char c;
    };
    
    union Data data;
    printf("Size of union: %zu bytes\n", sizeof(union Data));
    
    data.i = 65;
    printf("Stored as int: %d\n", data.i);
    printf("As char: %c\n", data.c);  // Same memory interpreted as char
    
    data.f = 3.14;
    printf("Stored as float: %.2f\n", data.f);
    
    // Part 7
    printf("\nMemory Management:\n");
    char *text = (char*)malloc(20 * sizeof(char));
    if(text) {
        strcpy(text, "Hello");
        printf("Original: %s\n", text);
        
        char *new_text = (char*)realloc(text, 50 * sizeof(char));
        if(new_text) {
            text = new_text;
            strcat(text, ", World! This is dynamic memory.");
            printf("After realloc: %s\n", text);
        }
        free(text);
        printf("Memory freed\n");
    }
    
    // Part 8
    printf("\nFunction Pointers:\n");
    
    // Define functions
    int add(int a, int b) { return a + b; }
    int multiply(int a, int b) { return a * b; }
    
    // Declare function pointers
    int (*operation)(int, int);
    
    // Use as adder
    operation = add;
    printf("5 + 3 = %d\n", operation(5, 3));
    
    // Use as multiplier
    operation = multiply;
    printf("5 * 3 = %d\n", operation(5, 3));
    
    // Part 9 (Simulated command line)
    printf("\nCommand Line Simulation:\n");
    {
        // Simulate: ./program 10 20 30
        int argc_sim = 4;
        char *argv_sim[] = {"program", "10", "20", "30"};
        
        int sum_args = 0;
        printf("Arguments: ");
        for(int i = 1; i < argc_sim; i++) {
            int num = atoi(argv_sim[i]);
            printf("%d ", num);
            sum_args += num;
        }
        printf("\nSum: %d\n", sum_args);
    }
    
    // Part 10
    printf("\nBank Account System:\n");
    
    typedef struct {
        int account_number;
        char name[50];
        float balance;
    } BankAccount;
    
    BankAccount account;
    account.account_number = 1001;
    strcpy(account.name, "John Smith");
    account.balance = 1000.00;
    
    printf("Account Created:\n");
    printf("Account #: %d\n", account.account_number);
    printf("Name: %s\n", account.name);
    printf("Balance: $%.2f\n", account.balance);
    
    // Deposit
    account.balance += 500.00;
    printf("After depositing $500: $%.2f\n", account.balance);
    
    // Withdraw
    if(account.balance >= 200.00) {
        account.balance -= 200.00;
        printf("After withdrawing $200: $%.2f\n", account.balance);
    } else {
        printf("Insufficient funds for withdrawal\n");
    }
    
    printSeparator();
    printf("End of Exercise 3\n");
    printSeparator();
    
    return 0;
}
