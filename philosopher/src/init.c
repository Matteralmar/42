/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:26:09 by gvasylie          #+#    #+#             */
/*   Updated: 2026/01/27 13:26:31 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11
		|| str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LLONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			return (LLONG_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	init_philos(t_philos *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_ph)
	{
		philos[i].id = i + 1;
		philos[i].meal_c = 0;
		philos[i].lst_meal = info->st_time;
		philos[i].l_fork = i;
		philos[i].r_fork = (i + 1) % info->n_ph;
		philos[i].info = info;
		i++;
	}
}

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

int	init_info(t_info *info, int ac, char **av, int i)
{
	info->n_ph = ft_atoi(av[1]);
	info->t_die = ft_atoll(av[2]);
	info->t_eat = ft_atoll(av[3]);
	info->t_sleep = ft_atoll(av[4]);
	if (info->n_ph <= 0 || info->t_die <= 0 || info->t_eat < 0
		|| info->t_sleep < 0)
		return (1);
	if (ac == 6 && ft_atoi(av[5]) > 0)
		info->eat_c = ft_atoi(av[5]);
	else if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (1);
	else
		info->eat_c = -1;
	info->death = 0;
	info->st_time = get_time_ms() + 50;
	if (pthread_mutex_init(&info->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&info->death_mutex, NULL) != 0)
		return (1);
	info->forks_mutex = malloc(sizeof(pthread_mutex_t) * info->n_ph);
	if (!info->forks_mutex)
		return (1);
	while (i < info->n_ph)
		pthread_mutex_init(&info->forks_mutex[i++], NULL);
	return (0);
}
