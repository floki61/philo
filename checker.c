/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:35:47 by oel-berh          #+#    #+#             */
/*   Updated: 2022/06/19 03:57:13 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	data_init(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philo[i].id = i;
		philo[i].num_of_meals = 0;
		philo[i].last_meal = gettime();
		philo[i].data = data;
		i++;
	}
}

int	mutex_init(t_data *data)
{
	int	i;
	int	nbr_of_philo;

	i = -1;
	nbr_of_philo = data->n_philo;
	data->fork = malloc(sizeof(pthread_mutex_t) * nbr_of_philo);
	data->th = malloc(sizeof(pthread_t) * nbr_of_philo);
	pthread_mutex_init(&data->print, NULL);
	while (++i < nbr_of_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	return (0);
}

static int	read_data(t_data *data, int argc, char **argv)
{
	if (ft_atoi(argv[1]) == 0)
		return (1);
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_meals = -1;
	if (argc == 6)
		data->n_meals = ft_atoi(argv[5]);
	return (0);
}

static int	check_arg(char *argv[])
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		n = 0;
		while (ft_strlen(argv[i]) > n)
		{
			if (!ft_isdigit(argv[i][n]))
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

int	par_fun(int argc, char **argv, t_data **data, t_philo **philo)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error Invalid arg\n");
		exit(0);
	}
	*data = malloc(sizeof(t_data));
	if (check_arg(argv) || read_data(*data, argc, argv))
	{
		printf("Error Invalid arg\n");
		exit(0);
	}
	*philo = malloc(sizeof(t_philo) * (*data)->n_philo);
	return (0);
}
