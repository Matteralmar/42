/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaligula <kaligula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:26:16 by gvasylie          #+#    #+#             */
/*   Updated: 2026/02/09 13:51:24 by kaligula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death(t_philos *philos, int i)
{
	if (get_time_ms() - philos[i].lst_meal >= philos->info->t_die)
	{
		pthread_mutex_lock(&philos->info->print_mutex);
		printf("%lld %d died\n",
			get_time_ms() - philos->info->st_time, philos[i].id);
		pthread_mutex_unlock(&philos->info->print_mutex);
	}
}

int	eat_chk(int i, int eat_f, t_philos *philos)
{
	int	meals;

	if (philos->info->eat_c != -1)
	{
		while (i < philos->info->n_ph)
		{
			meals = philos[i].meal_c;
			if (meals < philos->info->eat_c)
			{
				eat_f = 0;
				break ;
			}
			eat_f = 1;
			i++;
		}
	}
	return (eat_f);
}

void	*monitor(void *arg)
{
	t_philos	*philos;
	int			i;
	int			eaten_enough;

	philos = (t_philos *)arg;
	while (1)
	{
		i = -1;
		while (++i < philos->info->n_ph)
		{
			pthread_mutex_lock(&philos->info->death_mutex);
			eaten_enough = eat_chk(0, 0, philos);
			if (philos->info->death)
				return (pthread_mutex_unlock(&philos->info->death_mutex), NULL);
			if (get_time_ms() - philos[i].lst_meal >= philos->info->t_die
				|| (philos[i].meal_c == philos->info->eat_c && eaten_enough))
			{
				philos->info->death = 1;
				print_death(philos, i);
				return (pthread_mutex_unlock(&philos->info->death_mutex), NULL);
			}
			pthread_mutex_unlock(&philos->info->death_mutex);
		}
		usleep(100);
	}
}

int	monitor_threads(t_info *info, t_philos *philos)
{
	if (pthread_create(&info->monitoring_th, NULL, &monitor, philos) != 0)
		return (detach_start(philos, philos->info->n_ph), 1);
	return (0);
}
