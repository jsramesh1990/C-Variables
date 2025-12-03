#!/bin/bash

# C Variables Tutorial - Compile and Run Script
# This script helps compile and run all examples and exercises

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Project directories
SRC_DIR="src"
EXAMPLES_DIR="examples"
EXERCISES_DIR="exercises"
BUILD_DIR="build"
INCLUDE_DIR="include"

# Create build directory if it doesn't exist
mkdir -p $BUILD_DIR/examples
mkdir -p $BUILD_DIR/exercises

echo -e "${BLUE}========================================${NC}"
echo -e "${GREEN}C Variables Tutorial - Build System${NC}"
echo -e "${BLUE}========================================${NC}"

# Function to compile a single file
compile_file() {
    local source_file=$1
    local output_file=$2
    local extra_flags=$3
    
    echo -e "${YELLOW}Compiling:${NC} $source_file"
    gcc -Wall -Wextra -g -I$INCLUDE_DIR $extra_flags $source_file -o $output_file
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ Success:${NC} $output_file"
        return 0
    else
        echo -e "${RED}✗ Failed:${NC} $source_file"
        return 1
    fi
}

# Function to run a compiled program
run_program() {
    local program=$1
    local description=$2
    
    echo -e "\n${BLUE}=== Running: $description ===${NC}"
    if [ -f "$program" ]; then
        ./$program
    else
        echo -e "${RED}Error: Program not found: $program${NC}"
    fi
}

# Main menu
show_menu() {
    echo -e "\n${GREEN}Select an option:${NC}"
    echo "1. Build all examples"
    echo "2. Build all exercises"
    echo "3. Build main project"
    echo "4. Build everything"
    echo "5. Run all examples"
    echo "6. Run all exercises"
    echo "7. Run specific example"
    echo "8. Run specific exercise"
    echo "9. Clean build files"
    echo "10. Exit"
    echo -n "Enter choice [1-10]: "
}

# Build all examples
build_examples() {
    echo -e "\n${BLUE}Building Examples...${NC}"
    
    for example in $EXAMPLES_DIR/*.c; do
        if [ -f "$example" ]; then
            example_name=$(basename "$example" .c)
            output_file="$BUILD_DIR/examples/$example_name"
            compile_file "$example" "$output_file"
        fi
    done
}

# Build all exercises
build_exercises() {
    echo -e "\n${BLUE}Building Exercises...${NC}"
    
    for exercise in $EXERCISES_DIR/*.c; do
        if [ -f "$exercise" ]; then
            exercise_name=$(basename "$exercise" .c)
            output_file="$BUILD_DIR/exercises/$exercise_name"
            compile_file "$exercise" "$output_file"
        fi
    done
}

# Build main project
build_main() {
    echo -e "\n${BLUE}Building Main Project...${NC}"
    compile_file "$SRC_DIR/main.c" "$BUILD_DIR/main" "$SRC_DIR/utils.c"
}

# Run all examples
run_examples() {
    echo -e "\n${BLUE}Running All Examples...${NC}"
    
    for example_bin in $BUILD_DIR/examples/*; do
        if [ -f "$example_bin" ] && [ -x "$example_bin" ]; then
            example_name=$(basename "$example_bin")
            run_program "$example_bin" "Example: $example_name"
        fi
    done
}

# Run all exercises
run_exercises() {
    echo -e "\n${BLUE}Running All Exercises...${NC}"
    
    for exercise_bin in $BUILD_DIR/exercises/*; do
        if [ -f "$exercise_bin" ] && [ -x "$exercise_bin" ]; then
            exercise_name=$(basename "$exercise_bin")
            run_program "$exercise_bin" "Exercise: $exercise_name"
        fi
    done
}

# Run specific example
run_specific_example() {
    echo -e "\n${BLUE}Available Examples:${NC}"
    ls -1 $EXAMPLES_DIR/*.c | xargs -I {} basename {} .c | nl
    
    echo -n "Enter example number: "
    read example_num
    
    examples_array=($(ls -1 $EXAMPLES_DIR/*.c | xargs -I {} basename {} .c))
    
    if [ $example_num -ge 1 ] && [ $example_num -le ${#examples_array[@]} ]; then
        example_name=${examples_array[$((example_num-1))]}
        example_bin="$BUILD_DIR/examples/$example_name"
        
        if [ -f "$example_bin" ]; then
            run_program "$example_bin" "Example: $example_name"
        else
            echo -e "${RED}Example not built. Building first...${NC}"
            compile_file "$EXAMPLES_DIR/$example_name.c" "$example_bin"
            if [ -f "$example_bin" ]; then
                run_program "$example_bin" "Example: $example_name"
            fi
        fi
    else
        echo -e "${RED}Invalid example number${NC}"
    fi
}

# Run specific exercise
run_specific_exercise() {
    echo -e "\n${BLUE}Available Exercises:${NC}"
    ls -1 $EXERCISES_DIR/*.c | xargs -I {} basename {} .c | nl
    
    echo -n "Enter exercise number: "
    read exercise_num
    
    exercises_array=($(ls -1 $EXERCISES_DIR/*.c | xargs -I {} basename {} .c))
    
    if [ $exercise_num -ge 1 ] && [ $exercise_num -le ${#exercises_array[@]} ]; then
        exercise_name=${exercises_array[$((exercise_num-1))]}
        exercise_bin="$BUILD_DIR/exercises/$exercise_name"
        
        if [ -f "$exercise_bin" ]; then
            run_program "$exercise_bin" "Exercise: $exercise_name"
        else
            echo -e "${RED}Exercise not built. Building first...${NC}"
            compile_file "$EXERCISES_DIR/$exercise_name.c" "$exercise_bin"
            if [ -f "$exercise_bin" ]; then
                run_program "$exercise_bin" "Exercise: $exercise_name"
            fi
        fi
    else
        echo -e "${RED}Invalid exercise number${NC}"
    fi
}

# Clean build files
clean_build() {
    echo -e "\n${YELLOW}Cleaning build files...${NC}"
    rm -rf $BUILD_DIR/*
    echo -e "${GREEN}Build directory cleaned${NC}"
}

# Main program loop
while true; do
    show_menu
    read choice
    
    case $choice in
        1) build_examples ;;
        2) build_exercises ;;
        3) build_main ;;
        4) 
            build_examples
            build_exercises
            build_main
            ;;
        5) run_examples ;;
        6) run_exercises ;;
        7) run_specific_example ;;
        8) run_specific_exercise ;;
        9) clean_build ;;
        10) 
            echo -e "${GREEN}Goodbye!${NC}"
            exit 0
            ;;
        *) echo -e "${RED}Invalid option${NC}" ;;
    esac
    
    echo -e "\n${BLUE}Press Enter to continue...${NC}"
    read
done
