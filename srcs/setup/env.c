/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:35:19 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 05:02:21 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"

static void	setup_cam(t_env *env)
{
	env->cam.type = ISOMETRIC;
	env->cam.zoom = fmin(WIDTH / env->width / 2, HEIGHT / env->height / 2);
	env->cam.offset_y = 0;
	env->cam.offset_x = 0;
	env->cam.depth = 20.0;
	env->cam.alpha = 0.0;
	env->cam.beta = 0.0;
	env->cam.gamma = 0.0;
	env->cam.hud = 1;
}

static void	setup_env(t_env *env)
{
	t_pos	p;

	p.y = -1;
	env->z_min = 0;
	env->z_max = 0;
	while (++p.y < env->height)
	{
		p.x = -1;
		while (++p.x < env->width)
		{
			if (env->grid[p.y][p.x].z < env->z_min)
				env->z_min = env->grid[p.y][p.x].z;
			if (env->grid[p.y][p.x].z > env->z_max)
				env->z_max = env->grid[p.y][p.x].z;
		}
	}
	env->color_min = BLUE;
	env->color_max = WHITE;
	env->color_half = GREENER;
	env->color_third = BROWN;
	env->color_fourth = GREEN;
	env->delay = 0;
	env->gridmin.x = WIDTH / 54;
	env->gridmin.y = HEIGHT / 32;
	ft_bzero(env->input, sizeof(int) * SDL_NUM_SCANCODES);
}

void		setup(t_env *env)
{
	setup_env(env);
	setup_cam(env);
	setup_sdl(env);
	setup_ttf(env);
}
