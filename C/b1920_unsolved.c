/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1920.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:39:32 by jincpark          #+#    #+#             */
/*   Updated: 2022/09/04 17:52:50 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	put_num_in_arr(int n, int *arr)
{
	int	i;

	i = 0;
	while (i < n)
	{
		scanf("%d", &arr[i]);
		i++;
	}
}

void	check_and_print_nums(int *arr, int n, int m)
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
			if (arr[j] == num)
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
	int n;
	int m;
	int	*arr;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	put_num_in_arr(n, arr);
	scanf("%d", &m);
	check_and_print_nums(arr, n, m);
	free(arr);
}
