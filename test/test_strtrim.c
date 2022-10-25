#include <stdio.h>
#include "../libft/libft.h"

int main()
{
	printf("Expected: Boris  Result: %s\n", ft_strtrim("     Boris     ", " "));
	printf("Expected: Boris  Result: %s\n", ft_strtrim("Boris", "  "));
	printf("Expected: Boris  Result: %s\n", ft_strtrim("ddddBorisdddd", "d"));
	printf("Expected: Boris  Result: %s\n", ft_strtrim("dddd.Borisd.d.dd", "d."));
	printf("Expected: Boris Verdecia Echarte  Result: %s\n", ft_strtrim("dd d d. Boris Verdecia Echarte d.d.dd", "d. "));
	printf("Expected:  Result: %s\n", ft_strtrim("        ", " "));
	printf("Expected:  Result: %s....\n", ft_strtrim("", ""));
	return (0);
}


