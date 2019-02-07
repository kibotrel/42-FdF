/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 05:16:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/07 09:35:30 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

#include "fdf.h"
#include "env.h"

void	print_map(t_env *env)
{
	int	y;
	int	x;

	env->cam->zoom = ((WIDTH / env->width / 2) < (HEIGHT / env->height / 2) ? (WIDTH / env->width / 2) : (HEIGHT / env->height / 2));
	printf("Map :\n\n");
	y = -1;
	while (++y < env->height)
	{
		x = -1;
		printf("\t");
		while (++x < env->width)
		{
			printf("%d ", env->grid[y][x].z);
			if (x < env->width - 1)
				draw_line(transform(env->grid[y][x], env), transform(env->grid[y][x + 1], env), env);
			if (y < env->height - 1)
			draw_line(transform(env->grid[y][x], env), transform(env->grid[y + 1][x], env), env);
		}
		printf("\n");
	}
}
