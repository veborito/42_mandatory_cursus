/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:19 by bverdeci          #+#    #+#             */
/*   Updated: 2023/02/13 15:39:36 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Algos à tester:
	- swap push parce que push swap ça marche pas
*/

/* Comment va marcher l'algo ? 
 - tant que la stack A n'est pas vide.
 - on compare le premier element de la stack A avec le deuxieme.
 - si le premier est plus petit que le deuxieme on push le 1er
 	sur la stack B , Sinon swap_a et ensuite push sur b.
 - s'il y a plus d'un element dans la stack B
 - si le 1er element est plus petit que le deuxieme swap_b
 - tout remetttre dans A ensuite. Tant que B n'est pas vide push_a*/
void ft_sort(t_list **s_a, t_list **s_b, t_result **res)
{
	while(ft_lstsize(*s_a) > 0)
	{
		if ((*s_a)->content < (*s_a->next->content))
			ft_lstadd_back_2(res, ft_lstnew_2(ft_push_b(s_a, s_b)));
		else
		{
			ft_lstadd_back_2(res, ft_lstnew_2(ft_swap_a(s_a)));
			ft_lstadd_back_2(res, ft_lstnew_2(ft_push_b(s_a, s_b)));
		}
	}
}