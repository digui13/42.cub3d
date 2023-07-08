/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:57:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 21:40:49 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	clean_file_elements(t_data *data)
{
	free_str_safe(&data->file.no_path);
	free_str_safe(&data->file.so_path);
	free_str_safe(&data->file.we_path);
	free_str_safe(&data->file.ea_path);
	free_int_safe(&data->file.ceiling);
	free_int_safe(&data->file.floor);
}

void	clean_file_map(t_data *data)
{
	free_bidim_str_safe(&data->map.matrix);
}