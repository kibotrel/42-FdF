/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 22:31:10 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/05 02:07:37 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static void	print_usage(void)
{
	/*
	**	Error 1 : Malloc
	**	Error 2 : Read
	**	Error 3 : Close
	**	Error 4 : Filename
	**	Error 5 : Map width
	**	Error 6 : Missing points
	** 	Error 7 : Empty row
	**	Error 8 : Format

	*/

	ft_putendl("usage: Work in Progress.");
}

void		print_error(char *desc, int error)
{
	ft_putendl(desc);
	exit(error);
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			print_error("Error : Can't allocate memory.", 1);
		parse_file(av[1], env);
	}
	else
		print_usage();
	return (0);
}
