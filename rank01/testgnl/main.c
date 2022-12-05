#include "../get_next_line_2.0/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	fd;
	int	i;
	char *s;
	
	printf("start program\n");
	fd = open("/Users/borito/42/rank01/testgnl/test1.txt", O_RDONLY, S_IRUSR | S_IWUSR);
	i = 1;
	s = get_next_line(fd);
	printf("ligne %d : %s", i, s);
	return (0);
}
