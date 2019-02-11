/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 00:52:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/11 21:24:48 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"
#include "env.h"

static void	init_mlx(t_env *env)
{
	t_mlx	*fdf_mlx;

	if (!(fdf_mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		print_error("Error : Can't allocate memory.", 1);
	fdf_mlx->id = mlx_init();
	fdf_mlx->win = mlx_new_window(fdf_mlx->id, WIDTH, HEIGHT, TITLE);
	env->mlx =fdf_mlx;
}

static void	init_cam(t_env *env)
{
	t_cam	*fdf_cam;

	if (!(fdf_cam = (t_cam*)malloc(sizeof(t_cam))))
		print_error("Error : Can't allocate memory.", 1);
	fdf_cam->type = ISOMETRIC;
	fdf_cam->zoom = init_zoom(WIDTH / env->width / 2, HEIGHT / env->height / 2);
	fdf_cam->offset_y = 0;
	fdf_cam->offset_x = 0;
	fdf_cam->depth = 5.0;
	env->cam = fdf_cam;
}

static void	init_env(t_env *env)
{
	int		y;
	int		x;

	y = -1;
	env->z_min = 0;
	env->z_max = 0;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
		{
			if (env->grid[y][x].z < env->z_min)
				env->z_min = env->grid[y][x].z;
			if (env->grid[y][x].z > env->z_max)
				env->z_max = env->grid[y][x].z;
		}
	}
}

void	initialize(t_env *env)
{
	init_mlx(env);
	init_cam(env);
	init_env(env);
}
