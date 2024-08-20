/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:37:25 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/20 14:46:59 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_check_philosophers(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while (i < data->nb_philo)
	{
		if (get_curr_time() - getter_time(&data->checker_lunch,
				&data->philo[i].lst_lunch) >= getter_time(&data->time_die_mtx,
				&data->tm_die))
		{
			setter(&data->dead_mtx, &data->dead, 1);
			ft_print_dead_mutex(&data->philo[i]);
			return (1);
		}
		i++;
		usleep(100);
	}
	return (0);
}

int	case_one_philo(t_data *data, int i)
{
	if (pthread_create(&data->philo[i].thread_id, NULL, routine_solo,
			&(data->philo[i])) != 0)
		return (1);
	setter_time(&data->checker_lunch, &data->philo[i].lst_lunch,
		get_curr_time());
	return (0);
}
