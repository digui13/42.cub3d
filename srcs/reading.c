/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:42:11 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/13 16:58:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	line_elements(t_data *data)
{
	int	inc;

	inc = 0;
	while (*(data->rd.line + inc) != '\0')
	{
		if (!my_strncmp((data->rd.line + inc), "NO", 2))
			set_dir_val(data, &inc, &data->file.no_path);
		else if (!my_strncmp((data->rd.line + inc), "SO", 2))
			set_dir_val(data, &inc, &data->file.so_path);
		else if (!my_strncmp((data->rd.line + inc), "WE", 2))
			set_dir_val(data, &inc, &data->file.we_path);
		else if (!my_strncmp((data->rd.line + inc), "EA", 2))
			set_dir_val(data, &inc, &data->file.ea_path);
		else if (!my_strncmp((data->rd.line + inc), "C", 1))
			set_color_val(data, &inc, &data->file.floor);
		else if (!my_strncmp((data->rd.line + inc), "F", 1))
			set_color_val(data, &inc, &data->file.ceiling);
		else if (!my_isspace(*(data->rd.line + inc)))
			gameover(data, EXIT_FAILURE, "Error: File has extra content");
		inc++;
	}
}

void	reading(t_data *data, char *filename)
{
	data->rd.fd = open(filename, O_RDONLY);
	if (data->rd.fd == -1)
		gameover(data, FAIL, "Error: File doesnt open");
	data->rd.line = get_next_line(data->rd.fd);
	while (data->rd.line != NULL)
	{
		if (!has_file_orientations(data) || !has_file_colors(data))
			line_elements(data);
		//else
		//	line_map(data);
		free_str_safe(&data->rd.line);
		data->rd.line = get_next_line(data->rd.fd);
	}
	free_str_safe(&data->rd.line);
	close(data->rd.fd);
	data->rd.fd = -1;
	if (!has_file_orientations(data))
		gameover(data, EXIT_FAILURE, "Error: Miss file direction values");
	if (!has_file_colors(data))
		gameover(data, EXIT_FAILURE, "Error: Miss file color values");
	//if (!has_file_map(data))	
	//	gameover(data, EXIT_FAILURE, "Error: Miss file map values");
}
