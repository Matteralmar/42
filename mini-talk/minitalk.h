/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:09:40 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/06 10:09:40 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_inf
{
	unsigned int	len;
	char			letter;
	int				bit_pos1;
	char			*str;
	unsigned int	i;
	int				bit_pos2;
}	t_inf;

#endif
