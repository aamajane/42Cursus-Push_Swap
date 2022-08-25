/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:05:24 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:24:02 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_list **lst)
{
	int	temp;

	if (*lst)
	{
		if ((*lst)->next)
		{
			temp = (*lst)->content;
			(*lst)->content = (*lst)->next->content;
			(*lst)->next->content = temp;
		}
	}
}

int	sa(t_list **a, int n)
{
	ft_swap(a);
	if (n == 1)
		ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_list **b, int n)
{
	ft_swap(b);
	if (n == 1)
		ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_list **a, t_list **b, int n)
{
	ft_swap(a);
	ft_swap(b);
	if (n == 1)
		ft_putendl_fd("ss", 1);
	return (1);
}
