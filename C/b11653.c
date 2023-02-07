/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b11653.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:22:42 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/26 11:37:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	unsigned int	n;
	unsigned int	i;

	scanf("%d", &n);
	i = 2;
	while (i <= n)
	{
		if (n % i == 0)
		{
			printf("%d\n", i);
			n /= i;
			i = 2;
		}
		else
			i++;
	}
	return (0);
}
