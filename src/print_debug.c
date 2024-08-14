/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:03:05 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/14 13:44:57 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void	print_philos(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->nb_philo)
// 	{
// 		printf("Philosopher [%d]:\n", i + 1);
// 		printf("  Right fork: [%d]\n", data->philo[i].r_fork);
// 		printf("  Left fork: [%d]\n", data->philo[i].l_fork);
// 		printf("----------------\n");
// 		i++;
// 	}
// }

void	print_data_struct(t_data *data, int argc)
{
	printf("nb_philo: [%d]\n", data->nb_philo);
	printf("----------------\n");
	printf("tm_die: [%ld ms]\n", data->tm_die);
	printf("----------------\n");
	printf("tm_eat: [%ld ms]\n", data->tm_eat);
	printf("----------------\n");
	printf("tm_sleep: [%ld ms]\n", data->tm_sleep);
	if (argc == 6)
	{
		printf("----------------\n");
		printf("nb_lunch: [%d]\n", data->nb_lunch);
	}
}
