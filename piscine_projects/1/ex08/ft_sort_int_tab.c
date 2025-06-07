/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:14:59 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/19 15:19:30 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

//int	main(void)
//{
//	int	tab[] = {1, 2, 9, 10, 13, 11, 12};
//	int	size;
//	int	i;
//
//	size = sizeof(tab) / sizeof(tab[0]);
//	i = 0;
//	while (i < size)
//	{
//		printf("%d ", tab[i]);
//		i++;
//	}
//	printf("\n");
//	return (0);
//}