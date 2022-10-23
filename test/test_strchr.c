#include <string.h>
#include <stdio.h>

#include "../libft/libft.h"

int main()
{
	char c = '\0';
	char l = 'e';
	char s[] = "teste";
	char s2[] = "bonjour";
	
	printf("%s, %s\n", strchr(s, l), ft_strchr(s, l));
	printf("%s, %s\n", strchr(s, c), ft_strchr(s, c));
	printf("%s, %s\n", strchr(s, 't' + 256), ft_strchr(s, 't' + 256));
	printf("%s, %s\n", strchr(s, 0), ft_strchr(s, 0));
	printf("%s, %s\n", strchr(s, 127), ft_strchr(s, 127));
	printf("%s, %s\n", strchr(s2 + 2, 'b'), ft_strchr(s2 + 2, 'b'));

	printf("%s", strchr(s, l) == ft_strchr(s, l) ? "true\n":"false\n");
	printf("%s", strchr(s, c) == ft_strchr(s, c) ? "true\n":"false\n");
	printf("%s", strchr(s, 't' + 256) == ft_strchr(s, 't' + 256) ? "true\n":"false\n");
	printf("%s", strchr(s, 0) == ft_strchr(s, 0) ? "true\n":"false\n");
	printf("%s", strchr(s, 127) == ft_strchr(s, 127) ? "true\n":"false\n");
	printf("%s", strchr(s2 + 2, 'b') == ft_strchr(s2 + 2, 'b') ? "true\n":"false\n");
	
	int i = 127;

	while (i < 500)
	{
		printf("%s, %d\n", strchr(s, i) == ft_strchr(s, i) ? "true":"false", i);
		i++;
	}

	return 0;
}

