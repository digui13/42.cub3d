/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:02:02 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 13:28:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

static int	is_valid_symbol(char ch)
{
	if (ch == '1'
		|| ch == '0'
		|| ch == 'N'
		|| ch == 'S'
		|| ch == 'E'
		|| ch == 'W')
		return (YES);
	return (NO);
}

static void	alloc_map_line(t_data *data)
{
	char	**tmp;
	int		inc;

	inc = 0;
	if (data->map.matrix == NULL)
	{
		data->map.matrix = malloc(sizeof(char *) * 2);
		*data->map.matrix = my_strdup(data->rd.line);
		*(data->map.matrix + 1) = NULL;
		data->map.lines = 1;
	}
	else
	{
		tmp = malloc(sizeof(char *) * (data->map.lines + 2));
		while (inc < data->map.lines)
		{
			*(tmp + inc) = *(data->map.matrix + inc);
			inc++;
		}
		*(tmp + inc) = my_strdup(data->rd.line);
		*(tmp + inc + 1) = NULL;
		free(data->map.matrix);
		data->map.matrix = tmp;
		data->map.lines++;
	}
}

void	line_map(t_data *data)
{
	int	inc;

	inc = 0;
	while (*(data->rd.line + inc) != '\0')
	{
		if (is_valid_symbol(*(data->rd.line + inc)))
		{
			alloc_map_line(data);
			return ;
		}
		else if (!my_isspace(*(data->rd.line + inc)))
			gameover(data, EXIT_FAILURE,
				"Error: File has extra content inside map content");
		else if (!(*(data->rd.line + inc) == ' ') && !(*(data->rd.line + inc) == '\n'))
			gameover(data, EXIT_FAILURE,
				"Error: File has tabs inside map content");
		inc++;
	}
	if (data->map.matrix != NULL)
		data->rd.map_end = YES;
}
