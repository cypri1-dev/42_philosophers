/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:59:56 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/20 14:48:50 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	end_threads(t_data *data, int i)
{
	if (data->nb_philo == 1)
		pthread_join(data->philo[i].thread_id, NULL);
	else
	{
		while (--i >= 0)
			pthread_join(data->philo[i].thread_id, NULL);
	}
}

int	checker_all_ate(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while (i < data->nb_philo
		&& data->philo[i].nb_lunch_philo >= getter_nb_lunch(&data->nb_lunch_mtx,
			&data->nb_lunch))
		i++;
	if (i == data->nb_philo)
	{
		setter_all_luch(&data->all_lunch_mtx, &data->all_lunch, 1);
		return (1);
	}
	return (0);
}

void	ft_supervisor(t_data *data)
{
	while (!getter(&data->dead_mtx, &data->dead) || data->all_lunch == 1)
	{
		if (ft_check_philosophers(data))
			return ;
		if (getter(&data->dead_mtx, &data->dead))
			return ;
		if (data->nb_lunch != -1)
		{
			if (checker_all_ate(data))
				break ;
		}
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data_ref;

	philo = (t_philo *)arg;
	data_ref = philo->data;
	if (philo->id % 2)
		usleep(15000);
	while (!getter(&data_ref->dead_mtx, &data_ref->dead))
	{
		if (forks_routine(data_ref, philo))
			return (NULL);
		sub_routine(philo, data_ref);
		if (checker_three(philo, data_ref))
			return (NULL);
		ft_print_sleep_mutex(philo);
		sleep_and_check(data_ref);
		if (getter(&philo->data->dead_mtx, &philo->data->dead))
			return (NULL);
		ft_print_think_mutex(philo);
	}
	return (NULL);
}

void	create_threads(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	data->start = get_curr_time();
	if (data->nb_philo == 1)
	{
		if (case_one_philo(data, i))
			return ;
	}
	else
	{
		while (i < data->nb_philo)
		{
			if (pthread_create(&(data->philo[i].thread_id), NULL, routine,
					&(data->philo[i])) != 0)
				return ;
			setter_time(&data->checker_lunch, &data->philo[i].lst_lunch,
				get_curr_time());
			i++;
		}
	}
	ft_supervisor(data);
	end_threads(data, i);
	return ;
}
