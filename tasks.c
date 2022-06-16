#include "philosophers.h"

// long gettime()
// {
// 	struct timeval time;
// 	long time_usec;

// 	gettimeofday(&time, NULL);
// 	time_usec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
// 	return (time_usec);
// }
long	gettime(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_usec + current_time.tv_sec * 1000000));
}
void sleepi(unsigned long t_sleep)
{
	unsigned long	start_time;

	start_time = gettime();
	// usleep(t_sleep - 1000);
	while (((gettime() - start_time)) < t_sleep);
}

void    take_a_fork(t_philo *philo)
{
	// printf("hey from thread %d\n",philo->id - 1);
	// printf("get time llwla : %ld\n", gettime());
	printf(" philo number %d is waiting\n", philo->id);
	pthread_mutex_lock(&philo->data->fork[philo->id]);
	// printf("hey from thread %d %d\n",philo->id - 1 ,philo->id  % philo->data->n_philo);
	print(philo, 0);
	pthread_mutex_lock(&philo->data->fork[(philo->id + 1) % philo->data->n_philo]);
	print(philo, 0);
}

void	eating(t_philo *philo)
{
	print(philo, 1);
	philo->last_meal = gettime();
	sleepi(philo->data->t_eat * 1000);
	philo->num_of_meals += 1;
	// printf("%d num of meals == %d\n",philo->id, philo->num_of_meals);
	pthread_mutex_unlock(&philo->data->fork[(philo->id +  1) % philo->data->n_philo]);
	pthread_mutex_unlock(&philo->data->fork[philo->id]);
	printf("unlock  %d %d\n",philo->id,(philo->id + 1) % philo->data->n_philo);
}

void	sleeping(t_philo *philo)
{
	print(philo, 2);
	sleepi(philo->data->t_sleep * 1000);
}
void	thinking(t_philo *philo)
{
	print(philo, 3);
}
