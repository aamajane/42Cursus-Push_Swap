/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:38:18 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:23:50 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_list **lst1, t_list **lst2)
{
	t_list	*new_head;

	if (*lst2)
	{
		new_head = (*lst2)->next;
		ft_lstadd_front(lst1, *lst2);
		*lst2 = new_head;
	}
}

int	pa(t_list **a, t_list **b, int n)
{
	ft_push(a, b);
	if (n == 1)
		ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_list **b, t_list **a, int n)
{
	ft_push(b, a);
	if (n == 1)
		ft_putendl_fd("pb", 1);
	return (1);
}
