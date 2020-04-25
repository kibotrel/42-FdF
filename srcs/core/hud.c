/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 03:56:04 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 05:52:34 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"

static void	print_box_controls(t_env *env)
{
	t_pos	p;
	t_pos	max;
	t_pos	min;

	p.y = env->gridmin.y * 2 - 1;
	min.y = p.y + 3;
	max.y = env->gridmin.y * 30;
	max.x = WIDTH - env->gridmin.x * 13 + 2;
	while (++p.y < max.y)
	{
		p.x = WIDTH - env->gridmin.x * 13 - 1;
		while (++p.x < WIDTH)
		{
			if (p.y < min.y || p.y > max.y - 3 || p.x < max.x)
				draw_pixel(env->sdl.screen, p, 0xFFFFFF);
			else
				draw_pixel(env->sdl.screen, p, 0x242424);
		}
	}
}

static void	print_box_credits(t_env *env)
{
	t_pos	p;
	t_pos	max;
	t_pos	min;

	p.y = env->gridmin.y * 30 - 1;
	min.y = p.y + 3;
	max.x = env->gridmin.x * 34;
	min.x = env->gridmin.x * 19 + 3;
	while (++p.y < HEIGHT)
	{
		p.x = env->gridmin.x * 19 - 1;
		while (++p.x < max.x)
		{
			if (p.y < min.y || p.x < min.x || p.x > max.x - 3)
				draw_pixel(env->sdl.screen, p, 0xFFFFFF);
			else
				draw_pixel(env->sdl.screen, p, 0x242424);
		}
	}
}

static void	print_infos(t_env *env)
{
	police_color(&env->sdl.color, 0x68, 0xC8, 0x00);
	text(env, "Zoom", (t_pos){3, 49, 0, 0}, 1);
	text(env, "Move", (t_pos){6, 49, 0, 0}, 1);
	text(env, "Height level", (t_pos){9, 49, 0, 0}, 1);
	text(env, "Modify projection", (t_pos){12, 49, 0, 0}, 1);
	text(env, "Rotate view", (t_pos){15, 49, 0, 0}, 1);
	text(env, "Reset view", (t_pos){18, 49, 0, 0}, 1);
	text(env, "Toggle HUD", (t_pos){21, 49, 0, 0}, 1);
	text(env, "Change colorset", (t_pos){24, 49, 0, 0}, 1);
	text(env, "Close window", (t_pos){27, 49, 0, 0}, 1);
	text(env, "Wireframe made by kibotrel", (t_pos){31, 26, 0, 0}, 1);
	police_color(&env->sdl.color, 0xFF, 0xFF, 0xFF);
	text(env, "0 / 9", (t_pos){4, 49, 0, 0}, 1);
	text(env, "Left / Right / Up / Down", (t_pos){7, 49, 0, 0}, 1);
	text(env, "Page up / Page down", (t_pos){10, 49, 0, 0}, 1);
	text(env, "I / P", (t_pos){13, 49, 0, 0}, 1);
	text(env, "Q / W / A / D / X / C", (t_pos){16, 49, 0, 0}, 1);
	text(env, "R", (t_pos){19, 49, 0, 0}, 1);
	text(env, "H", (t_pos){22, 49, 0, 0}, 1);
	text(env, "1 / 2 / 3", (t_pos){25, 49, 0, 0}, 1);
	text(env, "Escape", (t_pos){28, 49, 0, 0}, 1);
}

void		print_hud(t_env *env)
{
	print_box_credits(env);
	print_box_controls(env);
	print_infos(env);
}
