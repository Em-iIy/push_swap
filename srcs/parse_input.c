/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:10:21 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/23 18:21:39 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	parse_input(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	j;
	int	largest;
	int	input;

	i = 1;
	largest = parse_input_bin(argc, argv);
	printf("largest:%d\n", largest);
	while (i < argc)
	{
		printf("%s:\t", argv[i]);
		input = ft_atoi(argv[i]);
		j = largest;
		while (j > 0)
		{
			j--;
			printf("%d", (input >> j) % 2);
		}
		printf("\n");
		i++;
	}
}
