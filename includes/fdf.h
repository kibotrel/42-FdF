/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 00:07:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/07 05:46:47 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_mlx
{
	void		*id;
	void		*win;
}				t_mlx;

typedef struct	s_cam
{
	int			type;
}				t_cam;

typedef struct	s_pos
{
	int			y;
	int			x;
	int			z;
}				t_pos;

typedef struct	s_env
{
	t_mlx		*mlx;
	t_cam		*cam;
	t_pos		**grid;
	int			height;
	int			width;
	int			gap;
}				t_env;

/*
**	main.c
*/

void			print_error(char *desc, int error);

/*
**	parsing.c
*/

void			parse_file(char *file, t_env *env);

/*
**	utils.c
*/

void			check_row(char *row);
void			expand_grid(t_pos **table, t_env *env);
int				row_size(char **coords);
int				is_validname(char *filename);

/*
** setup.c
*/

void			initialize(t_env *env);

/*
**	print_map.c
*/

void			print_map(t_env *env);

#endif
