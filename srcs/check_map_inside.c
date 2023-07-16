/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_inside.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:54:58 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 19:26:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

static void	check_up_down_left_right(t_data *data, char **matrix, int x, int y)
{
	if (*(*(matrix + y + 1) + x) == ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (*(*(matrix + y - 1) + x) == ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (*(*(matrix + y) + x + 1) == ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (*(*(matrix + y) + x - 1) == ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
}

static void	check_diagonal(t_data *data, char **matrix, int x, int y)
{
	if (*(*(matrix + y - 1) + x - 1) == ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (*(*(matrix + y - 1) + x + 1) == ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (*(*(matrix + y + 1) + x + 1) == ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (*(*(matrix + y + 1) + x - 1) == ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
}

static void	check_surrounds_limits(t_data *data, int x, int y)
{
	if (!((y + 1) < data->map.lines))
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (!(x + 1 < *(data->map.max_x + y)))
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (!(x + 1 < *(data->map.max_x + y + 1)))
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
	if (!(x + 1 < *(data->map.max_x + y - 1)))
		gameover(data, EXIT_FAILURE,
			"Error: Map is not surrounded by walls");
}

void	check_map_inside(t_data *data, char **matrix, int x, int y)
{
	if (x == 0 || x == (*(data->map.max_x + y) - 1)
		|| y == 0 || y == (data->map.lines - 1))
		return ;
	if (*(*(matrix + y) + x) != '0'
		&& *(*(matrix + y) + x) != 'N'
		&& *(*(matrix + y) + x) != 'S'
		&& *(*(matrix + y) + x) != 'E'
		&& *(*(matrix + y) + x) != 'W')
		return ;
	check_surrounds_limits(data, x, y);
	check_up_down_left_right(data, matrix, x, y);
	check_diagonal(data, matrix, x, y);
}
