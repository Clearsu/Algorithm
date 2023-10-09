/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b7568.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:22:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/11 23:03:50 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_data
{
	int	weight;
	int	height;
	int	order;
}	t_data;

void	set_data(int n, t_data *data)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &(data[i].weight), &(data[i].height));
		data[i].order = 1;
	}
}

void	decide_order(int n, t_data *data)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (data[i].weight > data[j].weight && data[i].height > data[j].height)
				data[j].order++;
			else if (data[i].weight < data[j].weight && data[i].height < data[j].height)
				data[i].order++;
		}
	}
}

void	print_order(int n, t_data *data)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", data[i].order);
		if (i < n - 1)
			printf(" ");
	}
}

int	main(void)
{
	int		n;
	t_data	data[50];
	
	scanf("%d", &n);
	set_data(n, data);
	decide_order(n, data);
	print_order(n, data);
}
