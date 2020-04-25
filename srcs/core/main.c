/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 00:37:46 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 06:58:29 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "core.h"
#include "clean.h"
#include "libft.h"
#include "setup.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		parse_file(av[1], &env);
		setup(&env);
		while (1)
		{
			ft_bzero(env.sdl.screen->pixels, env.sdl.resolution);
			hooks(&env);
			print_map(&env);
			if (env.cam.hud > 0)
				print_hud(&env);
			if (SDL_UpdateWindowSurface(env.sdl.win))
				clean(&env, 15, ERR_SDL_UPDATE);
		}
	}
	else
		usage();
	return (0);
}
