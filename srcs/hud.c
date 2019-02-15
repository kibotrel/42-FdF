/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:56:28 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 07:02:53 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "fdf.h"
#include "env.h"

void		toggle_hud(t_env *env)
{
	env = new_img(env);
	env->cam->hud *= -1;
	print_map(env);
}

static void	print_boxes(t_env *env)
{
	int	y;
	int	x;

	y = 299;
	while (++y < 951)
	{
		x = 1714;
		while (++x < WIDTH)
		{
			if (y < 303 || (y > 948 && y < 951) || x < 1717)
				pixel_to_image(env, x, y, 0xFFFFFF);
			else
				pixel_to_image(env, x, y, 0x242424);
		}
	}
	y = 1119;
	while (++y < HEIGHT)
	{
		x = 824;
		while (++x < 1155)
		{
			if (y < 1123 || x < 828 || x > 1152)
				pixel_to_image(env, x, y, 0xFFFFFF);
			else
				pixel_to_image(env, x, y, 0x242424);
		}
	}
}

static void	print_credits(void *id, void *win)
{
	mlx_string_put(id, win, 865, 1150, 0x68C800, "Wireframe made by kibotrel");
}

static void	print_controls(void *id, void *win)
{
	mlx_string_put(id, win, 1835, 320, 0x68C800, "Moves");
	mlx_string_put(id, win, 1795, 350, 0xFFFFFF, "W / A / S / D");
	mlx_string_put(id, win, 1830, 400, 0x68C800, "Height");
	mlx_string_put(id, win, 1785, 430, 0xFFFFFF, "Pg_up / Pg_down");
	mlx_string_put(id, win, 1807, 480, 0x68C800, "Projections");
	mlx_string_put(id, win, 1836, 510, 0xFFFFFF, "I / P");
	mlx_string_put(id, win, 1815, 560, 0x68C800, "Rotations");
	mlx_string_put(id, win, 1755, 590, 0xFFFFFF, "2 / 3 / 4 / 6 / 7 / 8");
	mlx_string_put(id, win, 1809, 640, 0x68C800, "Reset view");
	mlx_string_put(id, win, 1853, 670, 0xFFFFFF, "R");
	mlx_string_put(id, win, 1807, 720, 0x68C800, "Toggle HUD");
	mlx_string_put(id, win, 1853, 750, 0xFFFFFF, "H");
	mlx_string_put(id, win, 1820, 800, 0x68C800, "Colorset");
	mlx_string_put(id, win, 1815, 830, 0xFFFFFF, "Z / X / C");
	mlx_string_put(id, win, 1833, 880, 0x68C800, "Close");
	mlx_string_put(id, win, 1843, 910, 0xFFFFFF, "Esc");
}

void		print_hud(t_env *env, int draw)
{
	if (env->cam->hud == 1)
	{
		if (!draw)
			print_boxes(env);
		else
		{
			print_controls(env->mlx->id, env->mlx->win);
			print_credits(env->mlx->id, env->mlx->win);
		}
	}
}
