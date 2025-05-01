/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:33:57 by aartimez          #+#    #+#             */
/*   Updated: 2025/04/29 17:58:05 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	total_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1);
	return (len + 1);
}

void	fill_str(char *res, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			res[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				res[k++] = sep[j++];
		}
		i++;
	}
	res[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		len;

	if (size == 0)
	{
		res = (char *)malloc(1 * sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	len = total_len(size, strs, sep);
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	fill_str(res, strs, sep, size);
	return (res);
}

// #include <stdio.h>

// int main(void)
// {
//     char *strs1[] = {"Hello", "World", "Test"};
//     char *strs2[] = {"Hello", "", "Test"};
//     char *strs3[] = {"Alone"};
//     char *strs4[] = {"One", "Two", "Three", "Four", "Five"};
//     char *strs5[] = {"", "", ""};
//     char *result;

//     // Test 1: Basic join
//     result = ft_strjoin(3, strs1, "-");
//     printf("%s\n", result);
//     free(result);

//     // Test 2: Separator is empty
//     result = ft_strjoin(3, strs1, "");
//     printf("%s\n", result);
//     free(result);

//     // Test 3: Some strings are empty
//     result = ft_strjoin(3, strs2, "-");
//     printf("%s\n", result);
//     free(result);

//     // Test 4: Only one string
//     result = ft_strjoin(1, strs3, "-");
//     printf("%s\n", result);
//     free(result);

//     // Test 5: Size is zero
//     result = ft_strjoin(0, strs1, "-");
//     printf("%s\n", result);
//     free(result);

//     // Test 6: Larger input with multi-char separator
//     result = ft_strjoin(5, strs4, ", ");
//     printf("%s\n", result);
//     free(result);

//     // Test 7: All strings are empty
//     result = ft_strjoin(3, strs5, "-");
//     printf("%s\n", result);
//     free(result);

//     return 0;
// }