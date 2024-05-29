/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:06:47 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/29 15:13:37 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "../utils/utils.h"

typedef struct s_philo{
    pthread_t th;
    int     id;
    long    last_meal;
    int     n_of_meals;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    struct s_data  *data;
    
}   t_philo;

typedef struct s_data{
    t_philo *philo;
    pthread_mutex_t    *forks;
    long    t_eat;
    long    t_die;
    long    t_sleep;
    int n_philo;
    int num_meals;
}   t_data;

int main(int ac, char **av);
int parcing(int ac, char **av, t_data *data);
void *routine(void *d);
int ft_init(int ac, char **av, t_data *data);
#endif