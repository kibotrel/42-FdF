/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_presets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:23:17 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/14 22:30:06 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "fdf.h"

void	earth_set(t_env *env)
{
	env->color_min = BLUE;
	env->color_max = WHITE;
	env->color_half = GREENER;
	env->color_third = BROWN;
	env->color_fourth = GREEN;
}

void	moon_set(t_env *env)
{
	env->color_min = GRAY_MIN;
	env->color_max = WHITE;
	env->color_half = GRAY_MID;
	env->color_third = GRAY_HIGH;
	env->color_fourth = GRAY_LOW;
}

void	mars_set(t_env *env)
{
	env->color_min = BROWNER;
	env->color_max = ORANGE;
	env->color_half = REDER;
	env->color_third = BROWN;
	env->color_fourth = RED;
}
