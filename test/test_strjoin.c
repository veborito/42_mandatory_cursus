#include <stdio.h>
#include "../libft/libft.h"

int main()
{
	printf("Expected: , Result: %s\n", ft_strjoin("", ""));
	printf("Expected: salut, Result: %s\n", ft_strjoin("", "salut"));
	printf("Expected: salut, Result: %s\n", ft_strjoin("salut", ""));
	printf("Expected: salut comment vas-tu?, Result: %s\n", ft_strjoin("salut", " comment vas-tu ?"));
	printf("Expected: salut comment vas-tu?, Result: %s\n", ft_strjoin("salut comment", " vas-tu ?"));
	return 0;
}
