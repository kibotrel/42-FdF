/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 19:13:18 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/22 19:15:19 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	clean_sdl(t_env *env)
{
	if (env->sdl.screen)
		SDL_FreeSurface(env->sdl.screen);
	if (env->sdl.win)
		SDL_DestroyWindow(env->sdl.win);
	SDL_Quit();
}
