/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:44:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 18:44:08 by dpestana         ###   ########.fr       */
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
	check_map(&data);
	show_output(&data);
	gameover(&data, SUCCESS, NULL);
	return (0);
}
