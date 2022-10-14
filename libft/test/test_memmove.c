#include <string.h>
#include <stdio.h>

#include "../libft.h"

int main()
{
	char	str[] = "Salut Les Amiis";
	char	*str1, *str2;

	str1 = str;
	str2 = str;
	if (memmove(str1, str1 + 10, sizeof(char) * 5) == ft_memmove(str2, str2 + 10, sizeof(char) * 5))
	{
		printf("\033[0;32m");
		printf("C'est tout bon chacal!\n");
	}
	printf("memmove: %s\n", str1);
	printf("mon memmove: %s\n", str2);
	return 0;
}
