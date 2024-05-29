/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:55:24 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/29 15:12:43 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_digit(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] < '0' && str[i] >= '9' && str[i] != '-' && str[i] != '+')
            return (1);
        i++;
    }
    return (0);
}

static int	check_sign(char *str)
{
	int	i;
	int	mince;
	int	plus;

	i = 0;
	mince = 0;
	plus = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				mince++;
			if (str[i] == '+')
				plus++;
			if (str[i + 1] == '\0' || i != 0 || mince > 1 || plus > 1)
				return (1);
		}
		i++;
	}
    return (0);
}

int parcing(int ac, char **av, t_data *data)
{
    int i;

    i = 0;
    while (i < ac)
    {
        if (check_digit(av[i]) || check_sign(av[i]))
            return (1);
        i++;
    }
    return (0);
}