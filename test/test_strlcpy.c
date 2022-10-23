#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libft/libft.h"

int main()
{
	char dst[30];
	char dst1[30];
	strlcpy(dst, "", 0);
	ft_strlcpy(dst1, "", 0);
	printf("%s,%s.\n", dst, dst1);
	return 0;
}
