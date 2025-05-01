/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:32:11 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/14 12:15:28 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
// int main()
// {
//     char src[] = "abc";
//     char dest[3];
//     ft_strncpy(dest, src, 1);
//     // int f = ft_strlen(b);
//     // printf("%d", f);
//     // int g = ft_strlen(a);
//     printf("%s", dest);
//     return 0;
// }
