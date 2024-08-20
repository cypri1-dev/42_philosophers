/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:11:42 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/20 14:27:57 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	forks_routine(t_data *data_ref, t_philo *philo)
{
	pthread_mutex_lock(&data_ref->forks[philo->rgt_f_id]);
	if (checker(philo, data_ref))
		return (-1);
	ft_print_forks_mutex(philo);
	pthread_mutex_lock(&data_ref->forks[philo->lft_f_id]);
	if (checker_two(philo, data_ref))
		return (-1);
	ft_print_forks_mutex(philo);
	if (getter(&philo->data->dead_mtx, &philo->data->dead))
		return (-1);
	return (0);
}

void	sub_routine(t_philo *philo, t_data *data_ref)
{
	ft_print_eat_mutex(philo);
	eat_and_check(data_ref);
	setter_nb_lunch(&data_ref->nb_lunch_mtx, &philo->nb_lunch_philo, 1);
	pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
	pthread_mutex_unlock(&data_ref->forks[philo->lft_f_id]);
}

int	checker_three(t_philo *philo, t_data *data_ref)
{
	if (getter(&philo->data->dead_mtx, &philo->data->dead))
		return (-1);
	if (getter_all_ate(&data_ref->all_lunch_mtx, &data_ref->all_lunch))
		return (-1);
	return (0);
}

int	checker_two(t_philo *philo, t_data *data_ref)
{
	if (getter(&philo->data->dead_mtx, &philo->data->dead))
	{
		pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
		pthread_mutex_unlock(&data_ref->forks[philo->lft_f_id]);
		return (1);
	}
	return (0);
}

int	checker(t_philo *philo, t_data *data_ref)
{
	if (getter(&philo->data->dead_mtx, &philo->data->dead))
	{
		pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
		return (1);
	}
	return (0);
}
