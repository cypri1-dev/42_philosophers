/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:05:42 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/07 16:30:23 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_time(char **argv)
{
	int i;
	int	time_atoi;
	
	i = 2;
	time_atoi = 0;
	while(argv[i])
	{
		time_atoi = ft_atoi(argv[i]);
		if(time_atoi <= 0)
		{
			printf("Error!\n--TIME_TO_...-- must be positive and different from 0.\n");
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
	nb_philo = 0;
	nb_philo = ft_atoi(argv[i]);
	if (nb_philo <= 0 || nb_philo > 200)
	{
		printf("Error!\nThe number of philosophers must be positive, different from 0, and less than or equal to 200.");
		exit(EXIT_FAILURE);
	}
}