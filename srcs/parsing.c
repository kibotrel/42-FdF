/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 00:26:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/05 01:18:51 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "fdf.h"

void	parse_file(char *file, t_env *env)
{
	int fd;

	(void)env;
	if (!is_validname(file))
		print_error("Error : Wrong filename (expected *.fdf).", 4);
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error("Error : Can't open file.", 2);
	if (close(fd))
		print_error("Error : Can't close file.", 3);
}
