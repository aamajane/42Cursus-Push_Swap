/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:29:07 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:46:58 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ft_check_err(&a, ac, av))
		ft_push_swap(&a, &b);
	else
		ft_putendl_fd("Error", 2);
	return (0);
}

void	ft_push_swap(t_list **a, t_list **b)
{
	int		size;

	size = ft_lstsize(*a);
	if (size == 1 || ft_stack_is_sorted(*a))
		return ;
	else if (size <= 3)
		ft_sort_3(a);
	else if (size <= 5)
		ft_sort_5(a, b);
	else
		ft_midpoint_sort(a, b);
}
