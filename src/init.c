/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:25:29 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/08 15:03:23 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_philo(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].r_fork = 1;
		data->philo[i].l_fork = 0;
		i++;
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
	(*data)->philo = malloc(sizeof(t_philo) * (*data)->nb_philo);
	if (!(*data)->philo)
	{
		printf("Error!\nMemory allocation failed for philo.\n");
		free(*data);
		exit(EXIT_FAILURE);
	}
	init_philo(*data);
}
