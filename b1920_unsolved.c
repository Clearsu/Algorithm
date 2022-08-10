/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1920.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 02:47:50 by jincpark          #+#    #+#             */
/*   Updated: 2022/08/11 03:03:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*put_nums_in_array(int n)
{
	int	i;
	int	*array;

	i = 0;
	array = (int *)malloc(sizeof(int) * n);
	while (i < n)
		scanf("%d", &array[i++]);
	return (array);
}

void	print_nums_in_a(int n, int m, int *a)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < m)
	{
		scanf("%d", &num);
		j = 0;
		while (j < n)
		{
			if (num == a[j])
			{
				printf("1\n");
				break ;
			}
			j++;
		}
		if (j == n)
			printf("0\n");
		i++;
	}
}

int	main(void)
{
	int	n;
	int	m;
	int	*a;

	scanf("%d", &n);
	a = put_nums_in_array(n);
	scanf("%d", &m);
	print_nums_in_a(n, m, a);
	free(a);
	return (0);
}
