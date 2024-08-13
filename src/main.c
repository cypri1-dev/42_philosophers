/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:43:00 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/13 15:57:27 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = NULL;
	parse_philo(argc, argv, envp);
	init_data(argc, argv, &data);
	create_threads(data);
	free_handler(data);
	return (0);
}
