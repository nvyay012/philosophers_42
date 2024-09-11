#include "../include/philo.h"

int	init_data(t_data* data, int ac, char** av)
{
	data->philo_num = (int)ft_atoi(av[1]);
	data->death_time = (uint64_t)ft_atoi(av[2]);
	data->eat_time = (uint64_t)ft_atoi(av[3]);
	data->sleep_time = (uint64_t)ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nb = (int)ft_atoi(av[5]);
	else
		data->meals_nb = -1;
	if (data->philo_num <= 0 || data->philo_num >= 200 || data->eat_time == 0
		|| data->sleep_time == 0 || data->death_time == 0)
	{
		return (ft_error(ERR_IN_2, NULL));	
	}
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int	alloc(t_data* data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (ft_error(ALLOC_ERR_1, data));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (ft_error(ALLOC_ERR_2, data));
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		return (ft_error(ALLOC_ERR_3, data));
	return (0);
}

int	init_forks(t_data* data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
	i = 1;
	while (i < data->philo_num)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

void	init_philos(t_data* data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].eat_cont = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int	init(t_data* data, int ac, char** av)
{
	if (init_data(data, ac, av))
		return (1);
	if (alloc(data))
		return (1);
	if (init_forks(data))
		return (1);
	init_philos(data);
	return (0);
}