/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:38:36 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:23:54 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_rotate(t_list **lst)
{
	t_list	*new_last;

	if (*lst)
	{
		if ((*lst)->next)
		{
			new_last = *lst;
			while (new_last->next->next)
				new_last = new_last->next;
			ft_lstadd_front(lst, ft_lstlast(*lst));
			new_last->next = NULL;
		}
	}
}

int	rra(t_list **a, int n)
{
	ft_rev_rotate(a);
	if (n == 1)
		ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_list **b, int n)
{
	ft_rev_rotate(b);
	if (n == 1)
		ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_list **a, t_list **b, int n)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	if (n == 1)
		ft_putendl_fd("rrr", 1);
	return (1);
}
