#!/bin/bash

echo "Testing C Variables Tutorial..."
echo "================================"

# Clean first
make clean

# Build all
echo "Building all..."
make all

# Check if binaries were created
echo -e "\nChecking build results:"
echo "Examples:"
ls -la build/examples/
echo -e "\nExercises:"
ls -la build/exercises/
echo -e "\nMain:"
ls -la build/main

# Test a few examples
echo -e "\nTesting examples:"
echo "1. Basic Variables:"
./build/examples/01_basic_variables | head -20
echo -e "\n2. Variable Initialization:"
./build/examples/02_variable_initialization | head -20

echo -e "\nAll tests completed!"
