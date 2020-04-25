/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 07:52:39 by kibotrel          #+#    #+#             */
/*   Updated: 2020/04/25 03:53:34 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "graphic.h"

static void	isometric(t_pos *new)
{
	t_pos	old;

	old = *new;
	new->y = -old.z + (old.x + old.y) * sin(0.523599);
	new->x = (old.x - old.y) * cos(0.523599);
}

static void	parallel(t_pos *new)
{
	t_pos	old;

	old = *new;
	new->y = old.y - old.z * sin(0.785398);
	new->x = old.x - old.z * cos(0.785398);
}

static void	rotate(t_pos *new, double alpha, double beta, double gamma)
{
	t_pos	old;

	old = *new;
	new->y = old.y * cos(alpha) + old.z * sin(alpha);
	new->z = -old.y * sin(alpha) + old.z * cos(alpha);
	new->x = old.x * cos(beta) + new->z * sin(beta);
	new->z = -old.x * sin(beta) + new->z * cos(beta);
	old = *new;
	new->x = old.x * cos(gamma) - old.y * sin(gamma);
	new->y = old.x * sin(gamma) + old.y * cos(gamma);
}

t_pos		transform(t_pos p, t_env *env)
{
	p.color = init_color(env, p.z);
	p.y *= env->cam.zoom;
	p.x *= env->cam.zoom;
	p.z *= env->cam.zoom / env->cam.depth;
	p.x -= (env->width * env->cam.zoom) / 2;
	p.y -= (env->height * env->cam.zoom) / 2;
	rotate(&p, env->cam.alpha, env->cam.beta, env->cam.gamma);
	env->cam.type == ISOMETRIC ? isometric(&p) : parallel(&p);
	p.y += HEIGHT / 2 + env->cam.offset_y;
	p.x += WIDTH / 2 + env->cam.offset_x;
	return (p);
}
