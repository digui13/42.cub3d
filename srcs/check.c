/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:44:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 21:36:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	check_args(t_data *data, int ac)
{
	if (ac != 2)
		gameover(data, FAIL, "Error: Invalid args number");
}
