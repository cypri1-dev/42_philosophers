/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:10:02 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/16 12:15:26 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length && first[i] != '\0' && second[i] != '\0')
	{
		if ((unsigned char)first[i] > (unsigned char)second[i])
			return (1);
		else if ((unsigned char)first[i] < (unsigned char)second[i])
			return (-1);
		i++;
	}
	if (i == length || (first[i] == '\0' && second[i] == '\0'))
		return (0);
	else if (first[i] == '\0')
		return (-1);
	else
		return (1);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
	{
		return (1);
	}
	return (0);
}

int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = ft_int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (num > 0)
	{
		str[--len] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

int	ft_atoi(const char *nbr)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	while (*nbr && (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13)))
		++nbr;
	if (*nbr && (*nbr == '-' || *nbr == '+'))
	{
		if (*nbr++ == '-')
			sign *= -1;
	}
	while (*nbr && (*nbr >= '0' && *nbr <= '9'))
		result = (*nbr++ - '0') + result * 10;
	return (result * sign);
}
