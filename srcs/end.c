/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:46:31 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/03 17:14:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/cub3d.h"

static void	clean(t_data *data)
{
	clean_file(data);
	clean_map(data);
}

static void	error(char *msg)
{
	if (msg)
	{
		while (*msg)
			write(STDERR_FILENO, msg++, 1);
		write(STDERR_FILENO,"\n",1);
	}
}

void	gameover(t_data *data, int status, char *msg)
{
	clean(data);
	error(msg);
	exit(status);
}