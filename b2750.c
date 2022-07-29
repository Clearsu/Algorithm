/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2750.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:30:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/29 22:09:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_sort_nums(int n)
{
	int	nums[n];
	int	min;
	int	temp;
	int	idx;

	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);
	for (int i = 0; i < n - 1; i++)
	{
		min = nums[i];
		idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (nums[j] < min)
			{
				min = nums[j];
				idx = j;
			}
		}
		temp = nums[i];
		nums[i] = nums[idx];
		nums[idx] = temp;
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", nums[i]);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	print_sort_nums(n);
	return (0);
}
