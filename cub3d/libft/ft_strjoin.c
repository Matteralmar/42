/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:35:04 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/10/16 22:42:23 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		k;

	temp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		temp[i] = s2[k];
		k++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/* int main(void)
{
    char str1[50] = "kulajdu dela nejlepsi babicka";
    char str2[50] = " a pak hned deda";
    printf("%s", ft_strjoin(str1, str2));
    return (0);
} */
