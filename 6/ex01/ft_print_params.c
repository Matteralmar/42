/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:39:42 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/22 17:51:45 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	n;
	int		i;
	int		j;

	if (argc > 1)
	{
		n = '\n';
		i = 0;
		j = 1;
		while (argv[j])
		{
			while (argv[j][i])
			{
				write(1, &argv[j][i], 1);
				i++;
			}
			write(1, &n, 1);
			i = 0;
			j++;
		}
	}
	return (0);
}
