#include <stdlib.h>

int main()
{
	int *p = malloc(sizeof(int) * 10);
	int	i = 0;

	while (i < 10)
	{
		p[i] = p[i - 1] + 3;
		i++;
	}
	return (0);
}
