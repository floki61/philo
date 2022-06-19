/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:30:16 by oel-berh          #+#    #+#             */
/*   Updated: 2022/06/19 03:58:39 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (1)
	{
		pthread_mutex_lock(&philo->data->fork[philo->id]);
		print(philo, 0);
		pthread_mutex_lock(&philo->data->fork
		[(philo->id + 1) % philo->data->n_philo]);
		print(philo, 0);
		print(philo, 1);
		philo->last_meal = gettime();
		sleepi(philo->data->t_eat * 1000);
		pthread_mutex_unlock(&philo->data->fork[philo->id]);
		pthread_mutex_unlock(&philo->data->fork
		[(philo->id + 1) % philo->data->n_philo]);
		philo->num_of_meals += 1;
		print(philo, 2);
		sleepi(philo->data->t_sleep * 1000);
		print(philo, 3);
	}
	return (NULL);
}

void	creat_philo2(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (++i < data->n_philo)
	{
		if (i % 2 == 1)
		{
			philo[i].start_philo = gettime();
			pthread_create(&data->th[i], NULL, &routine, &philo[i]);
		}	
	}
}

void	creat_philo1(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	data->start_philo = gettime();
	while (++i < data->n_philo)
	{
		if (i % 2 == 0)
		{
			philo[i].start_philo = gettime();
			pthread_create(&data->th[i], NULL, &routine, &philo[i]);
		}
	}
	usleep(300);
}
