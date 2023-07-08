/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:56:18 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 21:39:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	initialize(t_data *data)
{
	data->file.no_path = NULL;
	data->file.so_path = NULL;
	data->file.we_path = NULL;
	data->file.ea_path = NULL;
	data->file.ceiling = NULL;
	data->file.floor = NULL;
	data->map.max_x = -1;
	data->map.max_y = -1;
	data->map.matrix = NULL;
	data->rd.fd = NULL;
	data->rd.line = NULL;
}