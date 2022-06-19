/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:49:56 by oel-berh          #+#    #+#             */
/*   Updated: 2022/06/19 03:43:06 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	philo = NULL;
	data = NULL;
	par_fun(argc, argv, &data, &philo);
	mutex_init(data);
	data_init(data, philo);
	creat_philo1(data, philo);
	creat_philo2(data, philo);
	sonar(data, philo);
	return (0);
}
