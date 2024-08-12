/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:25:29 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/12 14:31:47 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			hdl_err_threads(data, "Failed to initialize fork_mutex");
		i++;
	}
	if (pthread_mutex_init(&data->checker_lunch, NULL) !=0)
		hdl_err_mutex(data, "Failed to initialize lunch_mutex");
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->checker_lunch);
		hdl_err_mutex(data, "Failed to initialize lunch_mutex");
	}
}

void	init_data(int argc, char **argv, t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
	{
		printf("Error!\nMemory allocation failed for data.\n");
		exit(EXIT_FAILURE);
	}
	(*data)->nb_philo = ft_atoi(argv[1]);
	(*data)->tm_die = ft_atoi(argv[2]);
	(*data)->tm_eat = ft_atoi(argv[3]);
	(*data)->tm_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*data)->nb_lunch = ft_atoi(argv[5]);
	else
		(*data)->nb_lunch = -1;
	(*data)->all_lunch = 0;
	(*data)->dead = 0;
	// (*data)->philo = malloc(sizeof(t_philo) * (*data)->nb_philo);
	// if (!(*data)->philo)
	// {
	// 	printf("Error!\nMemory allocation failed for philo.\n");
	// 	free(*data);
	// 	exit(EXIT_FAILURE);
	// }
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->nb_philo);
	if (!(*data)->forks)
	{
		printf("Error!\nMemory allocation failed for forks.\n");
		free(*data);
		exit(EXIT_FAILURE);
	}
	init_mutex(*data);
}
