/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:06:47 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/30 17:56:29 by aakouhar         ###   ########.fr       */
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
    int     n_of_meals;
    int     status; //1 is eathimg/ 2 is sleeping/ 3 is thinking/ 4 is dieng
    u_int64_t    last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t lock_status;
    struct s_data  *data;
    
}   t_philo;

typedef struct s_data{
    t_philo *philo;
    pthread_mutex_t    *forks;
    pthread_mutex_t death_lock;
    long    t_eat;
    long    t_die;
    long    t_sleep;
    int n_philo;
    int death_flag;
    int num_meals;
    int *arr_time;
    pthread_t   monitore;
}   t_data;

int main(int ac, char **av);
int parcing(int ac, char **av, t_data *data);
void *routine(void *d);
int ft_init(int ac, char **av, t_data *data);
void    *death_func(void *p);
int ft_create_philos(t_data *data);
void    *death_func(void *p);
void    go_to_eat(t_philo *philo);

#endif