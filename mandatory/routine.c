/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:33:12 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/29 16:07:10 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    go_to_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    printf("%d has taken left fork\n", philo->id);
    pthread_mutex_lock(philo->right_fork);
    printf("%d has taken right fork\n", philo->id);
    // printf("from go to eat %ld\n", philo->data->t_eat);
    printf("%d is eating\n", philo->id);
    usleep(philo->data->t_eat);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    return ;
}

void    go_to_sleep(t_philo *philo)
{
    printf("%d is sleeping\n", philo->id);
    usleep(philo->data->t_sleep);
}

void *routine(void *d)
{
    t_philo *philo;

    philo = (t_philo *)d;
    if (philo->id % 2 != 0)
        usleep(100);
    go_to_eat(philo);
    go_to_sleep(philo);
    printf("%d is thinking\n", philo->id);
    return (0);
}