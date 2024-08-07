/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:26:47 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/07 16:39:43 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_overflow(char **argv)
{
	int		i;
	int		nb_atoi;
	char	*nb_itoa;

	i = 1;
	nb_atoi = 0;
	nb_itoa = NULL;
	while (argv[i])
	{
		nb_atoi = ft_atoi(argv[i]);
		nb_itoa = ft_itoa(nb_atoi);
		if (ft_strncmp(argv[i], nb_itoa, ft_strlen(argv[i])) == 0)
			i++;
		else
		{
			free(nb_itoa);
			printf("Error!\nOverflow detected.\n");
			exit(EXIT_FAILURE);
		}
		free(nb_itoa);
	}
}

void	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
			{
				printf("Error!\nOnly digits args are allowed!\n");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	check_nb_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error!\nInvalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
}

void	check_envp(char **envp)
{
	if (!*envp)
	{
		printf("Error!\nEnvironnement is missing.\n");
		exit(EXIT_FAILURE);
	}
}

void	parse_philo(int argc, char **argv, char **envp)
{
	check_envp(envp);
	check_nb_args(argc);
	check_digit(argv);
	check_overflow(argv);
	check_nb_philo(argv);
	check_time(argv);
}
