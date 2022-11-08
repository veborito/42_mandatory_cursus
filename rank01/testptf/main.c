#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <stdio.h>

int main()
{
	int i;
	int j;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	char *s1 = "salut";
	char *s2 = "Boris Verdecia Echarte";

	ft_printf("NON c'est %c %c %c %c %c %s %d lettres c'est pas bien compliqué\n", 'b', 'o', 'r', 'i', 's', "t'as capté ou je dois repeter?",5);

	ft_printf("Salut mec comment vas-tu ?\n");
	
	i = ft_printf("%p\n", s1);
	j = printf("%p\n", s1);
	printf("ft_printf-> %d : %d <-printf\n", i, j);

	a = ft_printf("%p\n", s2);
	b = printf("%p\n", s2);
	printf("ft_printf-> %d : %d <-printf\n", a, b);


	c = ft_printf("%X, ", 42);
	d = printf("%X\n", 42);
	printf("ft_printf-> %d : %d <-printf\n", c, d);
	
	e = ft_printf("%x, ", 0);
	f = printf("%x\n", 0);
	printf("ft_printf-> %d : %d <-printf\n", e, f);

	g = ft_printf("%u %%, ", 200000000);
	h = printf("%u %%\n", 200000000);
	printf("ft_printf-> %d : %d <-printf\n", g, h);

}
