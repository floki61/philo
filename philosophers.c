#include "philosophers.h"

void print(t_philo *philo, int i)
{
	long time;
	pthread_mutex_lock(&philo->data->print);
	// printf("%ld %ld %d\n",gettime(),philo->data->start_philo, philo->id);
	// printf("philo num = %d\n",philo->id);
	time = gettime() - philo->data->start_philo;

	// printf("time %ld\n", time);
	// printf("gettime %ld\n", gettime());
	// printf("start philo %ld\n", philo->data->start_philo);

	if(i == 0)
		printf("%ld %d has taken a fork\n", time, philo->id);
	else if(i == 1)
		printf("%ld %d is eating\n", time, philo->id);
	else if(i == 2)
		printf("%ld %d is sleeping\n", time, philo->id);
	else if(i == 3)
		printf("%ld %d is thinking\n", time, philo->id);
	else if(i == 4)
		printf("%ld %d is died\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	*routine(void *philo)
{
	t_philo  *ph = (t_philo *)philo;

	while(1)
	{
		// printf("philo num = %d\n",ph->id);
		take_a_fork(ph);
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return (NULL);
}

int	creat_philo(t_data *data, t_philo *philo)
{
	int i;
	int i2;
	int j;

	i = 0;
	i2 = 0;
	// data->start_philo = gettime();
	// while(i2 < 2)
	// {
	// 	i = i2;
		while(i < data->n_philo)
		{
			philo[i].id = i + 1; 
			philo[i].start_philo = gettime();
			philo[i].num_of_meals = 0;
			philo[i].last_meal = gettime();
			philo[i].data = data;
			pthread_create(&data->th[i], NULL, routine, &philo[i]);
			// printf("id in creation: %d\n", philo[i].id);
			usleep(100);
			i += 1;
		}
		// if (i2 == 0)
		// i2++;
	// }
	return (0);
}

int	check_died(t_data *data, t_philo *philo)
{
	int i;
	int j;

	while(1)
	{
		i = -1;
		j = 0;
		if(data->n_meals == 0)
			exit(0);
		else if(data->n_meals != -1)
		{
			while(++i < data->n_philo)
				if(philo[i].num_of_meals >= data->n_meals)
					j++;
			if(j == data->n_philo)
			{
				printf("n_meals\n");
				pthread_mutex_lock(&philo->data->print);
		 		return (1);
			}
		}
		i = -1;
		while(++i < data->n_philo)
		{
			if(gettime() - (philo[i].last_meal) >= data->t_die)
			{
				printf("died\n");
				pthread_mutex_lock(&philo->data->print);
		 		printf("%ld %d is died\n", gettime() - philo[i].data->start_philo, philo[i].id);
				return (1);
			}
		}
	}
}

int read_data(t_data *data, int argc, char **argv)
{
	if(ft_atoi(argv[1]) == 0)
		return (1);
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_meals = -1;
	if(argc == 6)
		data->n_meals = ft_atoi(argv[5]);
	return (0);
}
int	mutex_init(t_data *data)
{
	int i;
	int nbr_of_philo;

	i = -1;
	nbr_of_philo = data->n_philo;
	data->fork = malloc(sizeof(pthread_mutex_init) * nbr_of_philo);
	data->dead = malloc(sizeof(pthread_mutex_init) * nbr_of_philo);
	data->th = malloc(sizeof(pthread_t) * nbr_of_philo);
	pthread_mutex_init(&data->print, NULL);
	while(++i < nbr_of_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_mutex_init(&data->dead[i], NULL);
	}
	return (0);
}

int		par_fun(int argc, char **argv, t_data **data, t_philo **philo)
{
	if(argc != 5 && argc != 6)
	{
		printf("Error Invalid arg\n");
		exit(0);
	}
	*data = malloc(sizeof(t_data));
	if(check_arg(argv) || read_data(*data, argc, argv))
	{
		printf("Error Invalid arg\n");
			exit(0);
	 }
	*philo = malloc(sizeof(t_philo) * (*data)->n_philo);
	 return (0);
}
int main(int argc, char **argv)
{
	t_data *data;
	t_philo *philo;

	philo = NULL;
	data = NULL;
	par_fun(argc, argv, &data, &philo);
	mutex_init(data);
	creat_philo(data, philo);
	check_died(data, philo);
	return (0);
}