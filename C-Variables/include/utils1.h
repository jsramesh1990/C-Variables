/**
 * Utility functions header
 */

#ifndef UTILS_H
#define UTILS_H

// Clear input buffer
void clear_input_buffer();

// Print separator line
void print_separator();

// Get integer input with validation
int get_integer_input(const char* prompt);

// Get float input with validation
float get_float_input(const char* prompt);

// Get character input with validation
char get_char_input(const char* prompt);

#endif
