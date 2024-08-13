/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:41:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/13 18:04:35 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_print_eat_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->checker_lunch);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("Philosopher [%d] is eating\n", philo->id);
	philo->lst_lunch = get_curr_time();
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_unlock(&philo->data->checker_lunch);
}

void	ft_print_forks_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("Philosopher [%d] took a fork\n", philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

long	get_curr_time()
{
	struct timeval	tv;
	long	res_conv;

	res_conv = ZERO_INIT;
	gettimeofday(&tv, NULL);
	res_conv = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return(res_conv);
}