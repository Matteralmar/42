/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:26:12 by gvasylie          #+#    #+#             */
/*   Updated: 2026/01/27 13:26:29 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info		*info;
	t_philos	*philos;

	if (ac != 5 && ac != 6)
		return (printf("Argument specification error\n"), 1);
	info = malloc(sizeof(t_info));
	if (!info)
		return (printf("Malloc allocation error\n"), 1);
	memset(info, 0, sizeof(t_info));
	if (init_info(info, ac, av, 0))
		return (free(info), printf("Initialization of info failed\n"), 1);
	philos = malloc(sizeof(t_philos) * info->n_ph);
	if (!philos)
		return (printf("Malloc allocation error\n"), cleanup(info, philos), 1);
	memset(philos, 0, sizeof(t_philos) * info->n_ph);
	init_philos(philos, info);
	if (info->n_ph == 1)
		return (philosopher(&philos[0]), cleanup(info, philos), 1);
	if (create_threads(info, philos))
		return (printf("Thread creation error\n"), cleanup(info, philos), 1);
	if (monitor_threads(info, philos))
		return (printf("Thread monitor failed\n"), cleanup(info, philos), 1);
	if (join_th(philos))
		return (printf("Thread join error\n"), cleanup(info, philos), 1);
	return (cleanup(info, philos), 0);
}
