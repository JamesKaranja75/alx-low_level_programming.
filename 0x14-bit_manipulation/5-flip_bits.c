#include "main.h"

/**
 * flip_bits - A function that returns
 * the number of bits you will get from the flip
 * @n: First number
 * @m: Second number
 * Return: Number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int k, cnt = 0;
unsigned long int curr;
unsigned long int xor_result = n ^ m;

for (k = 63; k >= 0; k--)
{
curr = xor_result >> k;
if (curr & 1)
cnt++;
}
return (cnt);
}
