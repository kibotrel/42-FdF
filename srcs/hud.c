/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:56:28 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/14 21:22:31 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void		toggle_hud(t_env *env)
{
	env->cam->hud *= -1;
	mlx_clear_window(env->mlx->id, env->mlx->win);
	print_map(env);
}

// static void	print_infos(id, win)
// {
//
// }

static void	print_credits(void *id, void *win)
{
	mlx_string_put(id, win, 865, 1150, 0xFFFFFF, "Wireframe made by kibotrel");
}

static void	print_controls(void *id, void *win)
{
	mlx_string_put(id, win, 1800, 295, 0xFFFFFF, "- Controls -");
	mlx_string_put(id, win, 1835, 325, 0xFFFFFF, "Moves");
	mlx_string_put(id, win, 1795, 375, 0xFFFFFF, "W / A / S / D");
	mlx_string_put(id, win, 1830, 425, 0xFFFFFF, "Height");
	mlx_string_put(id, win, 1785, 455, 0xFFFFFF, "Pg_up / Pg_down");
	mlx_string_put(id, win, 1807, 505, 0xFFFFFF, "Projections");
	mlx_string_put(id, win, 1836, 535, 0xFFFFFF, "I / P");
	mlx_string_put(id, win, 1815, 585, 0xFFFFFF, "Rotations");
	mlx_string_put(id, win, 1755, 615, 0xFFFFFF, "2 / 3 / 4 / 6 / 7 / 8");
	mlx_string_put(id, win, 1833, 665, 0xFFFFFF, "Reset");
	mlx_string_put(id, win, 1853, 695, 0xFFFFFF, "R");
	mlx_string_put(id, win, 1807, 745, 0xFFFFFF, "Toggle HUD");
	mlx_string_put(id, win, 1853, 775, 0xFFFFFF, "H");
	mlx_string_put(id, win, 1820, 825, 0xFFFFFF, "Colorset");
	mlx_string_put(id, win, 1815, 855, 0xFFFFFF, "Z / X / C");
	mlx_string_put(id, win, 1833, 905, 0xFFFFFF, "Close");
	mlx_string_put(id, win, 1843, 935, 0xFFFFFF, "Esc");
}

void		print_hud(void *id, void *win)
{
	print_controls(id, win);
	// print_infos(id, win);
	print_credits(id, win);
}
