/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 00:54:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/05 01:18:56 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_validname(char *filename)
{
	int		i;
	int		j;
	char	*reference;

	reference = ".fdf";
	i = ft_strlen(filename) - 1;
	j = 3;
	while (j >= 0)
		if (filename[i--] != reference[j--])
			return (0);
	return (i >= 0 ? 1 : 0);
}
