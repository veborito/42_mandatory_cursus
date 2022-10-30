#include <stdio.h>
#include <string.h>

#include "../libft/libft.h"

int main()
{
	char s1[] = "hola";
	char *s2 = "";
	char *s3 = "a";
	char *str = strdup("0123456789");

	printf("Expected: hola , result: %s\n", ft_substr(s1, 0, strlen(s1)));
	printf("Expected: la , result: %s\n", ft_substr(s1, 2, 4));
	printf("Expected:  , result: %s\n", ft_substr(s1, 20, 1));
	printf("Expected: h , result: %s\n", ft_substr(s1, 0, 1));
	printf("Expected: , result: %s\n", ft_substr(s1, 0, 0));
	printf("Expected: , result: %s\n", ft_substr(s1, 12, 0));
	printf("Expected: , result: %s\n", ft_substr(s2, 0, 1));
	printf("Expected: , result: %s\n", ft_substr(s3, 1, 1));
	printf("Expected: , result: %s\n", ft_substr(s1, strlen(s1) + 5, 20));
	printf("Expected: 9 , result: %s\n", ft_substr(str, 9, 10));
	printf("Expected: 23456789 , result: %s\n", ft_substr(str, 2, 10));
	printf("Expected: 0123456789 , result: %s\n", ft_substr(str, 0, -1));
	printf("Expected: , result: %s\n", ft_substr(str, 10, 10));
	printf("--------------------------------------------------\n");
	printf("Expected: , result: %s\n", ft_substr("hola", -1, 0));
	printf("Expected: , result: %s\n", ft_substr("", 1, 1));
	printf("Expected: hola , result: %s\n", ft_substr("hola", 0, -1));
	printf("Expected: , result: %s\n", ft_substr("hola", -1, -1));
	printf("Expected: , result: %s\n", ft_substr("hola", 0, 0));
	printf("Expected: h , result: %s\n", ft_substr("hola", 0, 1));
	printf("Expected: hol , result: %s\n", ft_substr("hola", 0, 3));
	printf("Expected: hola , result: %s\n", ft_substr("hola", 0, 4));
	printf("Expected: hola , result: %s\n", ft_substr("hola", 0, 5));
	printf("Expected: , result: %s\n", ft_substr("hola", 2, 0));
	printf("--------------------------------------------------\n");
	printf("Expected: l , result: %s\n", ft_substr("hola", 2, 1));
	printf("Expected: la , result: %s\n", ft_substr("hola", 2, 2));
	printf("Expected: la , result: %s\n", ft_substr("hola", 2, 3));
	printf("Expected: la , result: %s\n", ft_substr("hola", 2, 30));
	printf("Expected: , result: %s\n", ft_substr("hola", 3, 0));
	printf("Expected: a , result: %s\n", ft_substr("hola", 3, 1));
	printf("Expected: a , result: %s\n", ft_substr("hola", 3, 2));
	printf("Expected: , result: %s\n", ft_substr("hola", 4, 0));
	printf("Expected: , result: %s\n", ft_substr("hola", 4, 1));
	printf("Expected: , result: %s\n", ft_substr("hola", 4, 20));
	printf("Expected: , result: %s\n", ft_substr("hola", 5, 2));
	return 0;
}
