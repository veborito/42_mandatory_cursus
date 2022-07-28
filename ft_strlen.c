#include <string.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int	i = 1;
		while (av[i])
		{
			printf("lenght of %s: %lu\n", av[i], ft_strlen(av[i]));
			i++;
		}
	}
	return (0);
}
