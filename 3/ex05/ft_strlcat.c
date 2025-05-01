/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:49:58 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/26 12:11:09 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = 0;
	src_len = ft_strlen(src);
	while (dest_len < size && dest[dest_len])
		dest_len++;
	if (dest_len == size)
		return (size + src_len);
	while (src[i] && (dest_len + i + 1) < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < size)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
int	main(void)
{
	char	buffer[20] = "Hello, ";
	char	*to_add = "world!";
	int	result;

	result = ft_strlcat(buffer, to_add, 20);
	printf("'%s'\n", buffer);
	printf("%d", result);
	return (0);
}
*/