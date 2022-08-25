/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:21:11 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:23:17 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_err(t_list **a, int ac, char **av)
{
	char	**arg;
	int		i;

	i = 0;
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (!arg || !arg[0])
			return (0);
		i = -1;
	}
	else
		arg = av;
	while (arg[++i])
	{
		if (!ft_check_arg(a, arg[i], ft_atoi(arg[i])))
		{
			if (ac == 2)
				ft_free(&arg);
			return (0);
		}
	}
	if (ac == 2)
		ft_free(&arg);
	return (1);
}

int	ft_check_arg(t_list **a, char *arg, int nb)
{
	if ((nb == 0 && ft_strncmp(arg, "0", ft_strlen(arg))) || \
		!ft_check_dup(*a, nb) || !ft_creat_stack(a, nb))
	{
		ft_lstclear(a);
		return (0);
	}
	return (1);
}

int	ft_check_dup(t_list *a, int nb)
{	
	while (a)
	{
		if (nb == a->content)
			return (0);
		a = a->next;
	}
	return (1);
}
