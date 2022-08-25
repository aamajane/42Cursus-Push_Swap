/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:55:12 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:23:26 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_creat_stack(t_list **a, int nb)
{
	t_list	*new;

	new = ft_lstnew(nb);
	if (!new)
		return (0);
	ft_lstadd_back(a, new);
	return (1);
}

int	ft_stack_is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_stack_is_reversed(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content < lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_check_stack_b_order(t_list **a, t_list **b)
{
	if (ft_stack_is_reversed(*b))
	{
		while (*b)
			pa(a, b, 1);
		return (1);
	}
	else if (ft_stack_is_sorted(*b))
	{
		while (*b)
		{
			rrb(b, 1);
			pa(a, b, 1);
		}
		return (1);
	}
	return (0);
}
