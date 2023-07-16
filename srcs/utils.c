/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:34:51 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 19:43:24 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

int	is_valid_symbol(char ch)
{
	if (ch == '1'
		|| ch == '0'
		|| ch == 'N'
		|| ch == 'S'
		|| ch == 'E'
		|| ch == 'W')
		return (YES);
	return (NO);
}

int	is_spawn(char ch)
{
	if (ch == 'N'
		|| ch == 'S'
		|| ch == 'E'
		|| ch == 'W')
		return (YES);
	return (NO);
}
