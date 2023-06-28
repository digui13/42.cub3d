/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:55:35 by dpestana          #+#    #+#             */
/*   Updated: 2023/06/28 16:06:00 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H



#endif

/*

	--------------
	| MY SO_LONG |
	--------------

		// Inicialization

			t_counter	inic_counter(void);
			t_map		render_map(void);
			t_window	render_window(t_game g);
			t_textures	render_textures(t_game g);

		// Utils

			void		read_map_file(char *map_path, t_game *g);
			void		printing_textures(t_game *g);
			void		move(t_game *g, int inc_x, int inc_y);
			void		enemy_animation(t_game *g);
			void		enemy_moving(t_game *g, int x, int y);

		// Ending game

			void		game_over(t_game *g, int clear_window, int clear_map, int error);

		// Libft

			size_t		ft_strlen(const char *s);
			char		*ft_strjoin(char const *s1, char const *s2);
			char		*ft_itoa(int n);

		// Events

			int			click_to_close(t_game *g);
			int			enemy_events(t_game *g);
			int			key_hook(int key_press, t_game *g);

		// Errors

			void		error_args(void);

		// Errors reading

			void		error_open_file(int *fd, t_game *g);
			void		error_first_line(int *fd, t_game *g);
			void		error_alloc_mem(int *fd, t_game *g);
			void		error_not_rectangle(t_game *g);
			void		error_square_map(t_game *g);

		// Errors printing
		
			void		error_invalid_map_char(t_game *g);
			void		error_too_many_entities(t_game *g);
			void		error_horiz_wall(t_game *g);
			void		error_verti_wall(t_game *g);

*/