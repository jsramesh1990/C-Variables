#include <stdio.h>
#include <math.h>
#include "../include/utils.h"

// Function prototypes
void calculateCircleArea(float radius);
void temperatureConversion(float celsius);
void demonstrateTypePromotion();
void demonstrateStorageClasses();

// Global variable
int global_usage = 0;

int main() {
    printSeparator();
    printf("EXAMPLE 5: USING VARIABLES IN PRACTICE\n");
    printSeparator();
    
    // 1. Mathematical Calculations
    printSection("1. Mathematical Calculations");
    
    float length = 10.5, width = 5.3;
    float area = length * width;
    float perimeter = 2 * (length + width);
    
    printf("Rectangle Dimensions:\n");
    printf("Length: %.2f, Width: %.2f\n", length, width);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
    
    // 2. Scientific Calculation
    printSection("2. Scientific Calculation");
    
    calculateCircleArea(7.0);
    
    // 3. Temperature Conversion
    printSection("3. Temperature Conversion");
    
    temperatureConversion(25.0);  // 25°C to Fahrenheit
    
    // 4. Financial Calculation
    printSection("4. Financial Calculation");
    
    float principal = 1000.0;
    float rate = 5.0;  // 5% annual interest
    int time = 3;      // 3 years
    
    float simple_interest = (principal * rate * time) / 100;
    float compound_interest = principal * pow(1 + rate/100, time) - principal;
    float total_amount = principal + compound_interest;
    
    printf("Principal: $%.2f\n", principal);
    printf("Rate: %.1f%%\n", rate);
    printf("Time: %d years\n", time);
    printf("Simple Interest: $%.2f\n", simple_interest);
    printf("Compound Interest: $%.2f\n", compound_interest);
    printf("Total Amount: $%.2f\n", total_amount);
    
    // 5. String Manipulation
    printSection("5. String Manipulation");
    
    char first_name[] = "John";
    char last_name[] = "Doe";
    char full_name[50];
    
    // Build full name
    int i = 0, j = 0;
    
    // Copy first name
    while(first_name[i] != '\0') {
        full_name[j] = first_name[i];
        i++;
        j++;
    }
    
    // Add space
    full_name[j] = ' ';
    j++;
    
    // Copy last name
    i = 0;
    while(last_name[i] != '\0') {
        full_name[j] = last_name[i];
        i++;
        j++;
    }
    
    // Null terminator
    full_name[j] = '\0';
    
    printf("First Name: %s\n", first_name);
    printf("Last Name: %s\n", last_name);
    printf("Full Name: %s\n", full_name);
    
    // 6. Counter and Accumulator Pattern
    printSection("6. Counter and Accumulator Pattern");
    
    int scores[] = {85, 92, 78, 90, 88};
    int n = sizeof(scores) / sizeof(scores[0]);
    int total_score = 0;
    int highest = scores[0];
    int lowest = scores[0];
    
    for(int i = 0; i < n; i++) {
        total_score += scores[i];  // Accumulator
        
        if(scores[i] > highest) {
            highest = scores[i];  // Update highest
        }
        
        if(scores[i] < lowest) {
            lowest = scores[i];   // Update lowest
        }
    }
    
    float average_score = (float)total_score / n;
    
    printf("Scores: ");
    for(int i = 0; i < n; i++) printf("%d ", scores[i]);
    printf("\n");
    printf("Total: %d\n", total_score);
    printf("Average: %.2f\n", average_score);
    printf("Highest: %d\n", highest);
    printf("Lowest: %d\n", lowest);
    
    // 7. Type Promotion and Demotion
    demonstrateTypePromotion();
    
    // 8. Storage Classes in Practice
    demonstrateStorageClasses();
    
    // 9. Using Variables in Control Flow
    printSection("9. Variables in Control Flow");
    
    int user_age = 20;
    int has_license = 1;
    int has_insurance = 0;
    
    printf("Age: %d, License: %s, Insurance: %s\n",
           user_age,
           has_license ? "Yes" : "No",
           has_insurance ? "Yes" : "No");
    
    if(user_age >= 18 && has_license) {
        printf("Can drive");
        if(!has_insurance) {
            printf(", but needs insurance!\n");
        } else {
            printf(" legally.\n");
        }
    } else {
        printf("Cannot drive.\n");
    }
    
    // 10. Bit Manipulation
    printSection("10. Bit Manipulation with Variables");
    
    unsigned int flags = 0;  // All bits cleared
    
    // Set specific bits (using bit positions 0, 2, 3)
    flags |= (1 << 0);  // Set bit 0
    flags |= (1 << 2);  // Set bit 2
    flags |= (1 << 3);  // Set bit 3
    
    printf("Flags value: %u (binary: ", flags);
    
    // Print binary representation
    for(int i = 7; i >= 0; i--) {
        printf("%d", (flags >> i) & 1);
        if(i == 4) printf(" ");  // Add space for readability
    }
    printf(")\n");
    
    // Check if bit 2 is set
    if(flags & (1 << 2)) {
        printf("Bit 2 is SET\n");
    }
    
    // Clear bit 3
    flags &= ~(1 << 3);
    printf("After clearing bit 3: %u\n", flags);
    
    // 11. Using Variables with Functions
    printSection("11. Variables with Functions");
    
    int num1 = 15, num2 = 4;
    
    // Pass by value
    printf("Before function: num1=%d, num2=%d\n", num1, num2);
    swapByValue(num1, num2);
    printf("After swapByValue: num1=%d, num2=%d (unchanged)\n", num1, num2);
    
    // 12. Constants in Practice
    printSection("12. Using Constants");
    
    const int MAX_USERS = 100;
    const float TAX_RATE = 0.08;
    const char* COMPANY_NAME = "TechCorp";
    
    float purchase_amount = 125.50;
    float tax_amount = purchase_amount * TAX_RATE;
    float total_cost = purchase_amount + tax_amount;
    
    printf("Company: %s\n", COMPANY_NAME);
    printf("Purchase: $%.2f\n", purchase_amount);
    printf("Tax (%.0f%%): $%.2f\n", TAX_RATE * 100, tax_amount);
    printf("Total: $%.2f\n", total_cost);
    printf("Maximum users allowed: %d\n", MAX_USERS);
    
    printSeparator();
    printf("End of Using Variables Example\n");
    printSeparator();
    
    return 0;
}

