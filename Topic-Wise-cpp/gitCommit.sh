#!/bin/bash
# Example -- ./gitCommit.sh Trees/GenerateTree_Ino_Post.cpp

# Check if the filename argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <file_name>"
    exit 1
fi

# Get the filename from the first argument
file_name="$1"
file="$1"



# echo "File name: $file_name"

# Remove file extension and folder names
file_name=$(basename "$file_name")
file_name=${file_name%.*}

# echo "File name: $file_name"
# echo "File : $file"

# Set the commit message to the file name
git commit -m "$file_name" "$file"
# echo "commit -m $file_name $file"
