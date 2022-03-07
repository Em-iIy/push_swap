/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_binary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:59:14 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/07 17:50:14 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	power_of_2(int n)
{
	int	i;

	i = 1;
	if (n > 31)
		return (0);
	while (n--)
		i *= 2;
	return (i);
}

static int	digits_bin(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
		return (32);
	while (n / power_of_2(i))
		i++;
	return (i);
}

int	parse_input_bin(int argc, char **argv)
{
	int	largest;
	int	temp;

	largest = 0;
	while (argc-- > 0)
	{
		temp = digits_bin(ft_atoi(argv[argc]));
		if (largest < temp)
			largest = temp;
	}
	return (largest);
}
