#include <stdio.h>
#include <string.h>

#include "../libft.h"

int main()
{
	const char *h1 = "Je m'appelle Boris Verdecia Echarte";
	const char *h2 = "";
	const char *h3 = "Boris";
	const char *n1 = "Boris";
	const char *n2 = "";
	const char *n3 = " ";
	const char *n4 = "Salutations";
	const char *n5 = "Boris Verdecia Echarte";

	printf("%s, %s\n", strnstr(h1, n1, 30), ft_strnstr(h1, n1, 30));
	printf("%s, %s\n", strnstr(h1, n1, 3), ft_strnstr(h1, n1, 3));
	printf("%s, %s\n", strnstr(h1, n2, 30), ft_strnstr(h1, n2, 30));
	printf("%s, %s\n", strnstr(h1, n2, 10), ft_strnstr(h1, n2, 10));
	printf("%s, %s\n", strnstr(h1, n3, 30), ft_strnstr(h1, n3, 30));
	printf("%s, %s\n", strnstr(h1, n4, 30), ft_strnstr(h1, n4, 30));
	printf("%s, %s\n", strnstr(h2, n1, 10), ft_strnstr(h2, n1, 10));
	printf("%s, %s\n", strnstr(h2, n2, 10), ft_strnstr(h2, n2, 10));
	printf("%s, %s\n", strnstr(h3, n5, 30), ft_strnstr(h3, n5, 30));
	printf("%s, %s\n", strnstr(h3, n1, 5), ft_strnstr(h3, n1, 5));
	printf("%s, %s\n", strnstr(h3, n1, 10), ft_strnstr(h3, n1, 10));
	printf("%s, %s\n", strnstr(h2, n2, 0), ft_strnstr(h2, n2, 0));
	
	return 0;
}
