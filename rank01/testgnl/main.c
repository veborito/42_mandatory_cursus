#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	fd;
	int	i;
	char *s;
	
	fd = open("/Users/borito/42/rank01/testgnl/test.txt", O_RDONLY, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (1);
	}
	i = 1;
	s = get_next_line(fd);
	printf("ligne %d : %s", i, s);
	free(s);
	while (1)
	{
		s = get_next_line(fd);
		i++;
		if (s == NULL)
			break;
		printf("ligne %d : %s", i, s);
		free(s);
	}
	return (0);
}
