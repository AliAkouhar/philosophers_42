/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:27:32 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/30 18:17:30 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_alloc(t_data *data)
{
    data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
    if (!data->forks)
        return (1);
    data->philo = malloc(sizeof(t_philo) * data->n_philo);
    if (!data->philo)
        return (1);
    return (0);
}

int ft_init_args(char **av, t_data *data)
{
    data->death_flag = 1;
    data->n_philo = ft_atol(av[1]);
    data->t_die = ft_atol(av[2]);
    data->t_eat = ft_atol(av[3]);
    data->t_sleep = ft_atol(av[4]);
    if (av[5])
        data->num_meals = ft_atol(av[5]);
    else
        data->num_meals = -1;
    return (0);
}

int ft_create_forks(t_data *data)
{
    int i;

    i = -1;
    if (pthread_mutex_init(&data->death_lock, NULL))
        return (printf("Error while init mutex"));
    while (++i < data->n_philo)
    {
        if (pthread_mutex_init(&data->philo[i].lock_status, NULL))
            return (printf("Error while init mutex"));
        if (pthread_mutex_init(&data->forks[i], NULL))
            return (printf("Error while creating forks\n"));
    }
    data->philo[0].left_fork = &data->forks[0];
    data->philo[0].right_fork = &data->forks[data->n_philo - 1];
    i = 0;
    while (++i < data->n_philo)
    {
        data->philo[i].left_fork = &data->forks[i];
        data->philo[i].right_fork = &data->forks[i - 1];
    }
    return (0);
}

int ft_create_philos(t_data *data)
{
    int i;

    // printf();
    i = -1;
    if(pthread_create(&data->monitore,NULL, death_func, data))
        return (1);
    while (++i < data->n_philo)
    {
        data->philo[i].data = data;
        data->philo[i].id = i;
        if (pthread_create(&data->philo[i].th, NULL, routine, &data->philo[i]))
            return (1);
    // printf("hello %d\n", data->philo[i].id);
    }
    i = -1;
    while (++i < data->n_philo)
    {
        if (pthread_join(data->philo[i].th, NULL))
            return (printf("error while joining\n"));
    }
    if (pthread_join(data->monitore, NULL))
        return (1);
    return (0);
}

int ft_init(int ac, char **av, t_data *data)
{
    if (ft_init_args(av, data))
        return (1);
    if (ft_alloc(data))
        return (1);
    if (ft_create_forks(data))
        return (1);
    if (ft_create_philos(data))
        return (1);
    return (0);
}