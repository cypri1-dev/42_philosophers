/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:41:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/19 13:33:05 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	sleep_and_check(t_data *data)
{
	time_t	tm_ref;
	time_t	remaining_time;
	// time_t	interval;

	tm_ref = get_curr_time();
	while (!getter(&data->dead_mtx, &data->dead))
	{
		remaining_time = data->tm_sleep - (get_curr_time() - tm_ref);
		if (remaining_time <= 0)
			break;

		// interval = remaining_time / 2;
		// if (interval < 10)
		// 	interval = 10; // Intervalle minimum de 10ms

		usleep(50); 
	}
}

void	eat_and_check(t_data *data)
{
	time_t	tm_ref;
	time_t	remaining_time;
	// time_t	interval;

	tm_ref = get_curr_time();
	while (!getter(&data->dead_mtx, &data->dead))
	{
		remaining_time = data->tm_eat - (get_curr_time() - tm_ref + 4);
		//dprintf(2, "ICI: %ld | id: %d\n", remaining_time, data->philo->id);
		if (remaining_time <= 0)
			break;
		// interval = remaining_time / 2;
		// if (interval < 10)
		// 	interval = 10; // Intervalle minimum de 10ms

		usleep(50);
	}
}

time_t	get_curr_time()
{
	struct timeval	tv;
	time_t	res_conv;

	res_conv = ZERO_INIT;
	gettimeofday(&tv, NULL);
	res_conv = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return(res_conv);
}
