#include "include/philo.h"


int	main(int ac, char** av) {
	if (ac < 5 || ac > 6)
		return (1);
	if (input_checker(av))
		return (1);
	if (init(&data, argv, argc))
                return (1);
}
