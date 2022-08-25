/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:22:45 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:24:07 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_read(char **input)
{
	char	c;
	int		i;

	i = 0;
	while (read(0, &c, 1))
		(*input)[i++] = c;
	(*input)[i] = '\0';
}

void	ft_sort_tab(int **tab, int size)
{
	int	i;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		if ((*tab)[i] > (*tab)[i + 1])
		{
			temp = (*tab)[i];
			(*tab)[i] = (*tab)[i + 1];
			(*tab)[i + 1] = temp;
			i = -1;
		}
	}
}

int	ft_free(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
		free((*str)[i++]);
	free(*str);
	return (0);
}

int	ft_find_min(t_list *a)
{
	int	index;
	int	min;
	int	i;

	min = a->content;
	index = 0;
	i = 0;
	while (a)
	{
		if (min > a->content)
		{
			min = a->content;
			index = i;
		}
		a = a->next;
		i++;
	}
	return (index);
}

int	ft_find_mid(t_list *lst, int size)
{
	int	*tab;
	int	mid;
	int	i;

	tab = (int *)malloc(sizeof(int) * ft_lstsize(lst));
	if (!tab)
		return (0);
	i = 0;
	while (size--)
	{
		tab[i++] = lst->content;
		lst = lst->next;
	}
	ft_sort_tab(&tab, i);
	mid = tab[i / 2];
	free(tab);
	return (mid);
}
