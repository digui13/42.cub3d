/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:53:58 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/16 16:23:15 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
#############################
#			MYFILES			#
#############################
*/

typedef struct s_file
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		*floor;
	int		*ceiling;

}t_file;

/*
#############################
#			MAP				#
#############################
*/

typedef struct s_map
{
	char	**matrix;
	int		*max_x;
	int		lines;
	
}t_map;

/*
#############################
#			READING			#
#############################
*/

typedef struct s_reading
{
	int		fd;
	int		map_end;
	char	*line;

}t_reading;

/*
#############################
#			DATA			#
#############################
*/

typedef struct s_data
{
	t_map		map;
	t_file		file;
	t_reading	rd;

}t_data;

#endif

/*

	typedef struct s_window {
		void	*mlx;
		void	*mlx_win;

	}	t_window;

	typedef struct s_textures {
		char	*collect;
		char	*player;
		char	*floor;
		char	*enemy;
		char	*wall;
		char	*exit;
		char	*enemy_m1;
		char	*enemy_m2;
		char	*enemy_m3;
		int		animation;
		int		delay;

		int		width;
		int		height;

	}	t_textures;

	typedef struct s_player {
		int	x;
		int	y;

	}	t_player;

	typedef struct s_counter
	{
		int	player;
		int	exit;
		int	collect;
		int	enemy;
		int	wall;
		int	floor;
		int	moves;

	}	t_counter;

	typedef struct s_map
	{
		char	**matrix;
		int		max_x;
		int		max_y;

	}	t_map;

	typedef struct s_game
	{
		t_window	win;
		t_textures	textures;
		t_player	player;
		t_counter	count;
		t_map		map;

	}	t_game;

*/