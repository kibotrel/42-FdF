/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 10:11:08 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:54:01 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "utils.h"

static void	clean_env(t_env *env)
{
	int	y;

	y = -1;
	while (++y < env->height)
		free(env->grid[y]);
	free(env->grid);
}

void		clean(t_env *env, int error, char *description)
{
	clean_env(env);
	clean_sdl(env);
	clean_ttf(env);
	error ? print_error(description, error) : exit(0);
}
