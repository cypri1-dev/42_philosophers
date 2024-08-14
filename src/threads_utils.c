/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:41:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/14 15:18:12 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	sleep_and_check(t_data *data)
{
	time_t	tm_ref;

	tm_ref = ZERO_INIT;
	tm_ref = get_curr_time();
	while(!data->dead)
	{
		if (get_curr_time() - tm_ref >= data->tm_sleep)
			break;
		//ajouter un usleep ?
	}
}

void	eat_and_check(t_data *data)
{
	time_t	tm_ref;

	tm_ref = ZERO_INIT;
	tm_ref = get_curr_time();
	// dprintf(2, "ref: %ld | diff %ld\n", tm_ref, ();
	while(!data->dead)
	{
		if (get_curr_time() - tm_ref >= data->tm_eat)
			break;
		//ajouter un usleep ?
	}
	dprintf(2, "TEST\n");
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