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
	pthread_mutex_t *print;
	int 			n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_pme;
} 	t_data;

typedef struct s_node
{
	pthread_t philo;
	int id;
	time_t p_time;
	time_t last_meal;
	t_data		*data;
} t_philo;


int	check_arg(char *argv[]);
void   *sayhey();
long long	ft_atoi(const char *str);
int ft_philo(t_data *data, t_philo *philo);
int	mutex_init(t_data *data);
#endif