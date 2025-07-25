#!/bin/bash

# Check if folder name is provided as command line argument
if [ $# -eq 1 ]; then
    folderName="$1"
else
    # Prompt for folder name if not provided as argument
    read -p "Enter the folder name containing main.cpp: " folderName
fi

# Check if the folder exists at the same level as the script
scriptDir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
folderPath="$scriptDir/$folderName"

if [ -d "$folderPath" ]; then
    # Define the path for the output executable (at the same level as the folder, but outside)
    outputExecutable="$scriptDir/a.out"

    # Compile the C++ code using the provided g++ command with the parameters
    compileCommand="clang++ -Werror -Wall -Wextra -Wconversion -O3 -std=c++20 $folderPath/main.cpp -o $outputExecutable"

    # Execute the compile command
    eval $compileCommand

    # Check if the compilation was successful
    if [ -f "$outputExecutable" ]; then
        # Display the location of the executable
        echo "Compilation successful. Executable created at: $outputExecutable"
        
        # Execute the compiled program
        echo "Executing the program..."
        echo "----------------------------------------"
        "$outputExecutable"
        echo "----------------------------------------"
        echo "Program execution completed."
    else
        echo "Compilation failed."
    fi
else
    echo "The folder '$folderName' does not exist at the expected location."
fi 