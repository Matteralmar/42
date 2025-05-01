/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:29:56 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/19 13:44:40 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <unistd.h>
#include <stdio.h>

void	cond(char *str, int *i, int *sign)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	cond(str, &i, &sign);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

//int	main(int argc, char **argv)
//{
//	if (argc == 2)
//	{
//		int	r;
//
//		r = ft_atoi(argv[1]);
//		printf("%d\n", r);
//	}
//	return (0);
//}
