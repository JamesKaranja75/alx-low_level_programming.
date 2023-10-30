#include "main.h"

/**
 * read_textfile - A function that reads a text file and prints it
 * to the POSIX standard output.
 * @filename: The file to read.
 * @letters: The number of letters to read and print.
 * Return: The actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t br, bw;
char *buffer;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
return (0);

br = read(fd, buffer, letters);
if (br == -1)
{
free(buffer);
close(fd);
return (0);
}

bw = write(STDOUT_FILENO, buffer, br);
if (bw == -1)
{
free(buffer);
close(fd);
return (0);
}

close(fd);
return (br);
}
