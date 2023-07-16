/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:46:31 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 11:17:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

static void	clean(t_data *data)
{
	clean_file_elements(data);
	clean_file_map(data);
}

static void	error(char *msg)
{
	if (msg)
	{
		write(STDERR_FILENO, "Error\n", 6);
		while (*msg)
			write(STDERR_FILENO, msg++, 1);
		write(STDERR_FILENO, "\n", 1);
	}
}

void	gameover(t_data *data, int status, char *msg)
{
	clean(data);
	error(msg);
	exit(status);
}
