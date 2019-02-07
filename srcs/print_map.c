/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 05:16:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/07 07:44:09 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

#include "fdf.h"

void	print_map(t_env *env)
{
	int	y;
	int	x;

	printf("Map :\n\n");
	y = -1;
	while (++y < env->height - 1)
	{
		x = -1;
		printf("\t");
		while (++x < env->width - 1)
		{
			printf("%d ", env->grid[y][x].z);
			draw_line(env->grid[y][x], env->grid[y][x + 1], env);
			draw_line(env->grid[y][x], env->grid[y + 1][x], env);
		}
		printf("\n");
	}
}
