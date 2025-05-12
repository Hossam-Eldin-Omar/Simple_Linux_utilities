# Simple Linux Utilities

This repository contains simple implementations of common Linux command-line utilities. Each utility is written for educational purposes, showcasing basic file handling and system operations in C.

## Utilities

- **copy**  
  A simplified version of the `cp` command. It copies the contents of one file to another.

- **cat**  
  Displays the contents of a file on the terminal, similar to the standard `cat` command.

- **mv**  
  Moves or renames files, mimicking the behavior of the `mv` command.

- **pwd**  
  Prints the current working directory path.

- **echo**  
  Prints a message or string to the terminal.

## How to Compile

Use `gcc` to compile any utility. For example:
```bash
gcc -o copy copy.c
./copy source.txt destination.txt
