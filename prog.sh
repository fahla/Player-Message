

#!/bin/bash

# Get the current directory
current_dir=$(pwd)

# Print the current directory
echo "Current directory: $current_dir"

# Navigate to the directory of your CMake project
cd $current_dir

# Create a build directory 
mkdir -p build

# Navigate to the build directory
cd build

# Generate build files using CMake
cmake ..

# Build the project
make

# Execute the program if build was successful
if [ $? -eq 0 ]; then
    ./CMakeProject3	
else
    echo "Build failed. Check for errors."
fi

#Remove build dir
cd ..
rm -rf build

read -p "Press Enter to exit"