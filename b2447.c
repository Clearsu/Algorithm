/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2447.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:10:20 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/30 11:30:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	*** (1, 1) (2, 1) (3, 1)
	* * (1, 2) (2, 2) (3, 2)
	*** (1, 3) (2, 3) (3, 3)
 */



#include <stdio.h>

void	print_stars(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		printf(" ");
	else
	{
		if (n / 3 == 0)
			printf("*");
		else
			print_stars(i, j, n / 3);
	}
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			print_stars(i, j, n);
		printf("\n");
	}
	return (0);
}
