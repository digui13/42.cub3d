/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:55:35 by dpestana          #+#    #+#             */
/*   Updated: 2023/07/17 17:50:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/*
#############################
#			CHECK			#
#############################
*/

void			check_args(t_data *data, int ac);
void			check_map(t_data *data);

/*
#############################
#			CHECK_FILE		#
#############################
*/

void			check_filename(t_data *data, char *filename);
int				has_file_orientations(t_data *data);
int				has_file_colors(t_data *data);
int				has_file_map(t_data *data);

/*
#############################
#			CLEAN			#
#############################
*/

void			clean_file_elements(t_data *data);
void			clean_file_map(t_data *data);

/*
#############################
#			END				#
#############################
*/

//static void		clean(t_data *data);
//static void		error(char *msg);
void			gameover(t_data *data, int status, char *msg);

/*
#############################
#			FREESAFE		#
#############################
*/

void			free_str_safe(char **str);
void			free_bidim_str_safe(char ***str);
void			free_int_safe(int **num);

/*
#############################
#			INITIALIZE		#
#############################
*/

void			initialize(t_data *data);

/*
#############################
#			MY_FUNCS		#
#############################
*/

int				my_isspace(int c);
char			*my_strdup(const char *s);
char			*my_strndup(const char *s, int qty);
int				my_strcmp(char *s1, char *s2);
int				my_strncmp(const char *s1, const char *s2, size_t n);

/*
#############################
#			READING			#
#############################
*/

//static void			line_elements(t_data *data);
void			line_map(t_data *data);
void			reading(t_data *data, char *filename);

/*
#############################
#		SET_DIRECTIONS		#
#############################
*/

void			set_dir_val(t_data *data, int *inc, char **str);
void			set_color_val(t_data *data, int *inc, int **rgb);

/*
#############################
#			SET_MAP			#
#############################
*/

int				is_valid_symbol(char ch);
int				is_spawn(char ch);
void			check_map_inside(t_data *data, char **matrix, int x, int y);
void			load_game(t_data *data);
void			show_output(t_data *data);

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