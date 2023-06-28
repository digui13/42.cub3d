/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:46:31 by dpestana          #+#    #+#             */
/*   Updated: 2023/06/28 16:04:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/cub3d.h"

static void	error(char *msg)
{
	if (msg)
		while (*msg)
			write(STDERR_FILENO, msg++, 1);
	write(STDERR_FILENO,"\n",1);
}

void	gameover(int status char *msg)
{
	error(msg);
	exit(status);
}