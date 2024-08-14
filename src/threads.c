/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:59:56 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/14 15:26:51 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	checker_all_ate(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while(i < data->nb_philo && data->philo[i].nb_lunch_philo >= data->nb_lunch)
		i++;
	if (i == data->nb_philo)
		data->all_lunch = 1;
}

void	ft_supervisor(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while(i < data->nb_philo && !data->dead)
	{
		pthread_mutex_lock(&data->checker_lunch);
		if(data->philo[i].lst_lunch - get_curr_time() >= data->tm_die)
		{
			ft_print_dead_mutex(data->philo);
			data->dead = 1;
		}
		pthread_mutex_unlock(&data->print_mutex);
		// usleep ?
		if (data->dead)
			break;
		if (data->nb_lunch != -1)
			checker_all_ate(data);
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo *philo;
	t_data *data_ref;

	philo = (t_philo *)arg;
	data_ref = philo->data;
	while(!data_ref->dead) // cond will be while(data->dead == 0)
	{
		pthread_mutex_lock(&data_ref->forks[philo->rgt_f_id]);
		ft_print_forks_mutex(philo);
		pthread_mutex_lock(&data_ref->forks[philo->lft_f_id]);
		ft_print_forks_mutex(philo);
		ft_print_eat_mutex(philo);
		eat_and_check(data_ref);
		philo->nb_lunch_philo += 1;
		pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
		pthread_mutex_unlock(&data_ref->forks[philo->lft_f_id]);
		//add rule if (argc == 6)
		ft_print_sleep_mutex(philo);
		sleep_and_check(data_ref);
		ft_print_think_mutex(philo);
	}
	return (NULL);
}

int	create_threads(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	data->start = get_curr_time();
	while(i < data->nb_philo)
	{
		if(pthread_create(&(data->philo[i].thread_id), NULL, routine, &(data->philo[i])) != 0)
			return (-1);
		data->philo[i].lst_lunch = get_curr_time();
		i++;
	}
	ft_supervisor(data);
	while (--i >= 0)
		pthread_join(data->philo[i].thread_id, NULL);
	//dprintf(2, "TOP : %ld\n", data->start);
	return (0);
}