#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CLEAN='\033[0m' 

executable_name="Main"
if [ -n "$1" ]; then
    executable_name="$1"
fi

echo -e "${YELLOW}Compiling project files:${CLEAN}"
find . -name "*.c" | while read -r file; do
    echo -e "${GREEN}  - "$file"${CLEAN}"
    gcc -c "$file" -o "${file%.c}.o"
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation failed for $file${CLEAN}\n"
        exit 1
    fi
done

if [ $? -ne 0 ]; then
    read -rp ""
    exit 1
fi

echo -e "\n${YELLOW}Building executable file '"$executable_name"'.${CLEAN}"
gcc -o "$executable_name" $(find . -name "*.o")

if [ $? -ne 0 ]; then
    echo -e "${RED}Linking failed for '"$executable_name"'${CLEAN}\n"
    read -rp ""
    exit 1
fi

echo -e "\n${YELLOW}Cleaning compiled files.${CLEAN}"
rm $(find . -name "*.o")

echo -e "\n${GREEN}Compilling was finished succesfully.${CLEAN}"

read -rp ""