/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:27:16 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/13 11:27:18 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int main()
// {
//     int A = 1;
//     int B = 1;
//     ft_div_mod(10, 2, &A, &B);
//     printf("%d", A);
//     printf("%d", B);
//     return 0;

// }