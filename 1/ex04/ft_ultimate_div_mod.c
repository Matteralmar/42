/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:34:32 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/13 11:34:36 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;

	div = *a / *b;
	*b = *a % *b;
	*a = div;
}

// int main()
// {
//      int A = 10;
//      int B = 2;
//      ft_ultimate_div_mod(&A, &B);
//      printf("%d", A);
//      printf("%d", B);
//      return 0;
// }
