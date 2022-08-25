/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:39:54 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/08 17:05:06 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define BUFFER_SIZE 100000

typedef struct s_data
{
	int	i;
	int	mid;
	int	size;
	int	num_pa;
	int	num_pb;
	int	num_ra;
	int	num_rb;
	int	last_chunk;
}				t_data;

// push_swap.c
void	ft_push_swap(t_list **a, t_list **b);

// check_error.c
int		ft_check_err(t_list **a, int ac, char **av);
int		ft_check_arg(t_list **a, char *arg, int nb);
int		ft_check_dup(t_list *a, int nb);

// checker.c
int		ft_checker(t_list **a, t_list **b);
int		ft_do_operation(t_list **a, t_list **b, char *line);

// hard_sort.c
void	ft_sort_3(t_list **a);
void	ft_sort_5(t_list **a, t_list **b);

// midpoint_sort.c
void	ft_midpoint_sort(t_list **a, t_list **b);
void	ft_empty_stack_a(t_list **a, t_list **b, int **chunk, int *i);
void	ft_empty_chunk_b(t_list **a, t_list **b, int **chunk, int *i);
void	ft_sort_chunk_b(t_list **a, t_list **b, int *chunk);
int		ft_empty_chunk_a(t_list **a, t_list **b, int *num_pa);

// creat_stack.c
int		ft_creat_stack(t_list **a, int nb);
int		ft_stack_is_sorted(t_list *a);
int		ft_stack_is_reversed(t_list *a);
int		ft_check_stack_b_order(t_list **a, t_list **b);

// push.c
void	ft_push(t_list **lst1, t_list **lst2);
int		pa(t_list **a, t_list **b, int n);
int		pb(t_list **b, t_list **a, int n);

// swap.c
void	ft_swap(t_list **lst);
int		sa(t_list **a, int n);
int		sb(t_list **b, int n);
int		ss(t_list **a, t_list **b, int n);

// rotate.c
void	ft_rotate(t_list **lst);
int		ra(t_list **a, int n);
int		rb(t_list **b, int n);
int		rr(t_list **a, t_list **b, int n);

// rev_rotate.c
void	ft_rev_rotate(t_list **lst);
int		rra(t_list **a, int n);
int		rrb(t_list **b, int n);
int		rrr(t_list **a, t_list **b, int n);

// utils_1.c
void	ft_read(char **input);
void	ft_sort_tab(int **tab, int size);
int		ft_free(char ***str);
int		ft_find_min(t_list *a);
int		ft_find_mid(t_list *lst, int size);

// utils_2.c
int		ft_chunk_is_reversed(t_list *lst, int i);
int		ft_chunk_is_sorted(t_list *lst, int i);
int		ft_check_rest_a(t_list *a, int mid, int size);
int		ft_check_rest_b(t_list *b, int mid, int size);

#endif
