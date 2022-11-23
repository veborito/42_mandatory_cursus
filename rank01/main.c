#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	char *nline;
	int	 fd;

	fd = open("/Users/borito/42/rank01/get_next_line_2.0/t1.txt", O_RDWR);
	nline = get_next_line(fd);
	printf("new line : %s\n", nline);
	free(nline);
}
