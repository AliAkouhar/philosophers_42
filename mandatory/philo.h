/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:06:47 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/25 12:26:03 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// #include utils.h"

typedef struct s_philo{
    pthread_t th;
    int     id;
    long    t_eat;
    long    t_die;
    long    t_sleep;
    long    last_meal;
    int     n_of_meals;
    
}   t_philo;

typedef struct s_data{
    t_philo *philo;
    int n_philo;
    char **args;
}   t_data;

int main(int ac, char **av);
int parcing(int ac, char **av, t_data *data);

#endif