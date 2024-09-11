#include "include/philo.h"


int	main(int ac, char** av) {
	t_data data;
	if (ac < 5 || ac > 6)
		return (EXIT_FAILURE);
	if (input_checker(av))
		return (EXIT_FAILURE);
	if (init(&data, ac, av))
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
