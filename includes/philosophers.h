/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:51:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/20 14:47:15 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*all includes*/

# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/*all defines*/

# define ZERO_INIT 0

/*all structs*/

typedef struct s_philo
{
	int				id;
	int				nb_lunch_philo;
	int				lft_f_id;
	int				rgt_f_id;
	time_t			lst_lunch;
	pthread_t		thread_id;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	time_t			tm_die;
	time_t			tm_eat;
	time_t			tm_sleep;
	time_t			start;
	int				nb_lunch;
	int				all_lunch;
	bool			dead;
	pthread_mutex_t	dead_mtx;
	pthread_mutex_t	*forks;
	pthread_mutex_t	checker_lunch;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	time_die_mtx;
	pthread_mutex_t	all_lunch_mtx;
	pthread_mutex_t	nb_lunch_mtx;
	t_philo			*philo;
}					t_data;

/*parsing*/

void				parse_philo(int argc, char **argv, char **envp);
void				check_envp(char **envp);
void				check_nb_args(int argc);
void				check_digit(char **argv);
void				check_overflow(char **argv);
void				check_nb_philo(char **argv);
void				check_time(char **argv);
void				check_nb_lunch(char **argv);

/*init*/

void				init_data(int argc, char **argv, t_data **data);
void				init_philo(t_data *data);
void				init_mutex(t_data *data);
void				init_mutex_two(t_data *data);
void				set_value(t_data **data, char **argv, int argc);

/*print*/

void				print_data_struct(t_data *data, int argc);
void				print_philos(t_data *data);
void				ft_print_forks_mutex(t_philo *philo);
void				ft_print_eat_mutex(t_philo *philo);
void				ft_print_sleep_mutex(t_philo *philo);
void				ft_print_think_mutex(t_philo *philo);
void				ft_print_dead_mutex(t_philo *philo);

/*threads*/

int					checker(t_philo *philo, t_data *data_ref);
int					checker_two(t_philo *philo, t_data *data_ref);
int					checker_three(t_philo *philo, t_data *data_ref);
void				sub_routine(t_philo *philo, t_data *data_ref);
int					forks_routine(t_data *data_ref, t_philo *philo);
int					case_one_philo(t_data *data, int i);
int					ft_check_philosophers(t_data *data);
void				create_threads(t_data *data);
void				init_thread_philo(t_data *data, pthread_t *threads, int i);
void				join_thread(t_data *data, pthread_t *threads, int i);
time_t				get_curr_time(void);
void				eat_and_check(t_data *data);
void				sleep_and_check(t_data *data);
int					checker_all_ate(t_data *data);
void				ft_supervisor(t_data *data);
void				*routine_solo(void *arg);
void				routine_part_two(t_data *data_ref, t_philo *philo);
void				*routine(void *arg);

/*getter - setter*/

void				setter_nb_lunch(pthread_mutex_t *mtx, int *nb_lunch,
						int value);
int					getter_nb_lunch(pthread_mutex_t *mtx, int *nb_lunch);
void				setter_all_luch(pthread_mutex_t *mtx, int *all_ate,
						int value);
int					getter_all_ate(pthread_mutex_t *mtx, int *all_ate);
time_t				getter_time(pthread_mutex_t *mtx, time_t *time);
void				setter_time(pthread_mutex_t *mtx, time_t *time,
						time_t value);
void				setter(pthread_mutex_t *mtx, bool *dead, bool value);
bool				getter(pthread_mutex_t *mtx, bool *dead);

/*errors - free*/

void				free_handler(t_data *data);
void				hdl_err_philo(t_data *data, char *msg);
void				hdl_err_mutex(t_data *data, char *msg);

/*functions utils*/

int					ft_strncmp(const char *first, const char *second,
						size_t length);
int					ft_isdigit(int c);
int					ft_int_len(int n);
char				*ft_itoa(int n);
int					ft_atoi(const char *nbr);
size_t				ft_strlen(const char *s);

#endif