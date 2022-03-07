/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:27 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/07 18:06:03 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long	ret_int;
	int		i;
	int		neg;

	ret_int = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] != '-' || str[i] != '+') && (str[i] < '0' && str[i] > '9'))
		return (0);
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret_int *= 10;
		ret_int += str[i] - '0';
		if (ret_int * neg > INT_MAX || ret_int * neg < INT_MIN)
			error_exit(10);
		i++;
	}
	return (ret_int * neg);
}
