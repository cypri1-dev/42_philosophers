/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:41:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/13 14:55:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	get_curr_time()
{
	struct timeval	tv;
	long	res_conv;

	res_conv = ZERO_INIT;
	gettimeofday(&tv, NULL);
	res_conv = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return(res_conv);
}