/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:29:06 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/06/24 13:07:40 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*temp;
	unsigned int		i;
	int					v;

	if (len >= ft_strlen(s) - start)
		v = ft_strlen(s) - start - len;
	else
		v = 0;
	if (ft_strlen(s) < start || len == 0)
		return (ft_strdup(""));
	temp = malloc((len + v + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i <= len - 1 && s[start + i] != '\0')
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/* int main(void)
{
    char const str[50] = "gabina ma zase dovolenou";
    unsigned int start = 0;
    size_t len = 10;
    printf("%s", ft_substr("gabina ma zase dovolenou", start, len));
    return (0);
} */
