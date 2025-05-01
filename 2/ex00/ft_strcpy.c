/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:42:02 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/14 12:14:31 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// int main()
// {
//     char src[] = "abc";
//     char dest[3];
//     ft_strcpy(dest, src);
//     // int f = ft_strlen(b);
//     // printf("%d", f);
//     // int g = ft_strlen(a);
//     printf("%s", dest);
//     return 0;
// }
