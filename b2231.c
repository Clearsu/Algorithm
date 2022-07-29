/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2231.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:41:06 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/29 14:51:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_constructor(int n)
{
	int	i;
	int	i_cp;
	int sum;

	i = 1;
	while (i < n)
	{
		i_cp = i;
		sum = 0;
		while (i_cp > 0)
		{
			sum += i_cp % 10;
			i_cp /= 10;
		}
		sum += i;
		if (sum == n)
		{
			printf("%d\n", i);
			return ;
		}
		i++;
	}
	printf("0\n");
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	print_constructor(n);
	return (0);
}
