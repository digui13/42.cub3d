/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:42:11 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/05 00:13:25 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/cub3d.h"

static void	check_file_values(t_data *data)
{
	if (!data->file.no_path || !data->file.so_path || !data->file.we_path || !data->file.ea_path  || !data->file.ceiling || !data->file.floor || !data->map.matrix)
		gameover(data, EXIT_FAILURE, "Error: Miss file values");
}

static void	set_orientation_path(t_data *data, char *line, )
{
	// skip chars
	data.
}

void	line_handler(t_data *data)
{
	int	inc;

	inc = 0;
	while (*(data->rd.line + inc) != '\0')
	{
		if (!data->file.no_path && !strncmp((data->rd.line + inc), "NO "))
			set_orientation_path(data, (data->rd.line + inc + 4));
		else if (!data->file.so_path && !strncmp((data->rd.line + inc), "SO "))

		else if (!data->file.we_path && !strncmp((data->rd.line + inc), "WE "))

		else if (!data->file.ea_path && !strncmp((data->rd.line + inc), "EA "))
		skip_spaces((data->rd.line + inc), inc);
		inc++;
	}
}

void	reading(t_data *data, char *filename)
{
	data->rd.fd = open(filename, O_RDONLY);
	if (data->rd.fd == -1)
		gameover(data, FAIL, "Error: File doesnt open");
	data->rd.line = get_next_line(data->rd.fd );
	while (data->rd.line != NULL)
	{
		line_handler(data);
		data->rd.line = get_next_line(data->rd.fd);
	}
	close(data->rd.fd);
	check_file_values(data);
}