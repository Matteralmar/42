/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:04:09 by gvasylie          #+#    #+#             */
/*   Updated: 2025/08/14 14:04:09 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allocate_stacks(int ac, char **av, t_stacks *st)
{
	int	i;

	i = 1;
	st->s_a = 0;
	st->s_b = 0;
	while (i < ac)
	{
		st->s_a += word_count(av[i], ' ');
		i++;
	}
	st->a = calloc(st->s_a, sizeof(int));
	if (!(st->a))
		free_exit_message(st, "Error\n");
	st->b = calloc(st->s_a, sizeof(int));
	if (!(st->b))
		free_exit_message(st, "Error\n");
}

void	args_join(int ac, char **av, t_stacks *st)
{
	char	*tmp_1;
	char	*tmp_2;
	int		i;

	i = 1;
	tmp_1 = ft_strdup("");
	if (!tmp_1)
		free_exit_message(st, "Error\n");
	while (i < ac - 1)
	{
		tmp_2 = ft_strjoin(tmp_1, av[i]);
		free(tmp_1);
		if (!tmp_2)
			free_exit_message(st, "Error\n");
		tmp_1 = ft_strjoin(tmp_2, " ");
		free(tmp_2);
		if (!tmp_1)
			free_exit_message(st, "Error\n");
		i++;
	}
	tmp_2 = ft_strjoin(tmp_1, av[i]);
	free(tmp_1);
	if (!tmp_2)
		free_exit_message(st, "Error\n");
	st->joined = tmp_2;
}

void	push_numbers(t_stacks *st, int i)
{
	char	**nums;
	long	result;

	nums = ft_split(st->joined, ' ');
	if (!nums)
		free_exit_message(st, "Error\n");
	while (nums[i] != NULL)
	{
		result = ft_atoer(nums[i]);
		if (result > INT_MAX || result < INT_MIN
			|| ft_strncmp(nums[i], "-0", 2) == 0)
		{
			while (nums[i] != NULL)
				free(nums[i++]);
			free(nums);
			free_exit_message(st, "Error\n");
		}
		st->a[i] = result;
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	normalize(t_stacks *st)
{
	int	i;
	int	j;
	int	ind;
	int	*norm;

	norm = malloc(st->s_a * sizeof(int));
	if (!norm)
		free_exit_message(st, "Error\n");
	i = -1;
	while (++i < st->s_a)
	{
		ind = 0;
		j = -1;
		while (++j < st->s_a)
			if (st->a[i] > st->a[j])
				ind++;
		norm[i] = ind;
	}
	i = -1;
	while (++i < st->s_a)
		st->a[i] = norm[i];
	free(norm);
}
