#include <stdio.h>
#include <string.h>

#include "../libft.h"

int main()
{
	char s1[] = "Salut comment vas-tu?";
	char *s2 = "";
	char *s3 = "a";

	printf("Expected: Salut comment vas-tu? , result: %s\n", ft_substr(s1, 0, strlen(s1)));
	printf("Expected:  comme , result: %s\n", ft_substr(s1, 5, 11));
	printf("Expected: ? , result: %s\n", ft_substr(s1, 20, 1));
	printf("Expected: S , result: %s\n", ft_substr(s1, 0, 1));
	printf("Expected: (null) , result: %s\n", ft_substr(s1, 0, 0));
	printf("Expected: (null) , result: %s\n", ft_substr(s1, 12, 0));
	printf("Expected:  , result: %s\n", ft_substr(s2, 0, 1));
	printf("Expected: (null)  , result: %s\n", ft_substr(s2, 0, 0));
	printf("Expected:   , result: %s\n", ft_substr(s3, 1, 1));
	return 0;
}
