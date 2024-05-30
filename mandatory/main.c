/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:06:41 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/30 17:46:26 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data  data;
    
    if (!(ac == 5 || ac == 6))
        return (printf("Error, enter 5 or 6 arguments\n"), 1);
    if (parcing(ac, av, &data))
        return (1);
    if (ft_init(ac, av, &data))
        return (1);
}
