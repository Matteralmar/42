/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:58:22 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/20 20:11:52 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	if (nb < 0)
		return (0);
	while (n * n <= nb)
	{
		if (n * n > nb)
			return (0);
		if (n * n == nb)
			return (n);
		n++;
	}
	return (0);
}

// int main()
// {
//     int result = ft_sqrt(16);
//     printf("%d", result);
//     return 0;
// }