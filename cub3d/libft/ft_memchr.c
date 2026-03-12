/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:11:03 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/11 20:05:21 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*start;

	i = 0;
	start = NULL;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
		{
			start = &((unsigned char *)s)[i];
			break ;
		}
		i++;
	}
	return (start);
}

/* int	main(void)
{
	char s[50] = "kurnik sopak uz nemuzu s timhlectim";
	int c = 'n';
	size_t n = 8;
	printf("%s",(char*)ft_memchr(s, c, n));
	return (0);
} */
