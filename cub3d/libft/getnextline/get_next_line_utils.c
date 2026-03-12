/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:33:13 by codespace         #+#    #+#             */
/*   Updated: 2026/03/03 20:57:51 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		k;

	if (!s2)
		s2 = ft_strdup_gnl("");
	temp = (char *)malloc((gnlen(s1) + gnlen(s2) + 1) * sizeof(char));
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
	free(s1);
	temp[i] = '\0';
	return (free(s2), temp);
}

size_t	gnlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchrmod(const char *s, int c)
{
	int		i;
	char	*start;

	i = 0;
	start = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			start = &((char *)s)[i + 1];
			break ;
		}
		i++;
	}
	if (s[i] == (char)c)
		start = &((char *)s)[i + 1];
	return (start);
}

char	*ft_strdup_gnl(const char *s1)
{
	char				*temp;
	unsigned int		i;

	temp = malloc((gnlen(s1) + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < gnlen(s1))
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

// char	*end_of_line(char *buff)
// {
// 	int		i;
// 	char	*buffer;

// 	i = 0;
// 	buffer = ft_strdup(buff);
// 	while (buffer[i] != '\0'  && buffer[i] != '\n' ){
// 		i++;
// 		if (buffer[i] == '\n'){
// 			i++;
// 			break;
// 		}
// 	}
// 	free(buff);
// 	buffer[i] = '\0';
// 	return (buffer);
// }

char	*end_of_line(char *buff)
{
	int		i;
	char	*buffer;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	buffer = malloc(i + 1);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		buffer[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		buffer[i] = '\n';
		i++;
	}
	free(buff);
	buffer[i] = '\0';
	return (buffer);
}
