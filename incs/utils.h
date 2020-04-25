/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 00:48:39 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 05:23:12 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

int		row_size(char **coords);
int		is_validname(char *filename);
void	check_row(char *row);
void	free_tab(char **coords);
void	expand_grid(t_pos **table, t_env *env);

void	print_error(char *description, int error);
void	police_color(SDL_Color *color, int r, int g, int b);

void	text(t_env *env, char *str, t_pos pos, int mode);
void	draw_pixel(SDL_Surface *win, t_pos p, unsigned int color);
#endif
