#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CLEAN='\033[0m' 

echo -e "${YELLOW}Cleaning compiled files.${CLEAN}"
rm $(find . -name "*.o")

read -rp ""