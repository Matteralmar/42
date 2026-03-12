/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:16:52 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/24 12:46:49 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n - 1))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* int	main(void)
{
	char str[50] = "aaaajkfhnkan";
	char str2[50] = "acaaajhfakh";
	size_t n = 0;

	ft_strncmp(str, str2, n);
	printf("%d",ft_strncmp(str, str2, n));
	return (0);
} */
