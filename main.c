/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:44:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 13:13:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/cubed.h"

int	main(int ac, char **av)
{
	t_data	data;

	initialize(&data);
	check_args(&data, ac);
	check_filename(&data, av[1]);
	reading(&data, av[1]);
	printf("NO %s\n", data.file.no_path);
	printf("SO %s\n", data.file.so_path);
	printf("WE %s\n", data.file.we_path);
	printf("EA %s\n", data.file.ea_path);
	int i;
	i = 0;
	while (i < 3)
	{
		printf("ceiling -> %d\n", *(data.file.ceiling + i));
		printf("floor -> %d\n", *(data.file.floor + i));
		i++;
	}
	i = 0;
	while (i < data.map.lines)
	{
		printf("%s", *(data.map.matrix + i));
		i++;
	}
	gameover(&data, SUCCESS, NULL);
	return (0);
}
