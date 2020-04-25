/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:45:55 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 07:01:36 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "clean.h"
#include "utils.h"

void	setup_ttf(t_env *env)
{
	if (TTF_Init())
		clean(env, 13, ERR_TTF_INIT);
	if (!(env->sdl.font = TTF_OpenFont("assets/courrier_new.ttf", FONT_SIZE)))
		clean(env, 14, ERR_TTF_FONT);
	TTF_SetFontStyle(env->sdl.font, TTF_STYLE_BOLD);
	police_color(&env->sdl.color, 0xFF, 0xFF, 0xFF);
}
