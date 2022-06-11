#include "philosophers.h"

void print(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->print);
	if(i == 0)
		printf("%zu %d has taken a fork\n", gettime() - philo->p_time, philo->id);
	else if(i == 1)
		printf("%zu %d is eating\n", gettime(NULL) - philo->p_time, philo->id);
	else if(i == 2)
		printf("%zu %d is sleeping\n", gettime(NULL) - philo->p_time, philo->id);
	else if(i == 3)
		printf("%zu %d is thinking\n", gettime(NULL) - philo->p_time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	*routine(void *philo)
{
	t_philo  *ph = (t_philo *)philo;

	while(1)
	{
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

	i = 0;
	i2 = 0;
	while(i2 < 2)
	{
		i = i2;
		while(i < data->n_philo)
		{
			philo[i].id = i + 1; 
			philo[i].data = data;
			philo[i].p_time = gettime();
			// philo[i].last_meal = time(NULL);
			if (pthread_create(&philo[i].philo, NULL, routine, &philo[i]) == -1)
				 printf("Error : Thread can't be created");
			i += 2;
		}
		if (i2 == 0)
			usleep(100);
		i2++;
	}
	while(1)
	{
		sleep(1);
		return (0);
	}
}
int read_data(t_data *data, int argc, char **argv)
{
	if(ft_atoi(argv[1]) <= 0)
		return (1);
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		data->t_pme = ft_atoi(argv[5]);
	return (0);
}
int	mutex_init(t_data *data)
{
	int i;
	int x;

	i = 0;
	x = data->n_philo;
	data->fork = malloc(sizeof(pthread_mutex_init) * x);
	if(pthread_mutex_init(&data->print, NULL) == -1)
		printf("Error mutex init has failed\n");
	data->dead = malloc(sizeof(pthread_mutex_init) * i);
	while(i < x)
	{
		if(pthread_mutex_init(&data->fork[i], NULL) == -1)
			printf("Error mutex init has failed\n");
		if(pthread_mutex_init(&data->dead[i], NULL) == -1)
			printf("Error mutex init has failed\n");
		i++;
	}
	return (0);
}
int ft_philo(t_data *data, t_philo *philo)
{
	philo = malloc(sizeof(t_philo) * data->n_philo);
	mutex_init(data);
	creat_philo(data, philo);
	return (0);
}

int main(int argc, char **argv)
{
	t_data *data;
	t_philo *philo;

	philo = NULL;
	data = malloc(sizeof(t_data));
	if(argc == 5 || argc == 6)
	{
		if (check_arg(argv) || read_data(data, argc, argv))
		{
			printf("Error Invalid arg\n");
			return (1);
		}
	}
	else
	{
		printf("Error Invalid arg\n");
		return (1);
	}
	ft_philo(data, philo);
	return (0);
}