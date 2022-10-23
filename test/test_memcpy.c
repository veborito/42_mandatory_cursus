#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libft.h"

int main()
{
	char str[100];
	char str1[100];
	char src[] = "boris est trop beau";
	
	memcpy(str, src, 15);
	ft_memcpy(str1, src, 15);
	
	printf("%s %s\n", str, str1);

	return	0;
}
