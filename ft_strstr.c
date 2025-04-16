/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:22:52 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/16 15:46:09 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!*to_find)
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return (&str[i]);
		i++;
	}
	return ((void *)0);
}
int main()
{
    char str[]= "Helwor wor";
    char to_find[3] = "or";

    ft_strstr(str, to_find);
    printf("%s", ft_strstr(str, to_find));
}