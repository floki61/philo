/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 02:59:17 by oel-berh          #+#    #+#             */
/*   Updated: 2022/06/19 03:58:21 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, int i)
{
	long	time;

	pthread_mutex_lock(&philo->data->print);
	time = (gettime() - philo->data->start_philo) / 1000;
	if (i == 0)
		printf("%ld %d has taken a fork\n", time, philo->id + 1);
	else if (i == 1)
		printf("%ld %d is eating\n", time, philo->id + 1);
	else if (i == 2)
		printf("%ld %d is sleeping\n", time, philo->id + 1);
	else if (i == 3)
		printf("%ld %d is thinking\n", time, philo->id + 1);
	else if (i == 4)
		printf("%ld %d is died\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->data->print);
}
