/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:56:39 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/14 12:33:36 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
int	ft_str_is_numeric(char *str)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = str[i];
		if (y < 48 || y > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
// int main()
// {    
//     printf("%d", ft_str_is_numeric("123"));
//     return 0;
// }
