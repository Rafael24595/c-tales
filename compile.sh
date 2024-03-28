#!/bin/bash

executable_name="Main"
if [ -n "$1" ]; then
    executable_name="$1"
fi

echo "Compiling project files:"
find . -name "*.c" | while read -r file; do
    echo "- "$file""
    gcc -c "$file" -o "${file%.c}.o"
done

echo "Building executable file '"$executable_name"'."
gcc -o "$executable_name" $(find . -name "*.o")

echo "Cleaning compiled files."
rm $(find . -name "*.o")

read -rp "Compilling was finished succesfully..."