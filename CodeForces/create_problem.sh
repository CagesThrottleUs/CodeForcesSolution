#!/bin/bash

# Script to create a new CodeForces problem folder with main.cpp template

# Prompt for folder name
echo "Enter the CodeForces problem folder name (e.g., 1000A, 1001B, etc.):"
read folder_name

# Check if folder name is provided
if [ -z "$folder_name" ]; then
    echo "Error: No folder name provided."
    exit 1
fi

# Check if folder already exists
if [ -d "$folder_name" ]; then
    echo "Error: Folder '$folder_name' already exists."
    exit 1
fi

# Create the folder
mkdir "$folder_name"
if [ $? -eq 0 ]; then
    echo "Created folder: $folder_name"
else
    echo "Error: Failed to create folder '$folder_name'."
    exit 1
fi

# Create main.cpp with template
cat > "$folder_name/main.cpp" << 'EOF'
/**
 * Sort your headers here
 */
#include <iostream> // for std::cin, std::cout

/**
 * Template for fast I/O for competitive programming
 */
auto do_fast_io() -> void
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Your functions and other stuff here

/**
 * The namespace that would contain the solution to the problem piece by piece
 */
namespace Solution
{
} // namespace Solution

/**
 * Main function
 */
auto main() noexcept -> int
{
    // Fast I/O for competitive programming
    do_fast_io();

    // Your code here

    return 0;
}

EOF

if [ $? -eq 0 ]; then
    echo "Created main.cpp in $folder_name/"
    echo "Setup complete! You can now start coding in $folder_name/main.cpp"
else
    echo "Error: Failed to create main.cpp in '$folder_name'."
    exit 1
fi 