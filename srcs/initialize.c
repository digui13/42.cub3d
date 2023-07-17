/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:56:18 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/17 16:33:35 by dpestana         ###   ########.fr       */
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
	data->map.matrix = NULL;
	data->map.max_x = NULL;
	data->map.lines = 0;
	data->rd.fd = -1;
	data->rd.line = NULL;
	data->rd.map_end = NO;
	data->player.dir = -1;
	data->player.x = -1;
	data->player.y = -1;
	data->win.mlx = NULL;
	data->win.mlx_win = NULL;
	data->texture.ea = NULL;
	data->texture.no = NULL;
	data->texture.so = NULL;
	data->texture.we = NULL;
	data->texture.height = -1;
	data->texture.width = -1;
}
