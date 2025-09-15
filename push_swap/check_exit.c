/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:04:00 by gvasylie          #+#    #+#             */
/*   Updated: 2025/08/14 14:04:02 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit_message(t_stacks *st, char *msg)
{
	if (*msg)
		write(2, msg, ft_strlen(msg));
	if (st)
	{
		free(st->a);
		free(st->b);
		free(st->joined);
		free(st);
	}
	if (*msg)
		exit(42);
	else
		exit(0);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		free_exit_message(NULL, "");
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0] || av[i][0] == ' ')
			free_exit_message(NULL, "Error\n");
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' '
			&& av[i][j] != '-' && av[i][j] != '+')
				free_exit_message(NULL, "Error\n");
			if ((((av[i][j] == '+') || (av[i][j] == '-')) &&
			((av[i][j + 1] == '\0') || (av[i][j + 1] == '-') ||
			(av[i][j + 1] == '+') || (av[i][j + 1] == ' ')))
			|| ((ft_isdigit(av[i][j]) &&
			(av[i][j + 1] == '-' || av[i][j + 1] == '+'))))
				free_exit_message(NULL, "Error\n");
			j++;
		}
	}
}

long	ft_atoer(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_array_sorted(t_stacks *st)
{
	int	i;

	i = 0;
	while (i < st->s_a - 1)
	{
		if (st->a[i] > st->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	duplicates_or_sorted(t_stacks *st, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < st->s_a - 1)
		{
			j = i + 1;
			while (j < st->s_a)
			{
				if (st->a[i] == st->a[j])
					free_exit_message(st, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(st))
		free_exit_message(st, "");
}
