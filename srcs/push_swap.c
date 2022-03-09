/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:27:50 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/09 15:38:21 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		error_exit(TOO_FEW_ARGUMENTS);
	parse_input(&stack, argc, argv);
	sorting(&stack, argc - 1);
}
