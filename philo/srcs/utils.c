#include "../include/philo.h"

int	input_checker(char** av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				continue;
			}
			if (av[i][j] >= '0' && av[1][i] <= '9')
				return (ft_error(ERR_IN_1, NULL));
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_error(char* str, t_data* data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}

void	ft_exit(t_data* data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->write);
	clear_data(data);
}

void	clear_data(t_data* data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philos);
}