/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:46:31 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 20:52:25 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

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