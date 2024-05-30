/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:03:54 by aakouhar          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:33 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

uint64_t gettime(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        return (printf("error from get time of day\n"));
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}