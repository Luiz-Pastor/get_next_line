#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;

	fd = open("test1.txt", O_RDONLY);
	printf("alo\n\n");
	printf("> %s\n", get_next_line(fd));
}