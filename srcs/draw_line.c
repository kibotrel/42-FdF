/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 05:52:42 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/11 18:36:11 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

static t_line	setup_params(t_pos a, t_pos b)
{
	t_line	params;

	params.sign_y = (a.y < b.y ? 1 : -1);
	params.sign_x = (a.x < b.x ? 1 : -1);
	params.delta_y = absolute_value(b.y - a.y);
	params.delta_x = absolute_value(b.x - a.x);
	params.offset = params.delta_x - params.delta_y;
	params.error = 0;
	return (params);
}
void			draw_line(t_pos a, t_pos b, t_env *env)
{
	t_line	params;
	t_pos	p;

	params = setup_params(a, b);
	p = a;
	while (p.y != b.y || p.x != b.x)
	{
		mlx_pixel_put(env->mlx->id, env->mlx->win, p.x, p.y, color(p, a, b, params));
		if ((params.error = params.offset * 2) > -params.delta_y)
		{
			params.offset -= params.delta_y;
			p.x += params.sign_x;
		}
		if (params.error < params.delta_x)
		{
			params.offset += params.delta_x;
			p.y += params.sign_y;
		}
	}
	mlx_pixel_put(env->mlx->id, env->mlx->win, p.x, p.y, color(p, a, b, params));
}
