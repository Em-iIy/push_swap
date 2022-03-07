/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:10:21 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/07 17:53:42 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h> // remove

static void	indexing(t_node **stack_a, int argc)
{
	t_node	smallest;
	t_node	*iterator;
	long	temp;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		iterator = *stack_a;
		temp = 2147483648;
		while (iterator)
		{
			if (iterator->num < temp && iterator->idx == -1)
			{
				smallest.next = iterator;
				temp = iterator->num;
			}
			iterator = iterator->next;
		}
		smallest.next->idx = i;
		i++;
	}
}

/**
 * @brief 		Checks the splitted input string for chars other than digits
 * 					exits with error (INVALID_ARGUMENT)
 * 
 * @param str 	Splitted input string
 */
static void	check_num(int argc, char **argv)
{
	int		i;
	int		j;
	char	tmp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			tmp = argv[i][j];
			if (tmp == '-' && !ft_isdigit(argv[i][j + 1]))
				error_exit(INVALID_ARGUMENT);
			else if (tmp != '-' && !ft_isdigit(tmp))
				error_exit(INVALID_ARGUMENT);
			j++;
		}
		i++;
	}
}

/**
 * @brief 			Takes the user input, splits it up and fills up the stack_a
 * 						linked list will work with strings containing multiple
 * 						numbers separated by spaces
 * 
 * @param stack_a 	The stack to fill
 * @param argc 		Number of args
 * @param argv 		Args
 */
static void	fill_stack_a(t_node **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		node_add_back(stack_a, node_new(ft_atoi(argv[i])));
		i++;
	}
	indexing(stack_a, argc);
}

void	parse_input(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	j;
	int	largest;
	int	input;

	i = 1;
	check_num(argc, argv);
	if (argc == 2)
		exit (0);
	fill_stack_a(&stack->stack_a, argc, argv);
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
			printf("%d", (input >> j) & 1);
		}
		printf("\n");
		i++;
	}
}
