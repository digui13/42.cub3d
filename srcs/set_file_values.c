/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_orientations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:07:33 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/08 22:41:52 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

void	set_dir_path(t_data *data, char *line, int *inc, char **str)
{
	int	len;
	int	i;

	len = 0;
	i = *inc + 3;
	if (*str)
		gameover(data, EXIT_FAILURE, "Error: Duplicate elements");
	skip_spaces(line, &i);
	skip_str(line + i, &len);
	if (len == 0)
		gameover(data, EXIT_FAILURE, "Error: Element value not found");
	*str = my_strndup((line + i), len);
	(*inc) = i + len;
}
