/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:25:29 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/20 13:01:20 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_philo(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].nb_lunch_philo = ZERO_INIT;
		data->philo[i].lft_f_id = data->philo[i].id;
		data->philo[i].rgt_f_id = ((data->philo[i].id) + 1) % data->nb_philo;
		if (i == data->nb_philo - 1)
		{
			data->philo[i].rgt_f_id = data->philo[i].id;
			data->philo[i].lft_f_id = ((data->philo[i].id) + 1)
				% data->nb_philo;
		}
		data->philo[i].lst_lunch = ZERO_INIT;
		data->philo[i].data = data;
		i++;
	}
}

void	init_mutex_two(t_data *data)
{
	if (pthread_mutex_init(&data->time_die_mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&data->dead_mtx);
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->checker_lunch);
		hdl_err_mutex(data, "Failed to initialize dead_mutex");
	}
	if (pthread_mutex_init(&data->all_lunch_mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&data->time_die_mtx);
		pthread_mutex_destroy(&data->dead_mtx);
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->checker_lunch);
		hdl_err_mutex(data, "Failed to initialize dead_mutex");
	}
	if (pthread_mutex_init(&data->nb_lunch_mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&data->all_lunch_mtx);
		pthread_mutex_destroy(&data->time_die_mtx);
		pthread_mutex_destroy(&data->dead_mtx);
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->checker_lunch);
		hdl_err_mutex(data, "Failed to initialize dead_mutex");
	}
}

void	init_mutex(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			hdl_err_philo(data, "Failed to initialize fork_mutex");
		i++;
	}
	if (pthread_mutex_init(&data->checker_lunch, NULL) != 0)
		hdl_err_mutex(data, "Failed to initialize lunch_mutex");
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->checker_lunch);
		hdl_err_mutex(data, "Failed to initialize print_mutex");
	}
	if (pthread_mutex_init(&data->dead_mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->checker_lunch);
		hdl_err_mutex(data, "Failed to initialize dead_mutex");
	}
	init_mutex_two(data);
}

void	set_value(t_data **data, char **argv, int argc)
{
	(*data)->nb_philo = ft_atoi(argv[1]);
	(*data)->tm_die = ft_atoi(argv[2]);
	(*data)->tm_eat = ft_atoi(argv[3]);
	(*data)->tm_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*data)->nb_lunch = ft_atoi(argv[5]);
	else
		(*data)->nb_lunch = -1;
	(*data)->all_lunch = ZERO_INIT;
	(*data)->dead = ZERO_INIT;
}

void	init_data(int argc, char **argv, t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
	{
		printf("Error!\nMemory allocation failed for data.\n");
		exit(EXIT_FAILURE);
	}
	set_value(data, argv, argc);
	(*data)->philo = malloc(sizeof(t_philo) * (*data)->nb_philo);
	if (!(*data)->philo)
	{
		printf("Error!\nMemory allocation failed for philo.\n");
		free(*data);
		exit(EXIT_FAILURE);
	}
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->nb_philo);
	if (!(*data)->forks)
	{
		printf("Error!\nMemory allocation failed for forks.\n");
		free((*data)->philo);
		free(*data);
		exit(EXIT_FAILURE);
	}
	init_philo(*data);
	init_mutex(*data);
}
