/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:00:06 by gvasylie          #+#    #+#             */
/*   Updated: 2025/06/07 15:00:06 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>

int		pr_chr(int c);
size_t	pr_numb(int n);
size_t	pr_str(char *s);
size_t	pr_unumb(unsigned int n);
size_t	pr_hex(uintptr_t nbr, char *base);
size_t	pr_ptr(void *ptr);
int		ft_printf(const char *format, ...);
#endif