#include <stdio.h>
#include <string.h>

#include "../libft/libft.h"

int main()
{
	char	s[] = "123456";	
	char	s1[] = "123456";
	char	*res = memchr(s,0, 10);
	char	*res1 = ft_memchr(s1,0, 10);
	char	*res2 = memchr(s,0, 1);
	char	*res3 = ft_memchr(s1,0, 1);
	char	*res4 = memchr(s,2, 3);
	char	*res5 = ft_memchr(s1,2, 3);
	char	*res6 = memchr(s, 6, 6);
	char	*res7 = ft_memchr(s1, 6, 6);
	
	printf("%s\n",  memchr(s,0, 10) == ft_memchr(s1, 0, 10) ? "true":"false");
	printf("%s\n",  memchr(s,0, 1) == ft_memchr(s1, 0, 1) ? "true":"false");
	printf("%s\n",  memchr(s, 2, 3) == ft_memchr(s1, 2, 3) ? "true":"false");
	printf("%s\n",  memchr(s, 6, 6) == ft_memchr(s1, 6, 6) ? "true":"false");

	printf("%s, %s\n", res, res1);
	printf("%s, %s\n", res2, res3);
	printf("%s, %s\n", res4, res5);
	printf("%s, %s\n", res6, res7);
	
	return 0;
}
