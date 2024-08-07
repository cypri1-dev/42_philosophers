/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:56:35 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/07 16:21:24 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	int isornot = ft_isdigit('1');
	printf("%d", isornot);
	return (0);
}*/
