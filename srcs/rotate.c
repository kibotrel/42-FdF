/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:43:08 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 07:03:00 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "env.h"
#include "fdf.h"

void	rotate(t_env *env, int key)
{
	env = new_img(env);
	if (key == NUM2)
		env->cam->alpha += 0.05;
	if (key == NUM8)
		env->cam->alpha -= 0.05;
	if (key == NUM4)
		env->cam->beta -= 0.05;
	if (key == NUM6)
		env->cam->beta += 0.05;
	if (key == NUM3)
		env->cam->gamma -= 0.05;
	if (key == NUM7)
		env->cam->gamma += 0.05;
	print_map(env);
}

t_pos	rotate_x(t_pos p, double alpha)
{
	int	y;

	y = p.y;
	p.y = y * cos(alpha) + p.z * sin(alpha);
	p.z = -y * sin(alpha) + p.z * cos(alpha);
	return (p);
}

t_pos	rotate_y(t_pos p, double beta)
{
	int	x;

	x = p.x;
	p.x = x * cos(beta) + p.z * sin(beta);
	p.z = -x * sin(beta) + p.z * cos(beta);
	return (p);
}

t_pos	rotate_z(t_pos p, double gamma)
{
	int	x;
	int	y;

	x = p.x;
	y = p.y;
	p.x = x * cos(gamma) - y * sin(gamma);
	p.y = x * sin(gamma) + y * cos(gamma);
	return (p);
}
