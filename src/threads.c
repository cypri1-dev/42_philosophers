/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:59:56 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/20 12:01:34 by cyferrei         ###   ########.fr       */
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
	return(tmp);
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
	time_t tmp;
	
	pthread_mutex_lock(mtx);
	tmp = *time;
	pthread_mutex_unlock(mtx);
	return (tmp);
}

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

int	checker_all_ate(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while(i < data->nb_philo && data->philo[i].nb_lunch_philo >= getter_nb_lunch(&data->nb_lunch_mtx, &data->nb_lunch))
		i++;
	if (i == data->nb_philo)
	{
		setter_all_luch(&data->all_lunch_mtx, &data->all_lunch, 1);
		// data->all_lunch = 1;
		return(1);
	}
	return (0);
}
void	ft_supervisor(t_data *data)
{
	int i;

	i = ZERO_INIT;
	while (!getter(&data->dead_mtx, &data->dead) || data->all_lunch == 1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (get_curr_time() - getter_time(&data->checker_lunch, &data->philo[i].lst_lunch) >= getter_time(&data->time_die_mtx, &data->tm_die))
			{
				setter(&data->dead_mtx, &data->dead, 1);
				ft_print_dead_mutex(&data->philo[i]);
				break;
			}
			i++;
			usleep(100);
		}	
		if (getter(&data->dead_mtx, &data->dead))
			return;
		if (data->nb_lunch != -1)
		{
			if(checker_all_ate(data))
				break;
		}
	}
}

void	*routine_solo(void *arg)
{
	t_philo	*philo;
	t_data *data_ref;
	
	philo = (t_philo *)arg;
	data_ref = philo->data;
	while(!data_ref->dead)
	{
		pthread_mutex_lock(&data_ref->forks[philo->rgt_f_id]);
		ft_print_forks_mutex(philo);
		ft_print_dead_mutex(philo);
		setter(&data_ref->dead_mtx, &data_ref->dead, 1);
		pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo *philo;
	t_data *data_ref;

	philo = (t_philo *)arg;
	data_ref = philo->data;

	if (philo->id % 2)
		usleep(15000);
	while(!getter(&data_ref->dead_mtx, &data_ref->dead))
	{
		pthread_mutex_lock(&data_ref->forks[philo->rgt_f_id]);
		if(getter(&philo->data->dead_mtx, &philo->data->dead))
		{
			pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
			return(NULL);
		}
		ft_print_forks_mutex(philo);
		pthread_mutex_lock(&data_ref->forks[philo->lft_f_id]);
		if(getter(&philo->data->dead_mtx, &philo->data->dead))
		{
			pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
			pthread_mutex_unlock(&data_ref->forks[philo->lft_f_id]);
			return(NULL);
		}
		ft_print_forks_mutex(philo);
		if(getter(&philo->data->dead_mtx, &philo->data->dead))
		return(NULL);
		ft_print_eat_mutex(philo);
		eat_and_check(data_ref);
		setter_nb_lunch(&data_ref->nb_lunch_mtx, &philo->nb_lunch_philo, 1);
		// philo->nb_lunch_philo += 1;
		pthread_mutex_unlock(&data_ref->forks[philo->rgt_f_id]);
		pthread_mutex_unlock(&data_ref->forks[philo->lft_f_id]);
		if(getter(&philo->data->dead_mtx, &philo->data->dead))
			return(NULL);
		if (getter_all_ate(&data_ref->all_lunch_mtx, &data_ref->all_lunch))
			return(NULL);
		ft_print_sleep_mutex(philo);
		sleep_and_check(data_ref);
		if(getter(&philo->data->dead_mtx, &philo->data->dead))
			return(NULL);
		ft_print_think_mutex(philo);
	}
	return (NULL);
}

int	create_threads(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	data->start = get_curr_time();
	if (data->nb_philo == 1)
	{
		if(pthread_create(&data->philo[i].thread_id, NULL, routine_solo, &(data->philo[i])) != 0)
			return (-1);
		setter_time(&data->checker_lunch, &data->philo[i].lst_lunch, get_curr_time());
	}
	else
	{
		while(i < data->nb_philo)
		{
			if(pthread_create(&(data->philo[i].thread_id), NULL, routine, &(data->philo[i])) != 0)
				return (-1);
			setter_time(&data->checker_lunch, &data->philo[i].lst_lunch, get_curr_time());
			i++;
		}
	}
	ft_supervisor(data);
	if (data->nb_philo == 1)
		pthread_join(data->philo[i].thread_id, NULL);
	else
	{
		while (--i >= 0)
			pthread_join(data->philo[i].thread_id, NULL);
	}
	return (0);
}
