/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:42:11 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/06 03:20:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/cub3d.h"

static void	check_file_values(t_data *data)
{
	if (!data->file.no_path || !data->file.so_path || !data->file.we_path || !data->file.ea_path  || !data->file.ceiling || !data->file.floor || !data->map.matrix)
		gameover(data, EXIT_FAILURE, "Error: Miss file values");
}

static void	set_orientation_path(t_data *data, char *line, char *element)
{
	int i;

	i = 0;
	skip_str(line, i);
	if (!ft_strcmp(element, "NO"))
		data->file.no_path = ft_strndup(line, i);
	else if (!ft_strcmp(element, "SO"))
		data->file.so_path = ft_strndup(line, i);
	else if (!ft_strcmp(element, "WE"))
		data->file.we_path = ft_strndup(line, i);
	else if (!ft_strcmp(element, "EA"))
		data->file.ea_path = ft_strndup(line, i);
}

static void	set_color_values(t_data *data, char *line, char *element)
{
	
}

void	line_handler(t_data *data)
{
	int	inc;

	inc = 0;
	while (*(data->rd.line + inc) != '\0')
	{
		if (!data->file.no_path && !ft_strncmp((data->rd.line + inc), "NO "))
			set_orientation_path(data, (data->rd.line + inc + 4) , "NO");
		else if (!data->file.so_path && !ft_strncmp((data->rd.line + inc), "SO "))
			set_orientation_path(data, (data->rd.line + inc + 4) , "SO");
		else if (!data->file.we_path && !ft_strncmp((data->rd.line + inc), "WE "))
			set_orientation_path(data, (data->rd.line + inc + 4) , "WE");
		else if (!data->file.ea_path && !ft_strncmp((data->rd.line + inc), "EA "))
			set_orientation_path(data, (data->rd.line + inc + 4) , "EA");
		else if (!ft_strncmp((data->rd.line + inc), "C "))
			set_color_values(data, (data->rd.line + inc + 2), "C");
		else if (!ft_strncmp((data->rd.line + inc), "F "))
			set_color_values(data, (data->rd.line + inc + 2), "F");
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