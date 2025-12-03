# Makefile for C Variables Tutorial
# Working version with -lm flag

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I./include
LDFLAGS = -lm  # Math library for pow() function

# Directories
BUILD_DIR = build

# Default target
all: dirs examples exercises main

# Create directories
dirs:
	mkdir -p $(BUILD_DIR)/examples
	mkdir -p $(BUILD_DIR)/exercises

# Build all examples
examples: dirs
	for file in examples/*.c; do \
		name=$$(basename $$file .c); \
		echo "Compiling $$name..."; \
		gcc $(CFLAGS) $$file src/utils.c $(LDFLAGS) -o $(BUILD_DIR)/examples/$$name; \
	done

# Build all exercises
exercises: dirs
	for file in exercises/*.c; do \
		name=$$(basename $$file .c); \
		echo "Compiling $$name..."; \
		gcc $(CFLAGS) $$file src/utils.c $(LDFLAGS) -o $(BUILD_DIR)/exercises/$$name; \
	done

# Build main project
main: dirs
	gcc $(CFLAGS) src/main.c src/utils.c $(LDFLAGS) -o $(BUILD_DIR)/main

# Run all examples
run: examples
	@echo "Running all examples..."
	@for exe in $(BUILD_DIR)/examples/*; do \
		if [ -x $$exe ]; then \
			echo ""; \
			echo "=== Running $$(basename $$exe) ==="; \
			$$exe; \
		fi; \
	done

# Run all exercises
run-exercises: exercises
	@echo "Running all exercises..."
	@for exe in $(BUILD_DIR)/exercises/*; do \
		if [ -x $$exe ]; then \
			echo ""; \
			echo "=== Running $$(basename $$exe) ==="; \
			$$exe; \
		fi; \
	done

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all dirs examples exercises main run run-exercises clean
