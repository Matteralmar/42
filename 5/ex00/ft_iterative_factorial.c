/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:25:44 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/20 13:29:37 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb >= 2)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

//int main()
//{
//    int result = ft_iterative_factorial(-2);
//    printf("%d", result);
//    return 0;
//}