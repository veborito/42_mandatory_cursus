#include <stdio.h>
#include <string.h>

#include "../libft/libft.h"

int main()
{
	char s1[] = "Salut comment vas-tu?";
	char *s2 = "";
	char *s3 = "a";
	char *str = strdup("0123456789");

	printf("Expected: Salut comment va? , result: %s\n", ft_substr(s1, 0, strlen(s1)));
	printf("Expected:  comme , result: %s\n", ft_substr(s1, 5, 11));
	printf("Expected: ? , result: %s\n", ft_substr(s1, 20, 1));
	printf("Expected: S , result: %s\n", ft_substr(s1, 0, 1));
	printf("Expected: , result: %s\n", ft_substr(s1, 0, 0));
	printf("Expected: , result: %s\n", ft_substr(s1, 12, 0));
	printf("Expected: , result: %s\n", ft_substr(s2, 0, 1));
	printf("Expected: , result: %s\n", ft_substr(s2, 0, 0));
	printf("Expected: , result: %s\n", ft_substr(s3, 1, 1));
	printf("Expected: , result: %s\n", ft_substr(s1, strlen(s1) + 5, 20));
	printf("Expected: 9 , result: %s\n", ft_substr(str, 9, 10));
	printf("Expected: 23456789 , result: %s\n", ft_substr(str, 2, 10));
	printf("Expected: 0123456789 , result: %s\n", ft_substr(str, 0, -1));
	printf("Expected: , result: %s\n", ft_substr(str, 10, 10));
	return 0;
}
