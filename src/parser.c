/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:26:47 by cyferrei          #+#    #+#             */
/*   Updated: 2024/08/07 15:24:59 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_digit(char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	while (argv[i])
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			if(ft_isdigit(argv[i][j]))
				j++;
			else
			{
				printf("Error!\nOnly digits args are allowed!\n");
				exit(1);
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
		exit(1);
	}
}

void	check_envp(char	**envp)
{
	if (!*envp)
	{
		printf("Error!\nEnvironnement is missing.\n");
		exit(1);
	}
}
void	parse_philo(int argc, char **argv, char **envp)
{
	check_envp(envp);
	check_nb_args(argc);
	check_digit(argv);
}