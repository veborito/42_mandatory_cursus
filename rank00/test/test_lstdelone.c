#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"


static void ft_memdel_range(void *mem)
{
	if (mem)
        free(mem);
}


int     main()
{
    t_list  *mylist;
    t_list  *new_link;
    t_list  *last;
	char* s;
	char* s1;

	s = ft_strdup("Boris");
	s1 = ft_strdup("Boris");

    mylist = ft_lstnew(s1);
    last = mylist;
    new_link = ft_lstnew(s);
    ft_lstadd_front(&mylist, new_link);

    ft_lstdelone(mylist, ft_memdel_range);

    return 0;
}
