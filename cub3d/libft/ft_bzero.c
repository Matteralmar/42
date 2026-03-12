/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:15:54 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/11 18:16:37 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

/* int	main(void)
{
	char s[50] = "Kukacka kuka na houpacce";
	size_t n = 5;
	ft_bzero(s, n);
	printf("%s\n", s);
	return (0);
} */