void calculateCircleArea(float radius) {
    const float PI = 3.14159;
    float area = PI * radius * radius;
    float circumference = 2 * PI * radius;
    
    printf("Circle with radius %.2f:\n", radius);
    printf("Area: %.2f\n", area);
    printf("Circumference: %.2f\n", circumference);
}

void temperatureConversion(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    float kelvin = celsius + 273.15;
    
    printf("Temperature Conversions:\n");
    printf("Celsius: %.2f°C\n", celsius);
    printf("Fahrenheit: %.2f°F\n", fahrenheit);
    printf("Kelvin: %.2fK\n", kelvin);
}

void demonstrateTypePromotion() {
    printSection("7. Type Promotion in Expressions");
    
    char c = 'A';        // ASCII 65
    short s = 100;
    int i = 1000;
    float f = 3.14;
    double d = 2.71828;
    
    // Automatic promotions in expressions
    double result1 = c + s;      // char and short promoted to int
    double result2 = i + f;      // int promoted to float
    double result3 = f + d;      // float promoted to double
    
    printf("char 'A' (%d) + short 100 = %.2f\n", c, result1);
    printf("int 1000 + float 3.14 = %.2f\n", result2);
    printf("float 3.14 + double 2.71828 = %.5f\n", result3);
    
    // Explicit demotion (casting)
    int truncated = (int)d;
    printf("Explicit demotion: (int)%.5f = %d (truncated)\n", d, truncated);
}

void demonstrateStorageClasses() {
    printSection("8. Storage Classes in Practice");
    
    // Automatic (local) - default
    auto int auto_var = 10;
    
    // Static - persists between calls
    static int static_var = 0;
    static_var++;
    
    // Register - hint to compiler
    register int reg_var = 999;
    
    printf("Auto variable: %d\n", auto_var);
    printf("Static variable (call count): %d\n", static_var);
    printf("Register variable: %d\n", reg_var);
}

// Function demonstrating pass by value
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue: a=%d, b=%d\n", a, b);
}
