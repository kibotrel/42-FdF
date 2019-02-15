/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 22:31:10 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 14:51:48 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "env.h"
#include "fdf.h"

static void	print_usage(void)
{
	ft_putendl("\n\033[32;1musage: ./fdf map.fdf\033[0m\033[36m");
	ft_putendl("\n\tmap.fdf : array of XYZ coordinates");
	ft_putendl("\n\033[0m\033[32;1mFile format:\033[0m\033[36m");
	ft_putendl("\n\tEach row should contains the same amount of points");
	ft_putendl("\tformated like \"height_value\" at each x,y coordinate");
	ft_putendl("\n\033[0m\033[32;1mError handling:\033[0m\033[36m");
	ft_putendl("\n\tEach following error code are handled by the program");
	ft_putendl("\n\t- Failed memory allocation (1)\n\t- Invalid read (2)");
	ft_putendl("\t- Invalid close (3)\n\t- Invalid filename (4)");
	ft_putendl("\t- Invalid map width (5)\n\t- Missing point(s) in a row (6)");
	ft_putendl("\t- Empty row (7)\n\t- Invalid map format (8)");
	ft_putendl("\t- Empty file (9)");
	ft_putendl("\n\tUse \"echo $?\" to know the last process returned value");
	ft_putendl("\n\033[0m\033[32;1mControls:\033[0m\033[36m");
	ft_putendl("\n\tThe following inputs are handled in the mlx window");
	ft_putendl("\n\t- Move the map along x and y axis (W,A,S,D)");
	ft_putendl("\t- Rotate the map along x,y,z axis (2,3,4,6,7,8)");
	ft_putendl("\t- Modify height value along x axis (Page_Up, Page_Down)");
	ft_putendl("\t- Change projection (I,P)\n\t- Change colorset (Z,X,C)");
	ft_putendl("\t- Reset view point (R)\n\t- Toggle HUD (H)");
	ft_putendl("\t- Close the window and exit the program (ESC)");
	ft_putendl("\n\t\t\t\t\t\t\033[0m\033[32;1mMade by kibotrel\n\033[0m");
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			print_error(ERR_MALLOC, 1);
		parse_file(av[1], env);
		initialize(env);
		print_map(env);
		hooks(env);
		mlx_loop(env->mlx);
	}
	else
		print_usage();
	return (0);
}
