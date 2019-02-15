/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 00:07:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 06:58:53 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


typedef struct	s_img
{
	void		*id;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*id;
	void		*win;
	t_img		*img;
}				t_mlx;

typedef struct	s_cam
{
	double		alpha;
	double		beta;
	double		gamma;
	float		depth;
	int			hud;
	int			type;
	int			zoom;
	int			offset_y;
	int			offset_x;
}				t_cam;

typedef struct	s_pos
{
	int			y;
	int			x;
	int			z;
	int			color;
}				t_pos;

typedef struct	s_env
{
	t_mlx		*mlx;
	t_cam		*cam;
	t_pos		**grid;
	int			z_min;
	int			z_max;
	int			width;
	int			height;
	int			color_min;
	int			color_max;
	int			color_half;
	int			color_third;
	int			color_fourth;
}				t_env;

typedef struct	s_line
{
	int			error;
	int			offset;
	int			sign_y;
	int			sign_x;
	int			delta_y;
	int			delta_x;
}				t_line;

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
int				absolute_value(int nb);
int				row_size(char **coords);
int				is_validname(char *filename);

/*
**	utils2.c
*/

t_env			*new_img(t_env *env);
void			free_all(t_env *param);
void			free_tab(char **coords);
int				get_zoom(int a, int b);
/*
** setup.c
*/

void			initialize(t_env *env);

/*
**	print_map.c
*/

void			print_map(t_env *env);
void			toggle_hud(t_env *env);
/*
**	draw_line.c
*/

void			draw_line(t_pos a, t_pos b, t_env *env);
void			pixel_to_image(t_env *env, int x, int y, int color);

/*
**	projection.c
*/

t_pos			transform(t_pos p, t_env *env);

/*
**	hooks.c
*/

void			hooks(t_env *env);

/*
** process_input.c
*/

void			zoom(t_env *env, int key);
void			offset(t_env *env, int key);
void			projection(t_env *env, int key);
void			scale_height(t_env *env, int key);
void			colorset(t_env *env, int key);

/*
**	color.c
*/

int				color(t_pos pos, t_pos start, t_pos end, t_line params);
int				init_color(t_env *env, int z);

/*
**	hud.c
*/

void			print_hud(t_env  *env, int draw);

/*
**	rotate.c
*/

t_pos			rotate_x(t_pos p, double alpha);
t_pos			rotate_y(t_pos p, double alpha);
t_pos			rotate_z(t_pos p, double alpha);
void			rotate(t_env *env, int key);

/*
**	color_presets.c
*/

void			mars_set(t_env *env);
void			moon_set(t_env *env);
void			earth_set(t_env *env);
#endif
