/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:26:47 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/07 14:45:13 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	parse_philo(int argc, char **envp)
{
	(void)argc;
	if (!*envp)
	{
		printf("Error!\nEnvironnement is missing.\n");
		return;
	}
}