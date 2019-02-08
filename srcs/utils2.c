/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 02:07:46 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/08 04:46:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	free_all(t_env *env)
{
	int	y;

	y = -1;
	free(env->mlx);
	free(env->cam);
	while(++y < env->height)
		free(env->grid[y]);
	free(env->grid);
	free(env);
}

int		init_zoom(int a, int b)
{
	return (a < b ? a : b);
}
