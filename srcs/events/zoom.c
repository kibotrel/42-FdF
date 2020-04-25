/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 03:01:32 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:11:26 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	zoom(t_env *env)
{
	if (env->input[SDL_SCANCODE_0])
		env->cam.zoom++;
	if (env->input[SDL_SCANCODE_9] && env->cam.zoom > 0)
		env->cam.zoom--;
}
