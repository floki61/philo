/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sonar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:42:54 by oel-berh          #+#    #+#             */
/*   Updated: 2022/06/19 03:58:28 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_meals(t_data *data, t_philo *philo)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (data->n_meals == 0)
		return (1);
	else if (data->n_meals != -1)
	{
		while (++i < data->n_philo)
			if (philo[i].num_of_meals >= data->n_meals)
				j++;
		if (j == data->n_philo)
		{
			printf("n_meals\n");
			pthread_mutex_lock(&philo->data->print);
			return (1);
		}
	}
	return (0);
}

static int	check_death(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		if ((gettime() - philo[i].last_meal) / 1000 >= data->t_die)
		{
			pthread_mutex_lock(&philo->data->print);
			printf("%ld %d is died\n",
				(gettime() - philo->data->start_philo) / 1000, philo->id + 1);
			return (1);
		}
	}
	return (0);
}

int	sonar(t_data *data, t_philo *philo)
{
	while (1)
	{
		if (check_meals(data, philo))
			return (1);
		if (check_death(data, philo))
			return (1);
	}
}
