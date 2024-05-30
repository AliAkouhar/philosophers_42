/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:33:12 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/30 18:28:11 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *death_func(void *p)
{
    t_data  *data;
    u_int64_t   time;
    int i;

    data = (t_data *)p;
    time = gettime();
    while (data->death_flag)
    {
        i = -1;
        while (++i < data->n_philo)
        {
                printf("%i hhhhhh %llu\n", i, time - data->philo[i].last_meal);
                printf("hhhh %llu\n", time);
                printf("hh %llu\n", data->philo[i].last_meal);
             if (time - data->philo[i].last_meal >= data->t_die && data->philo[i].status != 1)
             {
                printf("%i DIED\n", data->philo[i].id);
                data->death_flag = 0;
                // break;
                exit(1);
             }
        }
    }
   /*  if (data->death_flag == 0)
        go_to_kill_all_philo(data); */
    return (0);
}

void    go_to_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    printf("%d has taken left fork\n", philo->id);
    pthread_mutex_lock(philo->right_fork);
    printf("%d has taken right fork\n", philo->id);
    // printf("from go to eat %ld\n", philo->data->t_eat);
    philo->status = 1;
    printf("%d is eating\n", philo->id);
    usleep(philo->data->t_eat * 1000);
    philo->last_meal = gettime();
    // printf("hohohoho %llu\n", philo->last_meal);
    philo->status = 0;
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    return ;
}

void    go_to_sleep(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock_status);
    printf("%d is sleeping\n", philo->id);
    usleep(philo->data->t_sleep * 1000);
    pthread_mutex_unlock(&philo->lock_status);
}

void *routine(void *d)
{
    t_philo *philo;

    philo = (t_philo *)d;
    philo->last_meal = gettime();
    if (philo->id % 2 != 0)
        usleep(100);
    while (philo->data->death_flag)
    {
        go_to_eat(philo);
        go_to_sleep(philo);
        printf("%d is thinking\n", philo->id);
    }
    return (0);
}