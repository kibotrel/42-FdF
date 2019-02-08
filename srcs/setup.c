/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 00:52:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/08 04:47:41 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

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
	printf("Minilibx infos :\n\n\tIdentifiant       : %p\n\tWindow            : %p\n\tWindow dimensions : %d x %d\n\n", env->mlx->id, env->mlx->win, HEIGHT, WIDTH);//
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
	printf("Cam infos :\n\n\tType : %d\n\tZoom : %d\n\n", env->cam->type, env->cam->zoom); //
}

void	initialize(t_env *env)
{
	init_mlx(env);
	init_cam(env);
}
