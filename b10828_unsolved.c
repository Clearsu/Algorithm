/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b10828.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:16:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/09/04 17:36:55 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_list {
	struct s_list *next;
	struct s_list *prev;
	unsigned int  data;
} t_list;

void	push(t_list *stack)
{
	scanf("%d", &stack->data);
	stack = stack->next;
}

void	read_instruction(void)
{
	
}

int	main(void)
{
	int	n;
	int	i;

	scanf("%d", &n);
	i = 0;
	while (i < n)
	{
		read_instruction();
		i++;
	}
}
