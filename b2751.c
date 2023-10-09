/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2751.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:54:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/26 18:08:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*read_nums(int n)
{
	int	*arr;

	arr = calloc(n, sizeof(int));
	if (!arr)
		return (NULL);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	return (arr);
}

void	print_arr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}

void	sort_and_merge(int *arr_src, int *arr_dest, int first, int mid, int last)
{
	int	idx_a;
	int	idx_b;
	
	idx_a = first;
	idx_b = mid + 1;
	for (int curr = idx_a; curr <= last; curr++)
	{
		if (idx_a <= mid && (idx_b > last || arr_src[idx_a] < arr_src[idx_b]))
		{
			arr_dest[curr] = arr_src[idx_a];
			idx_a++;
		}
		else
		{
			arr_dest[curr] = arr_src[idx_b];
			idx_b++;
		}
	}
}

void	devide_and_merge(int *arr_src, int *arr_dest, int first, int last)
{
	int	mid;

	if (last - first < 2)
		return ;
	mid = (last + first) / 2;
	devide_and_merge(arr_src, arr_dest, first, mid);
	devide_and_merge(arr_src, arr_dest, mid + 1, last);
	sort_and_merge(arr_src, arr_dest, first, mid, last);
}

int	main(void)
{
	int	n;
	int	*arr_src;
	int	*arr_dest;

	scanf("%d", &n);
	if (n <= 0)
		return (1);
	arr_src = read_nums(n);
	arr_dest = calloc(n, sizeof(int));
	if (!arr_src || !arr_dest)
		return (1);
	if (n > 1)
	{
		devide_and_merge(arr_src, arr_dest, 0, n - 1);
		print_arr(arr_dest, n);
	}
	else
		print_arr(arr_src, n);
	return (0);
}
