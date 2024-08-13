/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:51:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/13 16:03:52 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*all includes*/

# include "libft.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>

/*all defines*/

# define ZERO_INIT 0

/*all structs*/

typedef struct s_philo
{
	int	id;
	int	nb_lunch_philo;
	int	lft_f_id;
	int	rgt_f_id;
	long	lst_lunch;
	pthread_t	thread_id;
	struct s_data		*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				tm_die;
	int				tm_eat;
	int				tm_sleep;
	int				nb_lunch;
	int				all_lunch;
	bool			dead;
	long			start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	checker_lunch;
	pthread_mutex_t	print_mutex;
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
void	init_philo(t_data *data);

/*print_debug*/

void				print_data_struct(t_data *data, int argc);
void				print_philos(t_data *data);

/*threads*/

int					create_threads(t_data *data);
void				init_thread_philo(t_data *data, pthread_t *threads, int i);
void				join_thread(t_data *data, pthread_t *threads, int i);
long				get_curr_time();

/*errors - free*/

void	free_handler(t_data *data);
void				hdl_err_philo(t_data *data, char *msg);
void	hdl_err_mutex(t_data *data, char *msg);

#endif