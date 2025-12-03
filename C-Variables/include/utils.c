/**
 * Utility functions implementation
 */

#include <stdio.h>
#include <string.h>
#include "utils.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_separator() {
    printf("========================================\n");
}

int get_integer_input(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        clear_input_buffer();
        printf("Invalid input. Please enter an integer: ");
    }
    clear_input_buffer();
    return value;
}

float get_float_input(const char* prompt) {
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1) {
        clear_input_buffer();
        printf("Invalid input. Please enter a number: ");
    }
    clear_input_buffer();
    return value;
}

char get_char_input(const char* prompt) {
    char value;
    printf("%s", prompt);
    while (scanf(" %c", &value) != 1) {
        clear_input_buffer();
        printf("Invalid input. Please enter a character: ");
    }
    clear_input_buffer();
    return value;
}

void printSeparator() {
    printf("\n========================================\n");
}

void printSection(const char* title) {
    printf("\n%s\n", title);
    for(int i = 0; i < strlen(title); i++) printf("=");
    printf("\n");
}

void printVariableInfo(const char* name, void* address, size_t size, const char* type) {
    printf("%-15s: Address = %p, Size = %zu bytes, Type = %s\n", 
           name, address, size, type);
}

void demonstrateTypeSizes() {
    printSection("Data Type Sizes");
    
    printf("char           : %zu byte\n", sizeof(char));
    printf("short          : %zu bytes\n", sizeof(short));
    printf("int            : %zu bytes\n", sizeof(int));
    printf("long           : %zu bytes\n", sizeof(long));
    printf("long long      : %zu bytes\n", sizeof(long long));
    printf("float          : %zu bytes\n", sizeof(float));
    printf("double         : %zu bytes\n", sizeof(double));
    printf("long double    : %zu bytes\n", sizeof(long double));
}

void demonstrateTypeRanges() {
    printSection("Data Type Ranges");

 }

