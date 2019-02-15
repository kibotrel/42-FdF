/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 00:52:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 07:06:24 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"
#include "env.h"

static void	init_mlx(t_env *env)
{
	t_mlx	*fdf_mlx;
	t_img	*fdf_img;

	if (!(fdf_mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		print_error("Error : Can't allocate memory.", 1);
	fdf_mlx->id = mlx_init();
	fdf_mlx->win = mlx_new_window(fdf_mlx->id, WIDTH, HEIGHT, TITLE);
	if (!(fdf_img = (t_img*)malloc(sizeof(t_img))))
		print_error("Error : Can't allocate memory.", 1);
	fdf_img->id = mlx_new_image(fdf_mlx->id, WIDTH, HEIGHT);
	fdf_img->data = mlx_get_data_addr(fdf_img->id, &(fdf_img->bpp), &(fdf_img->size), &(fdf_img->endian));
	env->mlx = fdf_mlx;
	env->mlx->img = fdf_img;
}

static void	init_cam(t_env *env)
{
	t_cam	*fdf_cam;

	if (!(fdf_cam = (t_cam*)malloc(sizeof(t_cam))))
		print_error("Error : Can't allocate memory.", 1);
	fdf_cam->type = ISOMETRIC;
	fdf_cam->zoom = get_zoom(WIDTH / env->width / 2, HEIGHT / env->height / 2);
	fdf_cam->offset_y = 0;
	fdf_cam->offset_x = 0;
	fdf_cam->depth = 5.0;
	fdf_cam->alpha = 0.0;
	fdf_cam->beta = 0.0;
	fdf_cam->gamma = 0.0;
	fdf_cam->hud = 1;
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
	env->color_min = BLUE;
	env->color_max = WHITE;
	env->color_half = GREENER;
	env->color_third = BROWN;
	env->color_fourth = GREEN;
}

void		initialize(t_env *env)
{
	init_mlx(env);
	init_cam(env);
	init_env(env);
}
