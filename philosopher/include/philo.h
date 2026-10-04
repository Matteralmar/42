/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:26:01 by gvasylie          #+#    #+#             */
/*   Updated: 2026/01/27 15:00:54 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_info
{
	int				n_ph;
	long long		t_die;
	long long		t_sleep;
	long long		t_eat;
	int				eat_c;
	long long		st_time;
	int				death;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_t		monitoring_th;
	pthread_mutex_t	*forks_mutex;
}	t_info;

typedef struct s_philos
{
	int				id;
	pthread_t		th;
	int				meal_c;
	long long		lst_meal;
	int				l_fork;
	int				r_fork;
	t_info			*info;
}	t_philos;

void		init_philos(t_philos *philos, t_info *info);
int			init_info(t_info *info, int ac, char **av, int i);
long long	get_time_ms(void);
void		*philosopher(t_philos *philo);
int			thinking(t_philos *philo);
int			sleeping(t_philos *philo);
int			eating(t_philos *philo, int first, int second);
int			create_threads(t_info *info, t_philos *philo);
void		cleanup(t_info *info, t_philos *philos);
int			join_th(t_philos *philo);
void		detach_th(t_philos *philo, int n, int start, int tp);
int			monitor_threads(t_info *info, t_philos *philos);
void		detach_start(t_philos *philo, int n);
void		detach_from(t_philos *philo, int st);

#endif
