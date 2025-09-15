/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:04:27 by gvasylie          #+#    #+#             */
/*   Updated: 2025/08/14 14:04:28 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*st;

	check_args(ac, av);
	st = malloc(sizeof(t_stacks));
	if (!st)
		exit(42);
	allocate_stacks(ac, av, st);
	args_join(ac, av, st);
	push_numbers(st, 0);
	duplicates_or_sorted(st, 0);
	normalize(st);
	if (st->s_a == 2 && st->a[0] > st->a[1])
		swap("sa\n", st->a, st->s_a);
	else if (st->s_a == 3)
		sort_three(st, st->s_a - 1);
	else if (st->s_a >= 4 && st->s_a <= 5)
		sort_four_to_five(st, st->s_a - 1);
	else
		radix_sort(st, 0, 0, st->s_a);
	duplicates_or_sorted(st, 1);
	free_exit_message(st, "Error\n");
}
