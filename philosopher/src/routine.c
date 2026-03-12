/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaligula <kaligula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:26:20 by gvasylie          #+#    #+#             */
/*   Updated: 2026/02/13 11:22:54 by kaligula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->info->death_mutex);
	if (philo->info->death)
		return (pthread_mutex_unlock(&philo->info->death_mutex), 1);
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("%lld %d has taken a fork\n",
		get_time_ms() - philo->info->st_time, philo->id);
	printf("%lld %d has taken a fork\n",
		get_time_ms() - philo->info->st_time, philo->id);
	printf("%lld %d is eating\n",
		get_time_ms() - philo->info->st_time, philo->id);
	pthread_mutex_unlock(&philo->info->print_mutex);
	pthread_mutex_unlock(&philo->info->death_mutex);
	return (0);
}

void	philo_eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->info->death_mutex);
	philo->lst_meal = get_time_ms();
	pthread_mutex_unlock(&philo->info->death_mutex);
	print_eating(philo);
	usleep(philo->info->t_eat * 1000);
	pthread_mutex_lock(&philo->info->death_mutex);
	philo->lst_meal = get_time_ms();
	philo->meal_c++;
	pthread_mutex_unlock(&philo->info->death_mutex);
}

int	eating(t_philos *philo, int first, int second)
{
	pthread_mutex_lock(&philo->info->death_mutex);
	if (philo->info->death)
		return (pthread_mutex_unlock(&philo->info->death_mutex), 1);
	pthread_mutex_unlock(&philo->info->death_mutex);
	if (philo->l_fork < philo->r_fork)
	{
		first = philo->l_fork;
		second = philo->r_fork;
	}
	else
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	pthread_mutex_lock(&philo->info->forks_mutex[first]);
	pthread_mutex_lock(&philo->info->forks_mutex[second]);
	philo_eating(philo);
	pthread_mutex_unlock(&philo->info->forks_mutex[second]);
	pthread_mutex_unlock(&philo->info->forks_mutex[first]);
	return (0);
}

int	thinking(t_philos *philo)
{
	long long	t_think;

	pthread_mutex_lock(&philo->info->death_mutex);
	if (philo->info->death)
		return (pthread_mutex_unlock(&philo->info->death_mutex), 1);
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("%lld %d is thinking\n",
		get_time_ms() - philo->info->st_time, philo->id);
	pthread_mutex_unlock(&philo->info->print_mutex);
	pthread_mutex_unlock(&philo->info->death_mutex);
	t_think = philo->info->t_die - (philo->info->t_eat + philo->info->t_sleep);
	if (t_think > 0)
		usleep((t_think / 2) * 1000);
	return (0);
}

int	sleeping(t_philos *philo)
{
	long long	start;

	pthread_mutex_lock(&philo->info->death_mutex);
	if (philo->info->death)
		return (pthread_mutex_unlock(&philo->info->death_mutex), 1);
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("%lld %d is sleeping\n",
		get_time_ms() - philo->info->st_time, philo->id);
	pthread_mutex_unlock(&philo->info->print_mutex);
	pthread_mutex_unlock(&philo->info->death_mutex);
	start = get_time_ms();
	while (get_time_ms() - start < philo->info->t_sleep)
	{
		pthread_mutex_lock(&philo->info->death_mutex);
		if (philo->info->death)
			return (pthread_mutex_unlock(&philo->info->death_mutex), 1);
		pthread_mutex_unlock(&philo->info->death_mutex);
		usleep(1000);
	}
	return (0);
}
