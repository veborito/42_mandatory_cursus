#include "../libft/libft.h"
#include <stdio.h>

int main()
{
	int	min = -2147483648;
	int max = 2147483647;
	printf("Expected: %d Result: %s\n", min, ft_itoa(min));
	printf("Expected: %d Result: %s\n", 0, ft_itoa(0));
	printf("Expected: %d Result: %s\n", 9, ft_itoa(9));
	printf("Expected: %d Result: %s\n", 10, ft_itoa(10));
	printf("Expected: %d Result: %s\n", -2345, ft_itoa(-2345));
	printf("Expected: %d Result: %s\n", 20000, ft_itoa(20000));
	printf("Expected: %d Result: %s\n", max, ft_itoa(max));
	return 0;
}
