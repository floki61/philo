#include "philosophers.h"

size_t gettime()
{
	struct timeval time;
	size_t time_ms;

	gettimeofday(&time, NULL);
	time_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_ms);
}
void sleepi(unsigned long t_sleep)
{
	// size_t s_time;
	// s_time = gettime();
	usleep(t_sleep);

}

void    take_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	print(philo, 0);
	pthread_mutex_lock(&philo->data->fork[philo->id % philo->data->n_philo]);
	print(philo, 0);
}

void	eating(t_philo *philo)
{
	philo->last_meal = gettime();
	print(philo, 1);
	sleepi(philo->data->t_eat * 1000);
	philo->n_meal += 1;
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->fork[philo->id % philo->data->n_philo]);
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
