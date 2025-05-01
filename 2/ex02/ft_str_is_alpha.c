/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:55:08 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/14 12:22:51 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
int	ft_str_is_alpha(char *str)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = str[i];
		if ((y < 65 || y > 90) && (y < 97 || y > 122))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int main()
// {    
//     printf("%d", ft_str_is_alpha("abc"));
//     return 0;
// }
