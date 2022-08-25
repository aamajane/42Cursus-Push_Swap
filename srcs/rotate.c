/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:38:27 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:23:58 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_list **lst)
{
	t_list	*new_head;

	if (*lst)
	{
		if ((*lst)->next)
		{
			new_head = (*lst)->next;
			ft_lstadd_back(lst, *lst);
			*lst = new_head;
		}
	}
}

int	ra(t_list **a, int n)
{
	ft_rotate(a);
	if (n == 1)
		ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_list **b, int n)
{
	ft_rotate(b);
	if (n == 1)
		ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_list **a, t_list **b, int n)
{
	ft_rotate(a);
	ft_rotate(b);
	if (n == 1)
		ft_putendl_fd("rr", 1);
	return (1);
}
