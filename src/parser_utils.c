/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:05:42 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/13 14:35:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_nb_lunch(char **argv)
{
	if (ft_atoi(argv[5]) <= 0)
	{
		printf("Error!\nInvalid lunch number.\n");
		exit(EXIT_FAILURE);
	}
}

void	check_time(char **argv)
{
	int	i;
	int	time_atoi;

	i = 2;
	time_atoi = ZERO_INIT;
	while (argv[i] && i <= 4)
	{
		time_atoi = ft_atoi(argv[i]);
		if (time_atoi <= 0)
		{
			printf("Error!\nInvalid time.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_nb_philo(char **argv)
{
	int	i;
	int	nb_philo;

	i = 1;
	nb_philo = ZERO_INIT;
	nb_philo = ft_atoi(argv[i]);
	if (nb_philo <= 0 || nb_philo > 200)
	{
		printf("Error!\nInvalid number of philosophers.\n");
		exit(EXIT_FAILURE);
	}
}
