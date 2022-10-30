#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"

int main()
{
	int	fd;

	fd = open("TEST4", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (1);
	}
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(10, fd);
	ft_putchar_fd('\n', fd);
	if(close(fd) == -1)
	{
		printf("ERROR\n");
		return (1);
	}
	return (0);
}

