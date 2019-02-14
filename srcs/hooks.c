/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 02:01:56 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/14 22:22:11 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "env.h"

static int		red_cross(void *env)
{
	free_all(env);
	exit(0);
	return (0);
}

static int		read_input(int key, void *env)
{
	if (key == ESC)
		red_cross(env);
	if (key == PLUS || key == MINUS)
		zoom(env, key);
	if (key == I || key == P || key == R)
		projection(env, key);
	if (key == W || key == A || key == S || key == D)
		offset(env, key);
	if (key == PG_UP || key == PG_DOWN)
		scale_height(env, key);
	if (key == Z || key == X || key == C)
		colorset(env, key);
	if (key == H)
		toggle_hud(env);
	if (key == NUM2 || key == NUM3 || key == NUM4 || key == NUM6
		|| key == NUM7 || key == NUM8)
		rotate(env, key);
	return (0);
}

void			hooks(t_env *env)
{
	mlx_hook(env->mlx->win, 17, 0, red_cross, env);
	mlx_hook(env->mlx->win, 2, 0, read_input, env);
}
