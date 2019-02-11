/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 05:16:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/11 21:21:58 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "env.h"
#include "mlx.h"

static void	print_controls(void *id, void *win)
{
	mlx_string_put(id, win, 1810, 10, 0xFFFFFF, "- Controls -");
	mlx_string_put(id, win, 1850, 50, 0xFFFFFF, "Move");
	mlx_string_put(id, win, 1805, 80, 0xFFFFFF, "W / A / S / D");
	mlx_string_put(id, win, 1840, 110, 0xFFFFFF, "Height");
	mlx_string_put(id, win, 1795, 140, 0xFFFFFF, "Pg_up / Pg_down");
}

void		print_map(t_env *env)
{
	int	y;
	int	x;

	y = -1;
	print_controls(env->mlx->id, env->mlx->win);
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
		{
			if (x < env->width - 1)
				draw_line(transform(env->grid[y][x], env), transform(env->grid[y][x + 1], env), env);
			if (y < env->height - 1)
				draw_line(transform(env->grid[y][x], env), transform(env->grid[y + 1][x], env), env);
		}
	}
}
