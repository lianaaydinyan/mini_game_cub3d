/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:51:28 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/06 21:54:15 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>

//for error handling
# define T_ERROR 3
# define C_ERROR 4
# define M_ERROR 5
# define F_ERROR 6
# define E_ERROR 7
# define SCRWID 2040
# define SCRH 1000
# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_data	t_data;
typedef struct s_img	t_img;
typedef struct s_hero	t_hero;
typedef struct s_mlx	t_mlx;
typedef struct s_key	t_key;

struct s_key
{
	int	w;
	int	d;
	int	s;
	int	a;
	int	rr;
	int	rl;
};

struct	s_img
{
	int		heigth;
	int		width;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		start;
	int		end;
	int		endian;
};

struct	s_mlx
{
	void	*win;
	void	*ptr;
	t_img	image;
};

struct s_hero
{
	int		view;
	double	x;
	double	y;
};

struct s_data
{
	char	**textures;
	double	move_speed;
	double	rot_speed;
	int		f;
	int		c;
	double	tex_pos;
	int		step;
	int		map_x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		tex_y;
	int		tex_height;
	int		pitch;
	int		step_x;
	int		step_y;
	int		map_y;
	int		hit;
	int		celling_c;
	int		flooring_c;
	int		win_w;
	int		side;
	int		tex_x;
	int		draw_end;
	int		draw_start;
	int		win_h;
	int		line_length;
	int		line_height;
	int		**map;
	char	**map_c;
	double	widht;
	int		height;
	int		count;
	int		nb;
	int		to_map;
	int		tex_num;
	double	plane_x;
	double	plane_y;
	double	cam_y;
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	t_mlx	*mlx;
	t_img	texturess[4];
	t_img	*imgg;
	void	*mlx_ptr;
	void	*win_ptr;
	int		size;
	t_hero	*hero;
	t_key	keys;
	char	*filename;
	int		map_h;
	int		flag_c;
	int		flag_f;
};

int		do_walls(t_data *data);
int		key_cross(int keycode);
int		key_hook(void);
void	camera_frame_counting(t_data *data);
int		skipping(char **line, int fd, t_data *data);
int		i_am_color(char **line, t_data *data, int fd);
int		check_map(t_data *data);
int		tree_nb(char *line, t_data *data, int flag);
int		unpressed(int keycode, t_data *data);
void	camera_frame_counting(t_data *data);
int		pressed(int keycode, t_data *data);
void	keycodes_initializing(t_data *data);
void	depi_dzax(t_data *data);
void	ft_move_it_move_it(t_data *data);
void	init_win(t_data *data);
int		any_invalid(char **line, int i, int j);
int		check_neighbor(char **map_c, int i, int j);
int		tree_nb(char *line, t_data *data, int flag);
int		parcing(t_data *data, char **argv);
int		errorik(int flag);
char	*get_next_line(int fd);
int		empty_line(char *line);
void	skip_sp(char **line);
int		is_texture(char *line);
int		create_trgb(int t, int r, int g, int b);
int		ft_strlen_t(const char *str);
char	*ft_strdup_t(char *s1);
int		first_texture(char *line, int fd, t_data *data);
int		init_colors(char *line, t_data *data);
int		is_color(char *line);
int		first_texture(char *line, int fd, t_data *data);
int		set_texture(char *line, char **textures, int i);
int		fill_textures(char *line, char **textures);
int		init_textures(char **line, int fd, char **textures, int *to_map);
int		first_color(char *line, int fd, t_data *data);
int		parce_map(int fd, char *line, t_data *data);
int		can_be(char ch);
int		direction(char ch);
int		path_exist(char **textures);
void	to_int(t_data *data);
void	fill(char *line, int *z_map);
int		get_max_widht(char *file_name);
int		get_height(char **map);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			int *width, int *height);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	textures_drawing(t_data *data, int i);
void	texture_data_filling(t_data *data);
void	chose_gamer_path(t_data *data);
void	north_path_data_filling(t_data *data);
void	south_path_data_filling(t_data *data);
void	west_path_data_filling(t_data *data);
void	east_path_data_filling(t_data *data);
void	chose_gamer_path2(t_data *data);
void	hero_data_filling(t_data *data);
void	ft_filling(t_data *data);
int		choose_rigth_texture(t_data *data);
void	ft_texture_calculation(t_data *data);
void	draw_colors(t_data *data);
int		just_do_it(t_data *data);
void	counting_delta_dist(t_data *data, int i);
void	calculate_step_init_side_dist(t_data *data);
void	ft_dda_algorithm(t_data *data);
void	camera_frame_counting(t_data *data);
int		ft_raycasting(t_data *data);
int		ft_movement(int keycode, t_data *data);
void	keycodes_initializing(t_data *data);
void	ft_move_it_move_it(t_data *data);
float	ft_abs(float num);
void	qayl_aj(t_data *data);
void	qayl_araj(t_data *data);;
void	qayl_het(t_data *data);
void	depi_aj(t_data *data);
void	depi_dzax(t_data *data);
void	qayl_dzax(t_data *data);
int		pressed(int keycode, t_data *data);
int		unpressed(int keycode, t_data *data);

#endif
