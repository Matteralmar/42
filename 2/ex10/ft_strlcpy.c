/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:21:23 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/02 08:25:23 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int main(void)
{
    char dest[20];
    const char *source = "Hello, World!";
    unsigned int copied = ft_strlcpy(dest, source, sizeof(dest));

    printf("Copied: %s\n", dest);
    printf("Source length: %u\n", copied);
    return 0;
}