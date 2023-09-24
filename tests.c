#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

#define DEFAULT_FILE "test1.txt"

void	my_wait(void)
{
	char str[255];
	// FILE *file = fopen(stdin, "r");
	fgets(str, 254, stdin);
}

int main(int argc, char *argv[])
{
	int	fd;
	char *line;
	char *filename;

	char *aux = (char *) malloc(1);
	aux[0] = '\0';
	line = aux;

	if (argc < 2)
		filename = DEFAULT_FILE;
	else
		filename = argv[1];

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (printf("No file\n"), 1);
	// line = get_next_line(fd);
	// printf("\t> Linea 1:\n");
	// printf("%s\n", line);

	// line = get_next_line(fd);
	// printf("\t> Linea 2:\n");
	// printf("%s\n", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s\n", line);
		my_wait();
	}
}