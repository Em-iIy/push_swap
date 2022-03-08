/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:57:40 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/08 16:34:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	error_exit(int code)
{
	ft_putstr_fd("Error\n", 2);
	if (code == MALLOC_ERROR)
		ft_putstr_fd("Ran out of memory", 2);
	else if (code == TOO_FEW_ARGUMENTS)
		ft_putstr_fd("Too few arguments", 2);
	else if (code == INVALID_ARGUMENT)
		ft_putstr_fd("Please input numbers only", 2);
	else if (code == DUPLICATE_ARGUMENT)
		ft_putstr_fd("Duplicate numbers", 2);
	exit(code);
}
