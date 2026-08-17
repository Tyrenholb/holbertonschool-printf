# _printf

This project is a custom version of the C `printf` function.

It handles different format specifiers and prints output to standard output while returning the number of characters printed.

## Supported Specifiers

* `%c` - character
* `%s` - string
* `%d` - decimal integer
* `%i` - integer
* `%%` - percent sign

## Compilation

Compile all files with:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf


Run with:
./printf


Files

The project is split into separate files for `_printf` and the functions used to handle each format specifier.
