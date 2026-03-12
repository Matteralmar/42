/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:43:49 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/11 18:16:22 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char s[50] = "Kukacka kuka na houpacce";
	int c = 'a';
	size_t n = 5;
	printf("%s\n", (char*)ft_memset(s, c, n));
	return (0);
} */
