/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:49:43 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/20 12:51:38 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	setter_nb_lunch(pthread_mutex_t *mtx, int *nb_lunch, int value)
{
	pthread_mutex_lock(mtx);
	*nb_lunch = *nb_lunch + value;
	pthread_mutex_unlock(mtx);
}

int	getter_nb_lunch(pthread_mutex_t *mtx, int *nb_lunch)
{
	int	tmp;

	pthread_mutex_lock(mtx);
	tmp = *nb_lunch;
	pthread_mutex_unlock(mtx);
	return (tmp);
}

void	setter_all_luch(pthread_mutex_t *mtx, int *all_ate, int value)
{
	pthread_mutex_lock(mtx);
	*all_ate = value;
	pthread_mutex_unlock(mtx);
}

int	getter_all_ate(pthread_mutex_t *mtx, int *all_ate)
{
	int	tmp;

	pthread_mutex_lock(mtx);
	tmp = *all_ate;
	pthread_mutex_unlock(mtx);
	return (tmp);
}

time_t	getter_time(pthread_mutex_t *mtx, time_t *time)
{
	time_t	tmp;

	pthread_mutex_lock(mtx);
	tmp = *time;
	pthread_mutex_unlock(mtx);
	return (tmp);
}
