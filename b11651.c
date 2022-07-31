/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b11651.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:17:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/29 22:28:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_struct
{
	int	x;
	int	y;
} t_crd;

void	print_sort_coordinates(int n)
{
	t_crd crd[100000];
	int	temp_x;
	int	temp_y;
	int	min_x;
	int	min_y;

	for (int i = 0; i < n; i++)
		scanf("%d %d", &(crd[i].x), &(crd[i].y));
	
	for (int i = 0; i < n - 1; i++)
	{
		min_y = crd[i].y;
		for (int j = 0; j < n; j++)
		{
		}
	}
}

int	main(void)
{
	int	n;
	
	scanf("%d", &n);
	print_sort_coordinates(n);
	return (0);
}
