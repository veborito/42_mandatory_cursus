#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libft/libft.h"

int main()
{
	char dst[0];
	char dst1[0];
	int	x, y;
	x = strlcat(dst, "Salut", 0);
	y = ft_strlcat(dst1, "Salut", 0);
	printf("strlcat: %s ft_strlcat: %s\n %d %d\n", dst, dst1, x, y);
	
	char dst2[30] = "Salut, ";
	char dst3[30] = "Salut, ";
	int	x1, y1;
	x1 = strlcat(dst2, "Boris", 15 );
	y1 = ft_strlcat(dst3, "Boris", 15);
	printf("strlcat: %s ft_strlcat: %s\n %d %d\n", dst2, dst3, x1, y1);
	
	char dst4[10] = "Salut, ";
	char dst5[10] = "Salut, ";
	int	x2, y2;
	x2 = strlcat(dst4, "Boris", 5 );
	y2 = ft_strlcat(dst5, "Boris", 5);
	printf("strlcat: %s ft_strlcat: %s\n %d %d\n", dst4, dst5, x2, y2);
	
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[60] = "there is no stars in the sky";
	char buff2[60] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + strlen("there is no stars in the sky");	
	size_t x3,y3;
	x3 = strlcat(buff1, str, max);
	y3 = ft_strlcat(buff2, str, max);
	printf("strlcat: %s ft_strlcat: %s\n %zu %zu\n", buff1, buff2, x3, y3);
		
	char *str1 = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff3[60] = "there is no stars in the sky";
	char buff4[60] = "there is no stars in the sky";
	size_t max1 = 0;	
	size_t x4,y4;
	x4 = strlcat(buff3, str1, max1);
	y4 = ft_strlcat(buff4, str1, max1);
	printf("%zu\n", max1);
	printf("%zu\n", strlen(buff3));
	printf("%zu\n", strlen(buff4));
	printf("strlcat: %s ft_strlcat: %s\n %zu %zu\n", buff3, buff4, x4, y4);
	return 0;
}
