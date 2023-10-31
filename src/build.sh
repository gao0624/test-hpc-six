#!/bin/bash

for file in *.c; do
  filename=$(basename "$file" .c)
  gcc -S -o "${filename}.s" "$file"
done