/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:51:08 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/20 13:05:12 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	setter_time(pthread_mutex_t *mtx, time_t *time, time_t value)
{
	pthread_mutex_lock(mtx);
	*time = value;
	pthread_mutex_unlock(mtx);
}

void	setter(pthread_mutex_t *mtx, bool *dead, bool value)
{
	pthread_mutex_lock(mtx);
	*dead = value;
	pthread_mutex_unlock(mtx);
}

bool	getter(pthread_mutex_t *mtx, bool *dead)
{
	bool	tmp;

	pthread_mutex_lock(mtx);
	tmp = *dead;
	pthread_mutex_unlock(mtx);
	return (tmp);
}
