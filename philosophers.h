/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:10:00 by oel-berh          #+#    #+#             */
/*   Updated: 2022/06/19 03:58:13 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
// # include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	long			start_philo;
	pthread_t		*th;
}	t_data;

typedef struct s_node
{
	int				id;
	int				num_of_meals;
	long			start_philo;
	long			last_meal;
	t_data			*data;
}	t_philo;

//checker
void				data_init(t_data *data, t_philo *philo);
int					mutex_init(t_data *data);
int					par_fun(int argc, char **argv,
						t_data **data, t_philo **philo);
//print
void				print(t_philo *philo, int i);
//sonar
int					sonar(t_data *data, t_philo *philo);
//threads
void				creat_philo1(t_data *data, t_philo *philo);
void				creat_philo2(t_data *data, t_philo *philo);
//tools
int					ft_isdigit(int c);
long long			ft_atoi(const char *str);
int					ft_strlen(char *str);
long				gettime(void);
void				sleepi(unsigned long t_sleep);
#endif