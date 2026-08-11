#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    /* void *addr; */
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    /* addr = (void *)0x7ffe637541f0; */
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Progress: 100%% complete\n\n");

    printf("\n\n\n\n");
    /* test mains for now*/
   
    printf("[%d]\n", len);
    _printf("[%d]\n", len); 
    printf("[%d]\n", -45213213);
    _printf("[%d]\n", -45213213); 

     printf("[%d]\n", 0);
    _printf("[%d]\n", 0); 

     _printf("Postuve:[%d]\n", 762534);
    printf("Postuve:[%d]\n", 762534);

    return(0);
}

/* %u is the format specifier for an unsigned decimal integer - postive or zero ints only. */
/* %d is a format specifier used as a placeholder for a signed decimal integer. */
/* %i = for specifiier used to represent a single integer */
/* %s is a format specifier used to represent text strings */
/* %x is a format specifier used to print or read unsigned integers in hexadecimal (base-16) format using lowercase letters */
/* %p format specifier is used within input/output functions like printf() and scanf() to print or read raw memory addresses */
