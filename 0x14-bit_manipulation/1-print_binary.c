#include "main.h"
/**
 * print_binary - Prints the binary representation of a number
 * @n: Number to be printed
 */
void print_binary(unsigned long int n)
{
int i;
unsigned long int curr;
int cnt = 0;
for (i = 63; i >= 0; i--)
{
curr = n >> i;
if (curr & 1)
{
_putchar('1');
cnt++;
}
else if (cnt)
_putchar('0');
}
if (!cnt)
_putchar('0');
}
