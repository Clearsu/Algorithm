/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1929.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/27 16:34:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_prime(int n)
{
	int	i;

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

void	print_prime_nums(int n1, int n2)
{
	while (n1 <= n2)
	{
		if (is_prime(n1))
			printf("%d\n", n1);
		n1++;
	}
}

int	main(void)
{
	int	n1;
	int	n2;

	scanf("%d %d", &n1, &n2);
	print_prime_nums(n1, n2);
	return (0);
}
