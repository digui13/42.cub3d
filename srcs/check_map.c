/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:43:35 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 19:54:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

static void	check_map_limmits_up_down(t_data *data, char *line, int x, int y)
{
	if (y == 0 && *(line + x) != '1' && *(line + x) != ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map has invalid char in first line");
	if (y == (data->map.lines - 1) && *(line + x) != '1' && *(line + x) != ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map has invalid char in last line");
}

static void	check_map_limits_left_right(t_data *data, char *line, int x, int y)
{
	if (x == 0 && *(line + x) != '1' && *(line + x) != ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map has invalid char in first col");
	if (x == (*(data->map.max_x + y) - 1)
		&& *(line + x) != '1' && *(line + x) != ' ')
		gameover(data, EXIT_FAILURE,
			"Error: Map has invalid char in last col");
}

static void	check_map_line(t_data *data, char *line, int y, char **matrix)
{
	int	x;

	x = 0;
	while (*(line + x) != '\0')
	{
		check_map_limmits_up_down(data, line, x, y);
		check_map_limits_left_right(data, line, x, y);
		check_map_inside(data, matrix, x, y);
		if (!is_valid_symbol(*(line + x)) && *(line + x) != ' ')
			gameover(data, EXIT_FAILURE,
				"Error: Map has invalid char");
		if (is_spawn(*(line + x)))
		{
			if (data->player.dir != -1)
				gameover(data, EXIT_FAILURE,
					"Error: Map has more than one player spawns");
			data->player.x = x;
			data->player.y = y;
			data->player.dir = *(line + x);
		}
		x++;
	}
}

void	check_map(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map.lines)
	{
		check_map_line(data, *(data->map.matrix + y), y, data->map.matrix);
		y++;
	}
}
