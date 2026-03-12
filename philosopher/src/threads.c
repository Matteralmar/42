/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:26:23 by gvasylie          #+#    #+#             */
/*   Updated: 2026/01/27 13:26:24 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (get_time_ms() < philo->info->st_time)
		usleep(100);
	if (philo->id % 2)
		usleep(1000);
	while (1)
	{
		if (eating(philo, 0, 0) || sleeping(philo) || thinking(philo))
			break ;
	}
	return (NULL);
}

void	*philosopher(t_philos *philo)
{
	while (get_time_ms() < philo->info->st_time)
		usleep(100);
	pthread_mutex_lock(&philo->info->forks_mutex[philo->l_fork]);
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("%lld %d has taken a fork\n",
		get_time_ms() - philo->info->st_time,
		philo->id);
	pthread_mutex_unlock(&philo->info->print_mutex);
	usleep(philo->info->t_die * 1000);
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("%lld %d died\n",
		get_time_ms() - philo->info->st_time,
		philo->id);
	pthread_mutex_unlock(&philo->info->print_mutex);
	pthread_mutex_unlock(&philo->info->forks_mutex[philo->l_fork]);
	return (NULL);
}

int	join_th(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->n_ph)
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (detach_from(philo, i), 1);
		i++;
	}
	if (pthread_join(philo->info->monitoring_th, NULL) != 0)
		return (1);
	return (0);
}

int	create_threads(t_info *info, t_philos *philo)
{
	int	i;

	i = 0;
	while (i < info->n_ph)
	{
		if (pthread_create(&philo[i].th, NULL, &routine, &philo[i]) != 0)
			return (detach_start(philo, i), 1);
		i++;
	}
	return (0);
}
