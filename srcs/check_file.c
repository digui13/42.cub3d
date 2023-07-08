/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:31:17 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 21:36:34 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	check_filename(t_data *data, char *filename)
{
	int	inc;

	inc = 0;
	while (*(filename + inc) != '\0')
	{
		if (!ft_strcmp((filename + inc), ".cub") && inc != 0)
			return ;
		inc++;
	}
	gameover(data, FAIL, "Error: Invalid filename");
}

int	has_file_orientations(t_data *data)
{
	if (data->file.no_path && data->file.so_path && data->file.we_path && data->file.ea_path)
		return (YES);
	return (NO);
}

int	has_file_colors(t_data *data)
{
	if (data->file.ceiling && data->file.floor)
		return (YES);
	return (NO);
}

int	has_file_map(t_data *data)
{
	if (data->map.matrix)
		return (YES);
	return (NO);
}