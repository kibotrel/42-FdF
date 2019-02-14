/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 07:52:39 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/14 18:42:25 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "env.h"

static t_pos	isometric(t_pos p)
{
	int	y;
	int	x;

	y = p.y;
	x = p.x;
	p.y = -p.z + (x + y) * sin(0.523599);
	p.x = (x - y) * cos(0.523599);
	return (p);
}

static t_pos	parallel(t_pos p)
{
	int y;
	int x;

	y = p.y;
	x = p.x;
	p.z += 50;
	p.y = y - p.z * sin(0.785398);
	p.x = x - p.z * cos(0.785398);
	return (p);
}

t_pos			transform(t_pos p, t_env *env)
{
	p.color = init_color(env, p.z);
	p.y *= env->cam->zoom;
	p.x *= env->cam->zoom;
	p.z *= env->cam->zoom / env->cam->depth;
	p.x -= (env->width * env->cam->zoom) / 2;
	p.y -= (env->height * env->cam->zoom) / 2;
	p = rotate_x(p, env->cam->alpha);
	p = rotate_y(p, env->cam->beta);
	p = rotate_z(p, env->cam->gamma);
	if (env->cam->type == ISOMETRIC)
		p = isometric(p);
	if (env->cam->type == PARALLEL)
		p = parallel(p);
	p.y += HEIGHT / 2 + env->cam->offset_y;
	p.x += WIDTH / 2 + env->cam->offset_x;
	return (p);
}
