/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:25:29 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/08 13:59:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_data_struct(t_data *data, int argc)
{
	printf("nb_philo: [%d]\n", data->nb_philo);
	printf("----------------\n");
	printf("nb_forks: [%d]\n", data->nb_forks);
	printf("----------------\n");
	printf("tm_die: [%d ms]\n", data->tm_die);
	printf("----------------\n");
	printf("tm_eat: [%d ms]\n", data->tm_eat);
	printf("----------------\n");
	printf("tm_sleep: [%d ms]\n", data->tm_sleep);
	if (argc == 6)
	{
		printf("----------------\n");
		printf("nb_lunch: [%d]\n", data->nb_lunch);
	}
}

void	init_data(int argc, char **argv, t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error!\nMemory allocation failed for data.\n");
		exit(EXIT_FAILURE);
	}
	(*data)->nb_philo = ft_atoi(argv[1]);
	(*data)->nb_forks = (*data)->nb_philo;
	(*data)->tm_die = ft_atoi(argv[2]);
	(*data)->tm_eat = ft_atoi(argv[3]);
	(*data)->tm_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*data)->nb_lunch = ft_atoi(argv[5]);
}
