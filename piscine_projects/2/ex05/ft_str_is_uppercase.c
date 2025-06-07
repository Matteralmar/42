/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:56:46 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/14 12:36:19 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = str[i];
		if (y < 65 || y > 90)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
// int main()
// {    
//     printf("%d", ft_str_is_uppercase("ABCZ"));
//     return 0;
// }
