/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:56:52 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/16 11:18:19 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_print_dead_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("Philosopher [%d] died\n", philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_print_think_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("Philosopher [%d] is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_print_sleep_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("Philosopher [%d] is sleeping\n", philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

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
