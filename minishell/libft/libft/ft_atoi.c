/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivantso <vivantso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:52:35 by vivantso          #+#    #+#             */
/*   Updated: 2025/12/13 16:11:53 by vivantso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_skip_spaces(char *nptr, size_t *i)
{
	while (nptr[*i] == ' ' || (nptr[*i] >= 9 && nptr[*i] <= 13))
		(*i)++;
}

int	ft_atoi(char *nptr)
{
	int		sign;
	int		result;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	ft_skip_spaces(nptr, &i);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
