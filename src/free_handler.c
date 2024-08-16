/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:55:40 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/16 14:06:12 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_handler(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while(i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->dead_mtx);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->checker_lunch);
	free(data->philo);
	free(data->forks);
	free(data);
}