/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:44:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 22:01:26 by dpestana         ###   ########.fr       */
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
	printf("%s\n", data.file.no_path);
	printf("%s\n", data.file.so_path);
	printf("%s\n", data.file.we_path);
	printf("%s\n", data.file.ea_path);
	gameover(&data, SUCCESS, NULL);
	return (0);
}