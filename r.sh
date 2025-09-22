#!/bin/bash
# run.sh — compile and run UVA-style C++ files
# Usage: ./run.sh 1154

# Get the problem number (first argument)
PROB_NUM="$1"

# Toggle this if you want to automatically redirect from input.txt
USE_INPUT=true

# Check that a number was provided
if [ -z "$PROB_NUM" ]; then
  #echo "Usage: $0 <problem_number>"
  exit 1
fi

# Compile the C++ file with optimization and C++17 standard
g++ -Wall -O2 -std=c++17 "${PROB_NUM}.cpp" -o "$PROB_NUM"
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

# Run the compiled program
if [ "$USE_INPUT" = true ] && [ -f input.txt ]; then
  #echo "Running $PROB_NUM with input redirected from input.txt..."
  "./$PROB_NUM" < input.txt
else
  #echo "Running $PROB_NUM without input redirection..."
  "./$PROB_NUM"
fi
