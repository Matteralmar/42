/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:31:24 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/24 12:13:01 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*start;

	i = 0;
	start = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			start = &((char *)s)[i];
			break ;
		}
		i++;
	}
	if (s[i] == (char)c)
		start = &((char *)s)[i];
	return (start);
}

/* int	main(void)
{
	const char s[50] = "to be or not to be";
	int c = 'o';
	printf("%s", ft_strchr(s, c));
	return (0);
} */
