/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:19:58 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:19:58 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11
		|| str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
void minus_1(unsigned int i, char *s)
{
	s[0] -= 1;
}

char char_plus_1(unsigned int i, char c)
{
	c += 1;
	return c;
}

int main()
{
	int		num;
	size_t	len;
	char	*str;
	char	*tmp;
	char	*new;
	char	s[9] = "+98703";
	char	*src = "21";
	size_t i;
	int *arr;


	len = ft_strlen(s);
	printf("ft_strlen: %s", s);
	printf("\nft_strlen: %ld\n", len);

	len = ft_strlcat(s, src, sizeof(s));
	printf("\nft_strlcat: %s", src);
	printf("\nft_strlcat: %s", s);
	printf("\nft_strlcat: %ld\n", len);

	str = ft_strdup(s);
	printf("\nft_strdup: %s", s);
	printf("\nft_strdup: %s\n", str);

	num = ft_atoi(str);
	printf("\nft_atoi: %d\n", num);

	str = ft_itoa(num);
	printf("\nft_itoa: %s\n", str);

	printf("\nft_memset: %s", str);
	ft_memset(str + 3, 32, 1);
	printf("\nft_memset: %s\n", str);

	printf("\nft_substr: %s", str);
	tmp = ft_substr(str, 0, 3);
	printf("\nft_substr: %s\n", tmp);

	printf("\nft_memcpy: %s", str);
	printf("\nft_memcpy: %s", s + 5);
	ft_memcpy(str, s + 5, 3);
	printf("\nft_memcpy: %s\n", str);

	printf("\nft_memmove: %s", str + 4);
	printf("\nft_memmove: %s", tmp);
	ft_memmove(str + 4, tmp, 3);
	printf("\nft_memmove: %s\n", str);

	len = ft_strncmp(str, s, 1);
	printf("\nft_strncmp: %d\n", (int)len);

	len = ft_memcmp(str, s + 5, 3);
	printf("\nft_memcmp: %d\n", (int)len);

	printf("\nft_strnstr: %s\n", ft_strnstr(str, "1 9", sizeof(str)));

	ft_memset(str + 3, '9', 1);
	printf("\nft_strrchr: %s", str);
	printf("\nft_strrchr: %s\n", ft_strrchr(str, '9'));

	printf("\nft_strchr: %s", str);
	printf("\nft_strchr: %s\n", ft_strchr(str, '9'));
	ft_memset(str + 3, '*', 1);

	printf("\nft_memchr: %s", str);
	printf("\nft_memchr: %s\n", (char *)ft_memchr(str, ' ', sizeof(str)));
	
	if (tmp) free(tmp);

	tmp = ft_strjoin(str, str + 3);
	ft_memmove(tmp, str + 4, 3);
	printf("\nft_strjoin: %s\n", tmp);

	printf("\nft_strlcpy: %ld", ft_strlcpy(tmp + 8, str, 4));
	printf("\nft_strlcpy: %s\n", tmp);

	printf("\nft_strtrim: %s\n", ft_strtrim(tmp, "2198"));

	ft_striteri(tmp, minus_1);
	printf("\nft_striteri: %s\n", tmp);

	new = ft_strmapi(tmp, char_plus_1);
	printf("\nft_strmapi: %s\n", new);

	printf("\nstring str: %s", str);
	printf("\nstring tmp: %s", tmp);
	printf("\nstring new: %s\n", new);

	char **split = ft_split(new, '*');
    if (split)
    {
        i = 0;
		printf("\n");
		while(split[i] != NULL)
		{
			printf("ft_split: %s\n", split[i]);
			i++;
		}
		i = 0;
		while(split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
        free(split);    
    }

	ft_bzero(str, ft_strlen(str));
	ft_bzero(tmp, ft_strlen(tmp));
	ft_bzero(new, ft_strlen(new));
	
	ft_memset(str, 1, 1);
	ft_memset(tmp, 272, 1);
	ft_memset(new, -1, 1);
	printf("\nstring str: %d", *((int *)str));
	printf("\nstring tmp: %d", *((int *)tmp));
	printf("\nstring new: %d\n", *((int *)new));

	if (str) free(str);
	if (tmp) free(tmp);
	if (new) free(new);

	arr = ft_calloc(2, 4);
	i = 0;
	while(i < 2)
	{
		printf("\nint arr[%ld]: %d", i, *(arr + i));
		i++;
	}
	printf("\n");
	if (arr) free(arr);
}
*/
