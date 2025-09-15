/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:04:41 by gvasylie          #+#    #+#             */
/*   Updated: 2025/08/14 14:04:41 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		s_a;
	int		s_b;
	char	*joined;
}			t_stacks;

void		allocate_stacks(int ac, char **av, t_stacks *st);
void		free_exit_message(t_stacks *st, char *msg);
void		check_args(int ac, char **av);
void		args_join(int ac, char **av, t_stacks *st);
void		push_numbers(t_stacks *st, int i);
long		ft_atoer(const char *str);
void		duplicates_or_sorted(t_stacks *st, int i);
int			is_array_sorted(t_stacks *st);
void		normalize(t_stacks *st);
void		swap(char *str, int *arr, int size);
void		push(char *str, t_stacks *st);
void		rotate(char *str, int *arr, int size);
void		radix_sort(t_stacks *st, int bit_size, int bit, int s_a);
void		sort_three(t_stacks *st, int max_n);
void		sort_four_to_five(t_stacks *st, int max_n);

#endif