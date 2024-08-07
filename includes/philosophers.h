/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:51:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/07 17:21:19 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*all includes*/

# include "libft.h"
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

/*all structs*/

typedef struct s_philo
{
	t_data *data;
}			t_philo;

typedef struct s_data
{
	int	nb_philo;
	int	tm_die;
	int	tm_eat;
	int	to_sleep;
	int	nb_lunch;
	int	nb_forks;
	bool dead;
	struct t_philo *philo;
}			t_data;

/*parsing*/

void	parse_philo(int argc, char **argv, char **envp);
void	check_envp(char	**envp);
void	check_nb_args(int argc);
void	check_digit(char **argv);
void	check_overflow(char **argv);
void	check_nb_philo(char **argv);
void	check_time(char **argv);

#endif