#include <strings.h>
#include <stdio.h>

#include "..\libft.h"

int main()
{
	char s[70];
	char st[70];

	bzero(s, 30);
	ft_bzero(s, 30);
	printf("%s\n%s\n", s, st);

}
