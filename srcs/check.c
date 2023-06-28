/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:44:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/06/28 16:04:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/cub3d.h"

void	check_args(int ac)
{
	if (ac != 2)
		gameover(FAIL, "Error: Invalid Quantity args");
}