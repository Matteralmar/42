/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:26:04 by gvasylie          #+#    #+#             */
/*   Updated: 2026/01/27 13:26:31 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach_start(t_philos *philo, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_detach(philo[i].th);
		i++;
	}
}

void	detach_from(t_philos *philo, int st)
{
	while (st < philo->info->n_ph)
	{
		pthread_detach(philo[st].th);
		st++;
	}
}

void	cleanup(t_info *info, t_philos *philos)
{
	int	i;

	if (!info)
		return ;
	if (info->forks_mutex)
	{
		i = 0;
		while (i < info->n_ph)
		{
			pthread_mutex_destroy(&info->forks_mutex[i]);
			i++;
		}
		free(info->forks_mutex);
	}
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->death_mutex);
	if (philos)
		free(philos);
	free(info);
}
