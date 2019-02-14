/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 05:16:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/14 22:31:56 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "env.h"

void		print_map(t_env *env)
{
	int	y;
	int	x;

	y = -1;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
		{
			if (x < env->width - 1)
				draw_line(transform(env->grid[y][x], env),
				transform(env->grid[y][x + 1], env), env);
			if (y < env->height - 1)
				draw_line(transform(env->grid[y][x], env),
				transform(env->grid[y + 1][x], env), env);
		}
	}
	if (env->cam->hud == 1)
		print_hud(env->mlx->id, env->mlx->win);
}
