/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:58:07 by anezkahavra       #+#    #+#             */
/*   Updated: 2026/03/03 21:08:21 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	int		j;
	char	*temp;

	i = 0;
	while (s1[i] != '\0' && is_in_set(set, s1[i]) == 1)
		i++;
	k = ft_strlen(s1) - 1;
	while (k > i && is_in_set(set, s1[k]) == 1)
		k--;
	k++;
	temp = malloc(((k - i) + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	j = 0;
	while (i != k)
	{
		temp[j] = s1[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

//  int main(void)
// {
//     char str[50] = "jkmkjmllkNAOMIjklmlkj";
//     char set[50] = "j";
// 	// printf("%d\n", is_in_set((set), 'k'));
//     printf("%s\n", ft_strtrim(str, set));
// 	printf("%s\n", ft_strtrim(str, "k"));

// 	printf("%s\n", ft_strtrim(str, "l"));
//     return (0);
// }
