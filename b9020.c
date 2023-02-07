/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b9020.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:28:13 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/27 18:23:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_prime(int n)
{
	int i;

	if (n == 1)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	print_goldbach_partition(int n)
{
	int i;

	i = n / 2;
	while (i >= 2)
	{
		if (is_prime(i) && is_prime(n - i))
		{
			printf("%d %d\n", i, n - i);
			return ;
		}
		i--;
	}
}

int	main(void)
{
	int tc_n;
	int n;

	scanf("%d", &tc_n);
	for (int i = 0; i < tc_n; i++)
	{
		scanf("%d", &n);
		print_goldbach_partition(n);
	}
	return (0);
}
