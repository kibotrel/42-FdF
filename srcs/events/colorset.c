/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 03:41:09 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:43:50 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "structs.h"

static void	earth_set(t_env *env)
{
	env->color_min = BLUE;
	env->color_max = WHITE;
	env->color_half = GREENER;
	env->color_third = BROWN;
	env->color_fourth = GREEN;
}

static void	moon_set(t_env *env)
{
	env->color_min = GRAY_MIN;
	env->color_max = WHITE;
	env->color_half = GRAY_MID;
	env->color_third = GRAY_HIGH;
	env->color_fourth = GRAY_LOW;
}

static void	mars_set(t_env *env)
{
	env->color_min = BROWNER;
	env->color_max = ORANGE;
	env->color_half = REDER;
	env->color_third = BROWN;
	env->color_fourth = RED;
}

void		colorset(t_env *env)
{
	if (env->input[SDL_SCANCODE_1])
		earth_set(env);
	if (env->input[SDL_SCANCODE_2])
		mars_set(env);
	if (env->input[SDL_SCANCODE_3])
		moon_set(env);
}
