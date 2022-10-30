#include <string.h>
#include <stdio.h>

#include "../libft/libft.h"




int main()
{
	char	str[22] = "Boris Verdecia Echarte";
	int		tab[10] = {1,2,3,4,5,6,7,8,9,10};

	printf("%s", ft_memmove(tab + 5, tab, sizeof(int) * 5) == memmove(tab + 5, tab, sizeof(int) * 5) ? "true\n":"false\n");
	printf("%s", ft_memmove(0, 0, 10) == memmove(0, 0, 10) ? "true\n":"false\n");
	printf("%s", ft_memmove(str + 5, str, 10) == memmove(str + 5, str, 10) ? "true\n":"false\n");

	printf("%s", ft_memmove(0, 0, 10) == memmove(0, 0, 10) ? "true\n":"false\n");
	
	for (int i = 0; i < 10; i++)
		printf("dest_array[%d] = %d\n", i, tab[i]);
	
	printf("tab: %p\n", tab);
	return 0;
}
