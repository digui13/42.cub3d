/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:34:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/17 17:50:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	load_game(t_data *data)
{
	data->win.mlx = mlx_init();
	data->win.mlx_win = mlx_new_window(data->win.mlx, 100, 100, "cub3d");

/*
	data->texture.no = mlx_xpm_file_to_image(g.win.mlx, "img/player.xpm", &t.width, &t.height);
	data->texture.ea = mlx_xpm_file_to_image(g.win.mlx, "img/player.xpm", &t.width, &t.height);
	data->texture.we = mlx_xpm_file_to_image(g.win.mlx, "img/player.xpm", &t.width, &t.height);
	data->texture.so = mlx_xpm_file_to_image(g.win.mlx, "img/player.xpm", &t.width, &t.height);

	mlx_destroy_image(data->win.mlx, data->texture.no);
*/
	mlx_destroy_window(data->win.mlx, data->win.mlx_win);
}
