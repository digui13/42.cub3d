/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:44:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 14:17:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	check_args(t_data *data, int ac)
{
	if (ac != 2)
		gameover(data, FAIL, "Error: Invalid args number");
}

static void	check_map_line(t_data *data, char *line, int y)
{
	int	x;

	x = 0;
	while (*(line + x) != '\0')
	{
		if (y == 0 && *(line + x) != '1' && *(line + x) != ' ')
			gameover(data, EXIT_FAILURE,
				"Error: Map has invalid char in first line");
		if (y == (data->map.lines - 1) && *(line + x) != '1' && *(line + x) != ' ')
			gameover(data, EXIT_FAILURE,
				"Error: Map has invalid char in last line");
		if (x == 0 && *(line + x) != '1' && *(line + x) != ' ')
			gameover(data, EXIT_FAILURE,
				"Error: Map has invalid char in first col");
		// if (x == (*(data->map.max_x + y) - 1) && *(line + x) != '1' && *(line + x) != ' ')
		//gameover(data, EXIT_FAILURE,
		//		"Error: Map has invalid char in last col");

		// if (x != 0 && x != (*(data->map.max_x + y) - 1) && y != 0 && y != (data->map.lines - 1))
		// if (*(line + x) == ' ')
		/*
		
			x-1 
			x+1 
			y+1 
			y-1

			x-1 y+1
			x-1 y-1
			x+1 y+1
			x+1 y-1

			has to equal to ' ' or '1'
			ifnt show error

		*/
		x++;
	}
}

void	check_map(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map.lines)
	{
		check_map_line(data, *(data->map.matrix + y), y);
		y++;
	}
}