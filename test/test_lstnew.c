#include <stdio.h>
#include "../libft/libft.h"

int main()
{
	t_list *list;

	list = ft_lstnew("Boris\n");
	printf("%s", list->content);

	return (0);
}
