/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:12:54 by gvasylie          #+#    #+#             */
/*   Updated: 2025/06/29 13:12:16 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*append_stash(int fd, char *buffer, char *stash)
{
	ssize_t	n;
	char	*tmp;

	if (ft_strchr(stash, '\n'))
		return (free(buffer), stash);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		if (!tmp)
			return (free(buffer), NULL);
		stash = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (n < 0)
		return (free(stash), NULL);
	return (stash);
}

char	*rtrn_stash(char **stash)
{
	char	*rtrn;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	rtrn = ft_substr(*stash, 0, i);
	if (!rtrn)
		return (free(*stash), *stash = NULL, NULL);
	tmp = ft_substr(*stash, i, ft_strlen(*stash) - i);
	free(*stash);
	if (!tmp)
		return (free(rtrn), *stash = NULL, NULL);
	*stash = tmp;
	return (rtrn);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*rtrn;
	static char	*stash[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(1);
		if (!stash[fd])
			return (free(buffer), NULL);
		*stash[fd] = '\0';
	}
	stash[fd] = append_stash(fd, buffer, stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	rtrn = rtrn_stash(&stash[fd]);
	if (!rtrn)
		return (NULL);
	return (rtrn);
}

// int main() {
// 	int fd1 = open("txt.txt", O_RDONLY);
// 	int fd2 = open("new.txt", O_RDONLY);
// 	int tmp;
// 	char *line1;
// 	tmp = fd1;
// 	while((line1 = get_next_line(tmp)) != NULL)
// 	{
// 		if(tmp == fd1)
// 			tmp = fd2;
// 		else if(tmp == fd2)
// 			tmp = fd1;
// 		printf("%s", line1);
//     	free(line1);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return 0;
// }