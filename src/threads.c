/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:59:56 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/13 17:40:41 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *arg)
{
	t_philo *philo;
	t_data *data_ref;
	int	i;

	philo = (t_philo *)arg;
	data_ref = philo->data;
	i = ZERO_INIT;
	while(i < 1) // cond will be while(data->dead == 0)
	{
		pthread_mutex_lock(&data_ref->forks[philo->rgt_f_id]);
		ft_print_forks_mutex(philo);
		pthread_mutex_lock(&data_ref->forks[philo->lft_f_id]);
		ft_print_forks_mutex(philo);
		ft_print_eat_mutex(philo);
		// pthread_mutex_lock(&data_ref->forks[philo->lft_f_id]);
		// pthread_mutex_lock(&data_ref->print_mutex);
		// printf("Je suis le philosophe[%d] et ma f_g a pour id:[%d] et ma f_d a pour id:[%d]\n", philo->id, philo->lft_f_id, philo->rgt_f_id);
		// pthread_mutex_unlock(&data_ref->print_mutex);
		// pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
		// pthread_mutex_unlock(&data_ref->forks[philo->lft_f_id]);
		// pthread_mutex_lock(&data_ref->print_mutex);
		// printf("Je suis le philo %d et je vis !\n", philo->id);
		// pthread_mutex_unlock(&data_ref->print_mutex);
		i++;
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
		if(pthread_create(&data->philo[i].thread_id, NULL, routine, (&data->philo[i])) != 0)
			return (-1);
		i++;
	}
	while (--i >= 0)
		pthread_join(data->philo[i].thread_id, NULL);
	//dprintf(2, "TOP : %ld\n", data->start);
	return (0);
}