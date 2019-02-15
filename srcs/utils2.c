/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 02:07:46 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 07:20:21 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "env.h"
#include "mlx.h"

void	free_all(t_env *env)
{
	int	y;

	y = -1;
	free(env->mlx->img);
	free(env->mlx);
	free(env->cam);
	while (++y < env->height)
		free(env->grid[y]);
	free(env->grid);
	free(env);
}

void	free_tab(char **coords)
{
	int	y;

	y = 0;
	while (coords[y])
		free(coords[y++]);
	free(coords);
}

t_env	*new_img(t_env *env)
{
	mlx_destroy_image(env->mlx->id, env->mlx->img->id);
	env->mlx->img->id = mlx_new_image(env->mlx->id, WIDTH, HEIGHT);
	env->mlx->img->data = mlx_get_data_addr(env->mlx->img->id,
		&(env->mlx->img->bpp), &(env->mlx->img->size),
		&(env->mlx->img->endian));
	return (env);
}

int		get_zoom(int a, int b)
{
	return (a < b ? a : b);
}
