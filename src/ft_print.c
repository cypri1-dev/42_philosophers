/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:56:52 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/19 14:29:25 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_print_dead_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d died\n", get_curr_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_print_think_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d is thinking\n", get_curr_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_print_sleep_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d is sleeping\n", get_curr_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_print_eat_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d is eating\n", get_curr_time() - philo->data->start, philo->id);
	setter_time(&philo->data->checker_lunch, &philo->lst_lunch, get_curr_time());
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_print_forks_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d  has taken a fork\n", get_curr_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
