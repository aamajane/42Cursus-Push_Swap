/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:44:27 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:23:31 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3(t_list **a)
{
	int	head;
	int	next;
	int	last;

	head = (*a)->content;
	next = (*a)->next->content;
	last = ft_lstlast(*a)->content;
	if (head >= next && next <= last && last >= head)
		sa(a, 1);
	else if (head >= next && next <= last && last <= head)
		ra(a, 1);
	else if (head <= next && next >= last && last <= head)
		rra(a, 1);
	else if (head <= next && next >= last && last >= head)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (head >= next && next >= last && last <= head)
	{
		sa(a, 1);
		rra(a, 1);
	}
}

void	ft_sort_5(t_list **a, t_list **b)
{
	int		index;
	int		i;

	i = 0;
	while (i++ < 2)
	{
		index = ft_find_min(*a);
		if (index <= 2)
			while (index--)
				ra(a, 1);
		else
			while (index++ < ft_lstsize(*a))
				rra(a, 1);
		pb(b, a, 1);
	}
	ft_sort_3(a);
	pa(a, b, 1);
	if (ft_lstsize(*b))
		pa(a, b, 1);
}
