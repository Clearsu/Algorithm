/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2798.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:58:14 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/29 14:11:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	get_blackjack_num(int n, int m)
{
	int	cards[n];
	int	max;
	int	sum;

	max = 0;
	for (int l = 0; l < n; l++)
		scanf("%d", &cards[l]);
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = cards[i] + cards[j] + cards[k];
				if (max < sum && sum <= m)
					max = sum;
			}
		}
	}
	printf("%d\n", max);
}

int	main(void)
{
	int	n;
	int	m;
	
	scanf("%d %d", &n, &m);
	get_blackjack_num(n, m);
	return (0);
}
