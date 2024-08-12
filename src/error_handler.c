/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:42:02 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/12 14:26:11 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	hdl_err_mutex(t_data *data, char *msg)
{
	int	i;

	i = 0;
	printf("%s\n", msg);
	while(i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	free(data);
	exit(EXIT_FAILURE);
}

void	hdl_err_threads(t_data *data, char *msg)
{
	printf("%s\n", msg);
	// free(data->philo);
	free(data->forks);
	free(data);
	exit(EXIT_FAILURE);
}
