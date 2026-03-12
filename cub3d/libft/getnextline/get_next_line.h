/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:27:01 by codespace         #+#    #+#             */
/*   Updated: 2026/03/03 20:57:50 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3000
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

char	*ft_strdup_gnl(const char *s1);
char	*ft_strchrmod(const char *s, int c);
size_t	gnlen(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*end_of_line(char *buff);
char	*get_next_line(int fd);

#endif
