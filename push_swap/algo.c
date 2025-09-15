/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:03:50 by gvasylie          #+#    #+#             */
/*   Updated: 2025/08/14 14:03:52 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *st, int max_n)
{
	if (st->a[1] == max_n)
		rotate("rra\n", st->a, st->s_a);
	else if (st->a[0] > st->a[2])
		rotate("ra\n", st->a, st->s_a);
	if (st->a[0] > st->a[1])
		swap("sa\n", st->a, st->s_a);
}

void	sort_four_to_five(t_stacks *st, int max_n)
{
	while (st->s_a > 3)
	{
		if (st->a[st->s_a - 1] == 0)
			rotate("rra\n", st->a, st->s_a);
		else if (st->a[0] > st->a[st->s_a - 1])
			rotate("ra\n", st->a, st->s_a);
		else if (st->a[0] > st->a[1])
			swap("sa\n", st->a, st->s_a);
		else
			push("pb\n", st);
		if (st->s_a == 5)
			duplicates_or_sorted(st, 1);
	}
	sort_three(st, max_n);
	if (st->s_b > 1 && st->b[0] < st->b[1])
		swap("sb\n", st->b, st->s_b);
	while (st->s_b > 0)
	{
		push("pa\n", st);
		if (st->a[0] > st->a[1])
			swap("sa\n", st->a, st->s_a);
	}
}

void	radix_sort(t_stacks *st, int bit_size, int bit, int s_a)
{
	int	i;

	while (((s_a - 1) >> bit_size) != 0)
		bit_size++;
	while (bit < bit_size)
	{
		i = 0;
		while (i < s_a)
		{
			if (((st->a[0] >> bit) & 1) == 0)
				push("pb\n", st);
			else
				rotate("ra\n", st->a, st->s_a);
			i++;
		}
		while (st->s_b > 0)
			push("pa\n", st);
		bit++;
	}
}
