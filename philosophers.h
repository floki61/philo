#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t *fork;
	pthread_mutex_t *dead;
	pthread_mutex_t print;
	int 			n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
} 	t_data;

typedef struct s_node
{
	pthread_t philo;
	int id;
	int num_of_meals;
	long start_philo;
	long last_meal;
	t_data		*data;
} t_philo;


int	check_arg(char *argv[]);
void   *sayhey();
long long	ft_atoi(const char *str);
int ft_philo(t_data *data, t_philo *philo);
int	mutex_init(t_data *data);
void print(t_philo *philo, int i);
long	gettime(void);
void sleepi(unsigned long t_sleep);
void    take_a_fork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
int	check_died(t_data *data, t_philo *philo);
#endif