/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:38:55 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/22 17:51:42 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len_calc(char *argv)
{
	int	o;

	o = 0;
	while (argv[o])
		o++;
	return (o);
}

void	reverse(char n, int j, char **argv)
{
	int	len;
	int	i;

	while (argv[j] != argv[0])
	{
		i = 0;
		len = len_calc(argv[j]);
		while (i < len)
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		write(1, &n, 1);
		j--;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		reverse('\n', argc - 1, argv);
	}
	return (0);
}
