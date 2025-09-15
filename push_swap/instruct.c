/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:04:20 by gvasylie          #+#    #+#             */
/*   Updated: 2025/08/14 14:04:21 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, int *arr, int size)
{
	if (size < 2)
		return ;
	arr[0] ^= arr[1];
	arr[1] ^= arr[0];
	arr[0] ^= arr[1];
	write(1, str, ft_strlen(str));
}

static void	push_stack(int *src, int *dst, int *src_size, int *dst_size)
{
	if (*src_size <= 0)
		return ;
	src[0] ^= dst[0];
	ft_memmove(dst + 1, dst, sizeof(int) * (*dst_size));
	dst[0] ^= src[0];
	(*dst_size)++;
	(*src_size)--;
	ft_memmove(src, src + 1, sizeof(int) * (*src_size));
}

void	push(char *str, t_stacks *st)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		push_stack(st->b, st->a, &st->s_b, &st->s_a);
	else
		push_stack(st->a, st->b, &st->s_a, &st->s_b);
	write(1, str, ft_strlen(str));
}

void	rotate(char *str, int *arr, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	if (ft_strncmp(str, "rr", 2) == 0)
	{
		tmp = arr[size - 1];
		ft_memmove(arr + 1, arr, sizeof(int) * (size - 1));
		arr[0] = tmp;
	}
	else
	{
		tmp = arr[0];
		ft_memmove(arr, arr + 1, sizeof(int) * (size - 1));
		arr[size - 1] = tmp;
	}
	write(1, str, ft_strlen(str));
}
