/* ************************************************************************** */
/*	                                                                      */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:26:40 by codespace         #+#    #+#             */
/*   Updated: 2024/08/20 17:22:55 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	help(char **buff, int bytestread, char **remainder, char **text)
{
	if (*buff)
		(*buff)[bytestread] = '\0';
	*text = ft_strjoin_gnl(*text, *buff);
	if (ft_strchrmod(*text, '\n') != NULL)
	{
		*remainder = ft_strdup_gnl(ft_strchrmod(*text, '\n'));
		if ((*remainder)[0] == '\0')
		{
			free(*remainder);
			*remainder = NULL;
		}
		*text = end_of_line(*text);
		return (0);
	}
	else if (ft_strchrmod(*text, '\n') == NULL && bytestread == 0)
	{
		*remainder = NULL;
		return (0);
	}
	return (1);
}

int	help02(char **buff, int fd)
{
	int	bytestread;

	*buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	bytestread = read(fd, *buff, BUFFER_SIZE);
	if (bytestread <= 0)
	{
		free (*buff);
		*buff = NULL;
	}
	return (bytestread);
}

/* char	*ending_with_nl(char *text)
{
	text[ft_strlen(text)] = '\n';
	text[ft_strlen(text + 1)] = '\0';
	return (text);
} */

int	updated_check(char *remainder, int fd)
{
	if (fd == -3)
	{
		free(remainder);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*text;
	int			bytestread;
	static char	*r;

	if (updated_check(r, fd) == 1 || fd < 0 || BUFFER_SIZE <= 0 || fd > 100)
		return (NULL);
	bytestread = help02(&buff, fd);
	if (bytestread == 0 && r == NULL)
		free(buff);
	if (bytestread < 0 || (bytestread == 0 && r == NULL))
		return (NULL);
	text = ft_strdup_gnl("");
	if (r != NULL)
	{
		free(text);
		text = r;
	}
	while (bytestread > 0 || r != NULL)
	{
		if (help(&buff, bytestread, &r, &text) == 0)
			break ;
		bytestread = help02(&buff, fd);
	}
	return (text);
}

// int	main(void)
// {
// 	int			fd;
// 	const char	*filename;
// 	char		*line;

// 	filename = "tets01.txt";
// 	fd = open(filename, O_RDONLY);
// 	if (fd != -1)
// 		line = get_next_line(fd);
// 	else
// 	{
// 		printf("error openning file\n");
// 		return (-1);
// 	}
// 	int i = 0;
// 	while (i < 25){
// 		if (line != NULL)
// 			printf("%s\n", line);
// 			free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	if (line != NULL)
// 		free(line);
// 	return (0);
// }
