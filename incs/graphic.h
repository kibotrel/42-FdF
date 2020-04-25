/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 00:48:39 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/22 08:24:06 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "structs.h"

typedef struct	s_line
{
	int			error;
	int			offset;
	int			sign_y;
	int			sign_x;
	int			delta_y;
	int			delta_x;
}				t_line;

void			draw_line(t_pos a, t_pos b, t_env *env);

int				init_color(t_env *env, int z);
int				gradient(t_pos pos, t_pos start, t_pos end, t_line params);

t_pos			transform(t_pos p, t_env *env);

#endif
