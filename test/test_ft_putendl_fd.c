#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"

int main()
{
	int	fd;

	fd = open("TEST3", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (1);
	}
	ft_putendl_fd("Je suis le roi du monde", fd);
	if(close(fd) == -1)
	{
		printf("ERROR\n");
		return (1);
	}
	return (0);
}

