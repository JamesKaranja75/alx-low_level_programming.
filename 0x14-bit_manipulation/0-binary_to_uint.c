#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an nsigned int
 * @b: Points to a string of 0 and 1 chars
 *
 * Return: the converted number,
 * or 0 if b is NULL or contains non-binary chars
 */
unsigned int binary_to_uint(const char *b)
{
int n;
unsigned int num = 0;

if (!b)
return (0);

for (n = 0; b[n]; n++)
{
if (b[n] < '0' || b[n] > '1')
return (0);
num = 2 * num + (b[n] - '0');
}
return (num);
}
