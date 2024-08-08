/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:59:56 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/08 18:17:36 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("Philo %d is living.\n", philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (NULL);
}

void	join_thread(t_data *data, pthread_t *threads, int i)
{
	if (pthread_join(threads[i], NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		free(threads);
		hdl_err_threads(data, "Failed to join thread");
	}
}

void	init_thread_philo(t_data *data, pthread_t *threads, int i)
{
	data->philo[i].data = data;
	data->philo[i].id = i + 1;
	if (pthread_create(&threads[i], NULL, ft_routine, &data->philo[i]) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		free(threads);
		hdl_err_threads(data, "Failed to create thread");
	}
}

void	create_threads(t_data *data)
{
	pthread_t	*threads;
	int			i;

	i = 0;
	threads = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!threads)
		hdl_err_threads(data, "Failed to allocate memory for threads");
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		free(threads);
		hdl_err_threads(data, "Failed to initialize mutex");
	}
	while (i < data->nb_philo)
		init_thread_philo(data, threads, i++);
	i = 0;
	while (i < data->nb_philo)
		join_thread(data, threads, i++);
	pthread_mutex_destroy(&data->print_mutex);
	free(threads);
	printf("All philosophers have finished!\n");
}
