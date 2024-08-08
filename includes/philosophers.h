/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:51:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/08 18:14:42 by cyferrei         ###   ########.fr       */
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

/*all structs*/

typedef struct s_philo
{
	struct s_data	*data;
	int				r_fork;
	int				l_fork;
	int				id;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				tm_die;
	int				tm_eat;
	int				tm_sleep;
	int				nb_lunch;
	int				nb_forks;
	bool			dead;
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
void				init_philo(t_data *data);

/*print_debug*/

void				print_data_struct(t_data *data, int argc);
void				print_philos(t_data *data);

/*threads*/

void				create_threads(t_data *data);
void				init_thread_philo(t_data *data, pthread_t *threads, int i);
void				join_thread(t_data *data, pthread_t *threads, int i);

/*errors*/

void				hdl_err_threads(t_data *data, char *msg);

#endif