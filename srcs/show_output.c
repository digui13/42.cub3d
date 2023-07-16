/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:50:46 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 16:30:11 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	show_output(t_data *data)
{
	printf("NO %s\n", data->file.no_path);
	printf("SO %s\n", data->file.so_path);
	printf("WE %s\n", data->file.we_path);
	printf("EA %s\n", data->file.ea_path);
	int i;
	i = 0;
	while (i < 3)
	{
		printf("ceiling %d\n", *(data->file.ceiling + i));
		printf("floor %d\n", *(data->file.floor + i));
		i++;
	}
	i = 0;
	while (i < data->map.lines)
	{
		printf("%s\n", *(data->map.matrix + i));
		i++;
	}
}