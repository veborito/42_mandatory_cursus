#include <stdlib.h>
#include <stdio.h>

#include "../libft/libft.h"

int main()
{
	printf("%d, %d\n", atoi(" \n \t \f \r   -12123avdw12342   "), ft_atoi(" \n \t \f \r   -12123avdw12342   "));
	printf("%d, %d\n", atoi("+-1212"), ft_atoi("+-1212"));
	printf("%d, %d\n", atoi("a 12123avdw12342"), ft_atoi("a 12123avdw12342"));
	printf("%d, %d\n", atoi(""), ft_atoi(""));
	printf("%d, %d\n", atoi("0123"), ft_atoi("0123"));
	printf("%d, %d\n", atoi("-12 12"), ft_atoi("-12 12"));
	printf("%d, %d\n", atoi("+12++12"), ft_atoi("+12++12"));
	printf("%d, %d\n", atoi(" +	1   -12 12"), ft_atoi(" +	1   -12 12"));
	printf("%d, %d\n", atoi("23343495959696502"), ft_atoi("23343495959696502"));
	printf("%d, %d\n", atoi("23.3"), ft_atoi("23.3"));
	printf("%d, %d\n", atoi("0"), ft_atoi("0"));
	printf("%d, %d\n", atoi("-2147483648."), ft_atoi("-2147483648."));
	return 0;
}
