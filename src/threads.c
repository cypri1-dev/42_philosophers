/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:59:56 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/08 17:36:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *ft_routine(void *arg) 
{
	t_philo *philo = (t_philo*)arg;
	
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("Philo %d is living.\n", philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return NULL;
}

void create_threads(t_data *data)
{
	pthread_t *threads;
	int i;
	
	i = 0;
	threads = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!threads)
	{
		perror("Failed to allocate memory for threads");
		free(data->philo);
		free(data);
		exit(EXIT_FAILURE);
	}
	// Initialisation du mutex
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		perror("Failed to initialize mutex");
		free(threads);
		free(data->philo);
		free(data);
		exit(EXIT_FAILURE);
	}
	// Création des threads
	while(i < data->nb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		if (pthread_create(&threads[i], NULL, ft_routine, &data->philo[i]) != 0)
		{
			perror("Failed to create thread");
			pthread_mutex_destroy(&data->print_mutex);
			free(threads);
			free(data->philo);
			free(data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	// Attente de la fin des threads
	while(i < data->nb_philo)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			perror("Failed to join thread");
			pthread_mutex_destroy(&data->print_mutex);
			free(threads);
			free(data->philo);
			free(data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	free(threads);
	printf("All philosophers have finished!\n");
}
