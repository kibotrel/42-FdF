/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 03:30:20 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 11:31:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "env.h"
#include "fdf.h"

void	zoom(t_env *env, int key)
{
	env = new_img(env);
	if (key == PLUS)
		env->cam->zoom++;
	if (key == MINUS && env->cam->zoom > 1)
		env->cam->zoom--;
	print_map(env);
}

void	projection(t_env *env, int key)
{
	env = new_img(env);
	if (key == I)
		env->cam->type = ISOMETRIC;
	if (key == P)
		env->cam->type = PARALLEL;
	env->cam->zoom = get_zoom(WIDTH / env->width / 2, HEIGHT / env->height / 2);
	env->cam->offset_x = 0;
	env->cam->offset_y = 0;
	env->cam->depth = 20.0;
	env->cam->alpha = 0.0;
	env->cam->beta = 0.0;
	env->cam->gamma = 0.0;
	print_map(env);
}

void	offset(t_env *env, int key)
{
	env = new_img(env);
	if (key == W)
		env->cam->offset_y -= OFFSET;
	if (key == A)
		env->cam->offset_x -= OFFSET;
	if (key == S)
		env->cam->offset_y += OFFSET;
	if (key == D)
		env->cam->offset_x += OFFSET;
	print_map(env);
}

void	scale_height(t_env *env, int key)
{
	env = new_img(env);
	if (key == PG_UP && env->cam->depth > MIN_DEPTH)
		env->cam->depth -= 0.4;
	if (key == PG_DOWN && env->cam->depth < MAX_DEPTH)
		env->cam->depth += 0.4;
	print_map(env);
}
