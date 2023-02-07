/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b4948.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:53:37 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/27 17:12:42 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n == 1)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	count_prime_nums(int n)
{
	int	i;
	int	cnt;

	i = n + 1;
	cnt = 0;
	while (i <= 2 * n)
	{
		if (is_prime(i))
			cnt++;
		i++;
	}
	return (cnt);
}

int	main(void)
{
	int	n;

	while (1)
	{
		scanf("%d", &n);
		if (!n)
			break ;
		printf("%d\n", count_prime_nums(n));
	}
	return (0);
}
