#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <time.h>
# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <pthread.h>


# define ALLOC_ERR_1 "ERROR WHILE ALLOCATING THREADS IDs"
# define ALLOC_ERR_2 "ERROR WHILE ALLOCATING PHILOS"
# define ALLOC_ERR_3 "ERROR WHILE ALLOCATING FORKS"

# define ERR_IN_1 "INVALID INPUT CHARACTER"
# define ERR_IN_2 "INVALID INPUT VALUES"

# define TH_ERR "ERROR WHILE CREATING THREADS"
# define JOIN_ERR "ERROR WHILE JOINING THREADS"
# define INIT_ERR_1 "ERROR WHILE INIT FORKS"

# define TIME_ERR "UNABLE TO RETRIVE UTC"

# define FORK "has taking a fork"
# define EAt "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define LEFT 0
# define RIGHT 1

struct s_data;

typedef struct s_philo
{
	struct s_data* data;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t* r_fork;
	pthread_mutex_t* l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t* tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo* philos;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t* forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;


int			ft_atoi(const char* str);
int			input_checker(char** av);
int			ft_error(char* str, t_data *data);
void		ft_exit(t_data* data);
int			init_data(t_data* data, int ac, char** av);
int			init(t_data* data, int ac, char** av);
int			alloc(t_data* data);
void		clear_data(t_data* data);
int			init_forks(t_data* data);

#endif
