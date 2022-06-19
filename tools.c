/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:00:56 by oel-berh          #+#    #+#             */
/*   Updated: 2022/06/19 03:58:47 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	gettime(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_usec + current_time.tv_sec * 1000000));
}

void	sleepi(unsigned long t_sleep)
{
	unsigned long	start_time;

	start_time = gettime();
	usleep(t_sleep - 10000);
	while (((gettime() - start_time)) < t_sleep)
		;
}
