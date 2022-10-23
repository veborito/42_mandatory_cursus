#include <string.h>
#include <stdio.h>

#include "../libft/libft.h"

int main()
{
	char c = '\0';
	char l = 'e';
	char s[] = "teste";
	char s2[] = "bonjour";

	printf("%s, %s\n", strrchr(s, l), ft_strrchr(s, l));
	printf("%s, %s\n", strrchr(s, c), ft_strrchr(s, c));
	printf("%s, %s\n", strrchr(s, 't' + 256), ft_strrchr(s, 't' + 256));
	printf("%s, %s\n", strrchr(s, 0), ft_strrchr(s, 0));
	printf("%s, %s\n", strrchr(s, 127), ft_strrchr(s, 127));
	printf("%s, %s\n", strrchr(s2 + 2, 'b'), ft_strrchr(s2 + 2, 'b'));
	printf("%s, %s\n", strrchr(s2, 'b'), ft_strrchr(s2, 'b'));
	printf("--------------------------------\n");
	printf("%s, %s\n", strrchr("\0", 8), ft_strrchr("\0", 8));

	printf("%s", strrchr(s, l) == ft_strrchr(s, l) ? "true\n":"false\n");
	printf("%s", strrchr(s, c) == ft_strrchr(s, c) ? "true\n":"false\n");
	printf("%s", strrchr(s, 't' + 256) == ft_strrchr(s, 't' + 256) ? "true\n":"false\n");
	printf("%s", strrchr(s, 0) == ft_strrchr(s, 0) ? "true\n":"false\n");
	printf("%s", strrchr(s, 127) == ft_strrchr(s, 127) ? "true\n":"false\n");
	printf("%s", strrchr(s2 + 2, 'b') == ft_strrchr(s2 + 2, 'b') ? "true\n":"false\n");
	printf("%s", strrchr(s2, 'b') == ft_strrchr(s2, 'b') ? "true\n":"false\n");
	printf("--------------------------------\n");
	printf("%s", strrchr("\0", 8) == ft_strrchr("\0", 8) ? "true\n":"false\n");

	return 0;
}


