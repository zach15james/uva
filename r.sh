#!/bin/bash
# Usage: ./r.sh 1154


# NOTE: 
# have inputi.txt
# have i.cpp
# run: ./r.sh i

# makes workflow super fast


# get the prob number
PROB_NUM="$1"

# get input file name
INPUT_FILE="input${PROB_NUM}.txt"

if [ -z "$PROB_NUM" ]; then
  #echo "Usage: $0 <problem_number>"
  exit 1
fi

# Compile the C++ file
g++ -lm -lcrypt -O2 -pipe -DONLINE_JUDGE "${PROB_NUM}.cpp" -o "$PROB_NUM"
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

# Run the compiled program
# Automatically check if the corresponding input file exists
if [ -f "$INPUT_FILE" ]; then
  #echo "Running $PROB_NUM with input redirected from $INPUT_FILE..."
  "./$PROB_NUM" < "$INPUT_FILE"
else
  #echo "Running $PROB_NUM without input redirection ($INPUT_FILE not found)..."
  "./$PROB_NUM"
fi