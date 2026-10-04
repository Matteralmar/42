/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaligula <kaligula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:37:42 by vivantso          #+#    #+#             */
/*   Updated: 2025/10/25 10:06:47 by kaligula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_dprintf(const char *format, ...);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putnbr(int nb, int fd);
int	ft_putnbr_base(unsigned long nbr, char *base, int fd);
int	ft_format(char spec, va_list *args, char **bases, int fd);

#endif
