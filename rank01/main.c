#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main()
{
	int i;
	int j;
	char *s1 = "salut";
	char *s2 = "Boris Verdecia Echarte";

	ft_printf("NON c'est %c %c %c %c %c %s %d lettres c'est pas bien compliqué\n", 'b', 'o', 'r', 'i', 's', "t'as capté ou je dois repeter?",5);

	ft_printf("Salut mec comment vas-tu ?\n");
	
	i = ft_printf("%p\n", s1);
	j = printf("%p\n", s1);
	printf("ft_printf-> %d : %d <-printf\n", i, j);

	i = ft_printf("%p\n", s2);
	j = printf("%p\n", s2);
	printf("ft_printf-> %d : %d <-printf\n", i, j);


	i = ft_printf("%X, ", 42);
	j = printf("%X\n", 42);
	printf("ft_printf-> %d : %d <-printf\n", i, j);
	
	i = ft_printf("%x, ", 1000);
	j = printf("%x\n", 1000);
	printf("ft_printf-> %d : %d <-printf\n", i, j);

	i = ft_printf("%u %%, ", 200000000);
	j = printf("%u %%\n", 200000000);
	printf("ft_printf-> %d : %d <-printf\n", i, j);

}
