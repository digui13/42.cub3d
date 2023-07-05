/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:44:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/03 17:58:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	initialize(data);
	check_args(&data, ac , av);
	check_filename(&data, av[1]);
	reading(&data, av[1]);
	
	gameover(&data, SUCCESS, NULL);
	return (0);
}