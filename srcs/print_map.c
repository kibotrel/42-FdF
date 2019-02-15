/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 05:16:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 10:01:03 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fdf.h"

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
	print_hud(env, 0);
	mlx_put_image_to_window(env->mlx->id, env->mlx->win,
		env->mlx->img->id, 0, 0);
	print_hud(env, 1);
}
