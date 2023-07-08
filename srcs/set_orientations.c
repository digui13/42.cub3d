/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_orientations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:07:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 20:54:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	set_no_path(t_data *data, char *line, char *element, int *inc)
{
	int	length;
	
	if (data->file.no_path)
		gameover(data, EXIT_FAILURE, "Error: Duplicate elements");
	skip_str();
	data->file.no_path = my_strndup();
}
