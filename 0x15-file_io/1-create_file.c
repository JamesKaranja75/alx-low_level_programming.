#include "main.h"

/**
 * create_file - A function that creates a file
 * @filename: The file to be created
 * @text_content: A NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int fd;
int count;
int result;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content)
{
for (count = 0; text_content[count]; count++)
;

result = write(fd, text_content, count);
}

if (result == -1)
{
close(fd);
return (-1);
}

close(fd);
return (1);
}
