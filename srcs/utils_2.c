/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:40:02 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:24:14 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_chunk_is_reversed(t_list *lst, int i)
{
	while (--i)
	{
		if (lst->content < lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_chunk_is_sorted(t_list *lst, int i)
{
	while (--i)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_check_rest_a(t_list *a, int mid, int size)
{
	while (size--)
	{
		if (a->content < mid)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_check_rest_b(t_list *b, int mid, int size)
{
	while (size--)
	{
		if (b->content > mid)
			return (0);
		b = b->next;
	}
	return (1);
}
