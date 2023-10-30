#include "main.h"
#include <stdio.h>
#define BUF_SIZE 1024

/**
 * error_98 - checks error 98
 * @file1: file to check
 * @buffer: the buffer
 * @argv: arguments
 */
void error_98(int file1, char *buffer, char *argv);

/**
 * error_99 - checks error 99
 * @file1: file to check
 * @buffer: buffer
 * @argv: arguments
 */
void error_99(int file1, char *buffer, char *argv);

/**
 * error_100 - checks error 100
 * @file1: file to check
 * @buffer: buffer
 */
void error_100(int file1, char *buffer);

/**
 * main - Copies the contents of one file to another.
 * @argc: Number of arguments.
 * @argv: A pointer to an array of arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
int file1, file2, result1, result2;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = malloc(sizeof(char) * BUF_SIZE);
if (!buffer)
return (0);
file2 = open(argv[1], O_RDONLY);
error_98(file2, buffer, argv[1]);

file1 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
error_99(file1, buffer, argv[2]);

do {
result1 = read(file2, buffer, BUF_SIZE);
if (result1 == 0)
break;

error_98(result1, buffer, argv[1]);

result2 = write(file1, buffer, result1);
error_99(result2, buffer, argv[2]);
} while (result2 >= BUF_SIZE);

result1 = close(file1);
error_100(result1, buffer);

result1 = close(file2);
error_100(result1, buffer);

free(buffer);
return (0);
}

/**
 * error_98 - checks error 98
 * @file1: file to check
 * @buffer: the buffer
 * @argv: arguments
 */
void error_98(int file1, char *buffer, char *argv)
{
if (file1 < 0)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv);
free(buffer);
exit(98);
}
}

/**
 * error_99 - checks error 99
 * @file1: file to check
 * @buffer: buffer
 * @argv: arguments
 */
void error_99(int file1, char *buffer, char *argv)
{
if (file1 < 0)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv);
free(buffer);
exit(99);
}
}

/**
 * error_100 - checks error 100
 * @file1: file to check
 * @buffer: buffer
 */
void error_100(int file1, char *buffer)
{
if (file1 < 0)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file1);
free(buffer);
exit(100);
}
}
