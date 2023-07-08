/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesafe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:24 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 22:43:24 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	free_str_safe(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_bidim_str_safe(char ***str)
{
	int	inc;

	inc = 0;
	if (*str != NULL)
	{
		while (*(*str + inc) != NULL)
		{
			free(*(*str + inc));
			*(*str + inc) = NULL;
			inc++;
		}
		free(*str);
		*str = NULL;
	}
}

void	free_int_safe(int **num)
{
	if (*num != NULL)
	{
		free(*num);
		*num = NULL;
	}
}
