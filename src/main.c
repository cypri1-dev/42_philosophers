/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:43:00 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/08 15:04:34 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	
	data = NULL;
	parse_philo(argc, argv, envp);
	init_data(argc, argv, &data);
	// print_data_struct(data, argc);
	// print_philos(data);
	free(data->philo);
	free(data);
	return (0);
}
