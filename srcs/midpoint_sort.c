/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:40:32 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:23:37 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_midpoint_sort(t_list **a, t_list **b)
{
	t_data	d;
	int		*chunk;

	d.size = ft_lstsize(*a);
	chunk = (int *)malloc(sizeof(int) * (d.size / 2));
	if (!chunk)
		return ;
	d.i = 0;
	while (d.size-- / 2)
		chunk[d.i++] = 0;
	d.i = 0;
	ft_empty_stack_a(a, b, &chunk, &d.i);
	while (*b && d.i >= 0)
	{
		if (ft_check_stack_b_order(a, b))
			break ;
		else if (chunk[d.i] == 2 || ft_chunk_is_reversed(*b, chunk[d.i]) \
				|| ft_chunk_is_sorted(*b, chunk[d.i]))
			ft_sort_chunk_b(a, b, &chunk[d.i]);
		else if (chunk[d.i])
			ft_empty_chunk_b(a, b, &chunk, &d.i);
		d.i--;
	}
	free(chunk);
}

void	ft_empty_stack_a(t_list **a, t_list **b, int **chunk, int *i)
{
	t_data	d;

	while ((*a)->next)
	{
		d.size = ft_lstsize(*a);
		d.mid = ft_find_mid(*a, d.size);
		while (d.size)
		{
			if (ft_check_rest_a(*a, d.mid, d.size))
				break ;
			if ((*a)->content < d.mid)
				(*chunk)[*i] += pb(b, a, 1);
			else if (ft_lstlast(*a)->content < d.mid)
			{
				rra(a, 1);
				(*chunk)[*i] += pb(b, a, 1);
			}
			else
				ra(a, 1);
			d.size--;
		}
		(*i)++;
	}
}

void	ft_empty_chunk_b(t_list **a, t_list **b, int **chunk, int *i)
{
	t_data	d;

	d.num_pa = 0;
	d.num_rb = 0;
	d.last_chunk = (*chunk)[0];
	d.mid = ft_find_mid(*b, (*chunk)[*i]);
	while ((*chunk)[*i])
	{
		if (ft_check_rest_b(*b, d.mid, (*chunk)[*i]))
			break ;
		if ((*b)->content > d.mid)
			d.num_pa += pa(a, b, 1);
		else
			d.num_rb += rb(b, 1);
		((*chunk)[*i])--;
	}
	while (*i && d.num_rb--)
		(*chunk)[*i] += rrb(b, 1);
	if (!(*i))
		(*chunk)[*i] = d.last_chunk - d.num_pa;
	while (d.num_pa > 1 && !ft_stack_is_sorted(*a))
		(*chunk)[++(*i)] += ft_empty_chunk_a(a, b, &d.num_pa);
	(*i)++;
}

void	ft_sort_chunk_b(t_list **a, t_list **b, int *chunk)
{
	t_data	d;

	if (*chunk == 2)
	{
		if ((*b)->content < (*b)->next->content)
			sb(b, 1);
		*chunk -= pa(a, b, 1);
		*chunk -= pa(a, b, 1);
	}
	else if (ft_chunk_is_reversed(*b, *chunk))
		while (*chunk)
			*chunk -= pa(a, b, 1);
	else if (ft_chunk_is_sorted(*b, *chunk))
	{
		d.num_rb = *chunk - 1;
		while (d.num_rb)
			d.num_rb -= rb(b, 1);
		*chunk -= pa(a, b, 1);
		while (*chunk)
		{
			rrb(b, 1);
			*chunk -= pa(a, b, 1);
		}
	}
}

int	ft_empty_chunk_a(t_list **a, t_list **b, int *num_pa)
{
	t_data	d;

	d.mid = ft_find_mid(*a, *num_pa);
	d.num_pb = 0;
	d.num_ra = 0;
	if (*num_pa == 2)
		if ((*a)->content > (*a)->next->content)
			*num_pa -= sa(a, 1) + 1;
	while (*num_pa)
	{
		if (ft_check_rest_a(*a, d.mid, *num_pa))
			break ;
		if ((*a)->content < d.mid)
			d.num_pb += pb(b, a, 1);
		else
			d.num_ra += ra(a, 1);
		(*num_pa)--;
	}
	while (d.num_ra--)
		*num_pa += rra(a, 1);
	return (d.num_pb);
}
