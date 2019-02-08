/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 05:16:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/08 00:59:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

#include "fdf.h"
#include "env.h"

void	print_map(t_env *env)
{
	int	y;
	int	x;

	int	line = 0;//

	y = -1;
	//printf("Map :\n\n"); //
	while (++y < env->height)
	{
		x = -1;
	//	printf("\tLine %-2d : ", line); //
		while (++x < env->width)
		{
		//	if (env->grid[y][x].z)
			//	printf("1 "); //
		//	else
			//	printf("0 "); //
			if (x < env->width - 1)
				draw_line(transform(env->grid[y][x], env), transform(env->grid[y][x + 1], env), env);
			if (y < env->height - 1)
			draw_line(transform(env->grid[y][x], env), transform(env->grid[y + 1][x], env), env);
		}
		//printf("\n"); //
		line++;
	}
}
