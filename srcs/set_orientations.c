/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_orientations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:07:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 21:25:41 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	set_no_path(t_data *data, char *line, int *inc)
{
	int	len;
	int	i;

	len = 0;
	i = *inc + 3;
	if (data->file.no_path)
		gameover(data, EXIT_FAILURE, "Error: Duplicate elements");
	skip_spaces(line, &i);
	skip_str(line + i, &len);
	if (len == 0)
		gameover(data, EXIT_FAILURE, "Error: Element value not found");
	data->file.no_path = my_strndup((line + i), len);
	(*inc) = i + len;
}

void	set_so_path(t_data *data, char *line, int *inc)
{
	int	len;
	int	i;

	len = 0;
	i = *inc + 3;
	if (data->file.so_path)
		gameover(data, EXIT_FAILURE, "Error: Duplicate elements");
	skip_spaces(line, &i);
	skip_str(line + i, &len);
	if (len == 0)
		gameover(data, EXIT_FAILURE, "Error: Element value not found");
	data->file.so_path = my_strndup((line + i), len);
	(*inc) = i + len;
}

void	set_we_path(t_data *data, char *line, int *inc)
{
	int	len;
	int	i;

	len = 0;
	i = *inc + 3;
	if (data->file.we_path)
		gameover(data, EXIT_FAILURE, "Error: Duplicate elements");
	skip_spaces(line, &i);
	skip_str(line + i, &len);
	if (len == 0)
		gameover(data, EXIT_FAILURE, "Error: Element value not found");
	data->file.we_path = my_strndup((line + i), len);
	(*inc) = i + len;
}

void	set_ea_path(t_data *data, char *line, int *inc)
{
	int	len;
	int	i;

	len = 0;
	i = *inc + 3;
	if (data->file.ea_path)
		gameover(data, EXIT_FAILURE, "Error: Duplicate elements");
	skip_spaces(line, &i);
	skip_str(line + i, &len);
	if (len == 0)
		gameover(data, EXIT_FAILURE, "Error: Element value not found");
	data->file.ea_path = my_strndup((line + i), len);
	(*inc) = i + len;
}
