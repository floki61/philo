#include "philosophers.h"

static int	ft_isdigit(int c)
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
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	check_arg(char *argv[])
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
