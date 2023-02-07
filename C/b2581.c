/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2581.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:35:56 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/26 11:09:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n == 1)
		return (0);
	else if (n == 2 || n == 3)
		return (n);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (n);
}

int	main(void)
{
	char	num1[6];
	char	num2[6];
	int		int_num1;
	int		int_num2;
	int		num;
	int		plus;
	int		min;

	scanf("%s\n%s", num1, num2);
	int_num1 = atoi(num1);
	int_num2 = atoi(num2);
	plus = 0;
	min = int_num2;
	for (int i = int_num1; i <= int_num2; i++)
	{
		num = is_prime(i);
		if (num)
		{
			plus += num;
			if (num < min)
				min = num;
		}
	}
	if (plus == 0)
	{
		printf("-1\n");
		return (0);
	}
	printf("%d\n%d\n", plus, min);
	return (0);
}
