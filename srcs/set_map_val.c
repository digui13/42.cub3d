/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:02:02 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/13 20:06:27 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	line_map(t_data *data)
{
	int	inc;

	inc = 0;
	while (*(data->rd.line + inc) != '\0')
	{
		if (*(data->rd.line + inc) == '1'
			|| *(data->rd.line + inc) == '0'
			|| *(data->rd.line + inc) == 'N'
			|| *(data->rd.line + inc) == 'S'
			|| *(data->rd.line + inc) == 'E'
			|| *(data->rd.line + inc) == 'W')
		{
			if (data->map.matrix == NULL)
			{
				
			}
			else
			{
				data->map.matrix = malloc(sizeof(char *) * (1 + data->map.max_y));
				while ()
				{
					
				}
				*(data->map.matrix + data->map.max_y) = ft_strdup(data->rd.line);
			}
		}
		inc++;
	}
}
