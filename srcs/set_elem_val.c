/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:07:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/13 18:20:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

static int	get_elem_val_len(t_data *data, int **inc)
{
	int	len;

	len = 0;
	if (!my_isspace(*(data->rd.line + **inc)))
		gameover(data, EXIT_FAILURE,
			"Error: Element arent separated by space");
	while (*(data->rd.line + **inc + len) != '\0'
		&& my_isspace(*(data->rd.line + **inc)))
		(**inc)++;
	while (*(data->rd.line + **inc + len) != '\0'
		&& !my_isspace(*(data->rd.line + **inc + len)))
		len++;
	if (len == 0)
		gameover(data, EXIT_FAILURE,
			"Error: Element value not found");
	return (len);
}

static int	get_num(t_data *data, char *line, int *inc)
{
	int	num;

	num = 0;
	while (*(line + *inc) != ',' && *(line + *inc) != '\0'
		&& !(my_isspace(*(line + *inc))))
	{
		if ('0' <= *(line + *inc) && *(line + *inc) <= '9')
		{
			num *= 10;
			num += (*(line + *inc) - 48);
		}
		else if (!('0' <= *(line + *inc) && *(line + *inc) <= '9')
			&& *(line + *inc) != ',')
			gameover(data, EXIT_FAILURE,
				"Error: Element color value not valid");
		(*inc)++;
	}
	return (num);
}

static int	*convert_str_to_rgb(t_data *data, char *line, int len)
{
	int	inc;
	int	rgb_idx;
	int	*rgb;

	inc = 0;
	rgb_idx = 0;
	rgb = malloc(sizeof(int) * 3);
	while (inc < len)
	{
		if (rgb_idx == 3)
			gameover(data, EXIT_FAILURE,
				"Error: Element color quantity not valid");
		*(rgb + rgb_idx) = get_num(data, line, &inc);
		if (*(rgb + rgb_idx) < 0 || *(rgb + rgb_idx) > 255)
			gameover(data, EXIT_FAILURE,
			"Error: Element color value not RGB");
		rgb_idx++;
		inc++;
	}
	return (rgb);
}

void	set_dir_val(t_data *data, int *inc, char **str)
{
	int	len;

	if (*str)
		gameover(data, EXIT_FAILURE,
			"Error: Duplicate elements");
	(*inc) += 2;
	len = get_elem_val_len(data, &inc);
	*str = my_strndup((data->rd.line + *inc), len);
	(*inc) += len;
}

void	set_color_val(t_data *data, int *inc, int **rgb)
{
	int	len;

	if (*rgb)
		gameover(data, EXIT_FAILURE,
			"Error: Duplicate elements");
	(*inc)++;
	len = get_elem_val_len(data, &inc);
	if (len > 11)
		gameover(data, EXIT_FAILURE,
			"Error: Element color quantity not supported");
	*rgb = convert_str_to_rgb(data, (data->rd.line + *inc), len);
	(*inc) += len;
}
