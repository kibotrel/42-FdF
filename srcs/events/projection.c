/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 03:18:46 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:22:53 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

void	projection(t_env *env)
{
	if (env->input[SDL_SCANCODE_I])
		env->cam.type = ISOMETRIC;
	if (env->input[SDL_SCANCODE_P])
		env->cam.type = PARALLEL;
	reset_view(env);
}
