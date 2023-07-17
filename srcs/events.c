/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:27:00 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/17 19:34:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubed.h"

static int	click_to_close(t_data *data)
{
	gameover(data, EXIT_SUCCESS, NULL);
	return (0);
}

void	events(t_data *data)
{
	//mlx_hook(data->win.mlx_win, KEY_PRESS, KEY_PRESS_MASK << 0, key_hook, &g);
	mlx_hook(data->win.mlx_win, X_BUTTON, KEY_PRESS_MASK << 0, click_to_close, data);
}

/*
int	key_hook(int key_press, t_data *data)
{
	if (key_press == KEY_ESC)
		game_over(g, 1, 1, 0);
	else if (key_press == A)
		move(g, 0, -1);
	else if (key_press == S)
		move(g, 1, 0);
	else if (key_press == D)
		move(g, 0, 1);
	else if (key_press == W)
		move(g, -1, 0);
	return (key_press);
}
*/