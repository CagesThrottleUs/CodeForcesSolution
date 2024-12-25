# Prompt for folder name
$folderName = Read-Host "Enter the folder name containing main.cpp"

# Check if the folder exists at the same level as the script
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$folderPath = Join-Path $scriptDir $folderName

if (Test-Path $folderPath) {
    # Define the path for the output executable (at the same level as the folder, but outside)
    $outputExecutable = Join-Path $scriptDir "a.exe"

    # Compile the C++ code using the provided g++ command with the parameters
    $compileCommand = "g++ -Wall -Wextra -Wconversion -static -O2 -std=c++20 $folderPath\main.cpp -o $outputExecutable"

    # Execute the compile command
    $compileResult = Invoke-Expression $compileCommand

    # Check if the compilation was successful
    if (Test-Path $outputExecutable) {
        # Display the location of the executable
        Write-Host "Compilation successful. Executable created at: $outputExecutable"
    } else {
        Write-Host "Compilation failed."
    }
} else {
    Write-Host "The folder '$folderName' does not exist at the expected location."
}
