/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:14:43 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/24 12:15:49 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
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
	printf("%s", ft_strrchr(s, c));
	return (0);
} */
