/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:20:46 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/23 23:27:11 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numb_int(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
/* char	*ft_obraceni(char *str)
{
	char	*temp;
	int		i;
	int		k;

	i = 0;
	k = ft_strlen(str) - 1;
	temp = malloc(ft_strlen(str) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		temp[i] = str[k];
		k--;
		i++;
	}
	temp[ft_strlen(str)] = '\0';
	return (temp);
} */

char	*ft_itoa(int n)
{
	char	*string;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	string = malloc(numb_int(n) * sizeof(char) + 1);
	if (string == NULL)
		return (NULL);
	if (n < 0)
		string[i] = '-';
	i = numb_int(n);
	string[i] = '\0';
	i--;
	while (n != 0)
	{
		if (n < 0)
			n = n * (-1);
		string[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (string);
}

/* int main(void)
{
	int n = -46466;
	printf("%s", ft_itoa(n));
	return (0);
} */
