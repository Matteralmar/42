/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:48:02 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/28 12:51:06 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	char_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	skip_whitespace_and_sign(char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	result;
	int	i;
	int	index;

	base_len = is_valid_base(base);
	if (base_len < 2)
		return (0);
	sign = 1;
	result = 0;
	i = 0;
	skip_whitespace_and_sign(str, &i, &sign);
	while (str[i] && (char_index(str[i], base) != -1))
	{
		index = char_index(str[i], base);
		result = result * base_len + index;
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>

// int main()
// {
//     printf("%d\n", ft_atoi_base("1010", "01"));         // binary -> 10
//     printf("%d\n", ft_atoi_base("FF", "0123456789ABCDEF")); // hex -> 255
//     printf("%d\n", ft_atoi_base("poney", "poneyvif"));  // base 8 -> some int
//     printf("%d\n", ft_atoi_base("  -1A", "0123456789ABCDEF")); // hex -> -26
//     printf("%d\n", ft_atoi_base("42", "0123456789"));   // dec -> 42
//     printf("%d\n", ft_atoi_base("42", ""));             // invalid base -> 0
//     printf("%d\n", ft_atoi_base("42", "0"));            // invalid base -> 0
//     printf("%d\n", ft_atoi_base("42", "012+3456789"));  // invalid base -> 0
// }