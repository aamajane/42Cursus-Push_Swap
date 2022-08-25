/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:14:00 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:23:22 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		ret;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!ft_check_err(&a, ac, av))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	ret = ft_checker(&a, &b);
	if (ret == -1)
		ft_putendl_fd("Error", 2);
	else if (!ret || b)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	return (0);
}

int	ft_checker(t_list **a, t_list **b)
{
	char	**tab;
	char	*input;
	int		i;

	input = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!input)
		return (0);
	ft_read(&input);
	tab = ft_split(input, '\n');
	if (!tab)
		return (0);
	free(input);
	i = 0;
	while (tab[i])
	{
		if (!ft_do_operation(a, b, tab[i++]))
		{
			ft_free(&tab);
			return (-1);
		}
	}
	if (!ft_stack_is_sorted(*a))
		return (ft_free(&tab));
	ft_free(&tab);
	return (1);
}

int	ft_do_operation(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		return (sa(a, 0));
	else if (!ft_strncmp(line, "sb", ft_strlen(line)))
		return (sb(b, 0));
	else if (!ft_strncmp(line, "ss", ft_strlen(line)))
		return (ss(a, b, 0));
	else if (!ft_strncmp(line, "pa", ft_strlen(line)))
		return (pa(a, b, 0));
	else if (!ft_strncmp(line, "pb", ft_strlen(line)))
		return (pb(b, a, 0));
	else if (!ft_strncmp(line, "ra", ft_strlen(line)))
		return (ra(a, 0));
	else if (!ft_strncmp(line, "rb", ft_strlen(line)))
		return (rb(b, 0));
	else if (!ft_strncmp(line, "rr", ft_strlen(line)))
		return (rr(a, b, 0));
	else if (!ft_strncmp(line, "rra", ft_strlen(line)))
		return (rra(a, 0));
	else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
		return (rrb(b, 0));
	else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
		return (rrr(a, b, 0));
	else
		return (0);
}
