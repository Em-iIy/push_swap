/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:57:40 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/23 17:04:36 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	error_exit(int code)
{
	ft_putstr_fd("Error:\n", 1);
	if (code == MALLOC_ERROR)
		ft_putstr_fd("Ran out of memory", 1);
	else if (code == TOO_FEW_ARGUMENTS)
		ft_putstr_fd("Too few arguments", 1);
	exit(code);
}
