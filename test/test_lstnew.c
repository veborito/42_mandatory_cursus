#include <stdio.h>
#include "../libft/libft.h"


void ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->content);
		list = list->next;
	}
}

static void ft_del(void *content)
{
	if (content)
		free(content);
}

int main()
{
	t_list *list;
	t_list *nl;
	char *s1 = ft_strdup("Verdecia");
	char *s2 = ft_strdup("De la muerte");

	list = ft_lstnew(s2);
	nl = ft_lstnew(s1);
	ft_lstadd_front(&list, nl);

	ft_lstdelone(list, ft_del);
	ft_putstr(nl->content);
	
	return (0);
}
