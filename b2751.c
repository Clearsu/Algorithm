/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2751.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:54:16 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/03 02:53:17 by jincpark         ###   ########.fr       */
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
	
}

void	devide_and_merge(int *arr_src, int *arr_dest, int first, int last)
{
	int	mid;

	if (first == last)
		return ;
	mid = (last - first) / 2;
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
	if (n == 0)
		return (0);
	arr_src = read_nums(n);
	arr_dest = calloc(n, sizeof(int));
	if (!arr_src || !arr_dest)
		return (1);
	if (n > 1)
		devide_and_merge(arr_src, arr_dest, 0, n - 1);
	print_arr_src(arr_src, n);
	free(arr_src);
	return (0);
}
