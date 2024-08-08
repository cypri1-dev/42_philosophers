/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:42:02 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/08 18:15:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	hdl_err_threads(t_data *data, char *msg)
{
	printf("%s\n", msg);
	free(data->philo);
	free(data);
	exit(EXIT_FAILURE);
}
