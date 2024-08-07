/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:51:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/07 16:38:29 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*all includes*/

# include "libft.h"
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

/*parsing*/

void	parse_philo(int argc, char **argv, char **envp);
void	check_envp(char	**envp);
void	check_nb_args(int argc);
void	check_digit(char **argv);
void	check_overflow(char **argv);
void	check_nb_philo(char **argv);
void	check_time(char **argv);

#endif