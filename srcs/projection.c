/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 07:52:39 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/07 09:05:13 by kibotrel         ###   ########.fr       */
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

t_pos			transform(t_pos p, t_env *env)
{
	p.y *= env->cam->zoom;
	p.x *= env->cam->zoom;
	if (env->cam->type == ISO)
		p = isometric(p);
	p.y += HEIGHT / 2;
	p.x += WIDTH / 2;
	return (p);
}
