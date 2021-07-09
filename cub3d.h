/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:26:44 by stune             #+#    #+#             */
/*   Updated: 2021/03/23 17:17:32 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx_mms_20200219/mlx.h"
# include <math.h>
# include "get_next_line.h"
# include "libft_m/libft.h"

typedef struct		s_bmp_header
{
	char			bf_type[2];
	unsigned int	bf_size;
	unsigned int	bf_reserved1;
	unsigned int	bf_off_bits;
	unsigned int	header_bi;
	int				width;
	int				height;
	unsigned short	planes;
	unsigned short	bpp;
	unsigned int	compresion;
	unsigned int	bi_size_image;
	int				bi_x_pels_per_meter;
	int				bi_y_pels_per_meter;
	unsigned int	bi_clr_used;
	unsigned int	bi_clr_inportant;
}					t_bmp_header;

typedef	struct		s_sprite
{
	double			sprite_x;
	double			sprite_y;
	double			dist_sp;
	int				size_sp;
	int				h_offset;
	int				v_offset;
	int				itter;
	double			ratio;
	int				x;
	int				y;
}					t_sprite;

typedef	struct		s_texture
{
	void			*image;
	char			*adr;
	int				text_heght;
	int				text_width;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
	double			ratio;
	int				x;
	int				y;
}					t_texture;

typedef	struct		s_ray
{
	double			hor_ray_x;
	double			ver_ray_y;
	int				intersection;
	double			distant;
}					t_ray;

typedef	struct		s_color
{
	unsigned int	fl_r;
	unsigned int	fl_g;
	unsigned int	fl_b;
	int				fl_valid;
	unsigned int	ce_r;
	unsigned int	ce_g;
	unsigned int	ce_b;
	int				ce_valid;
}					t_color;

typedef	struct		s_elem
{
	int				r_x;
	int				r_y;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	t_color			*all_color;
	char			**map;
	char			personage;
	int				max_map_x;
	int				max_map_y;
	int				sprite_num;
	int				screen;
}					t_elem;

typedef struct		s_wall
{
	int				i;
	int				j;
	int				x;
	int				y;
}					t_wall;

typedef struct		s_dir
{
	int				rayis_right;
	int				rayis_left;
	int				rayis_up;
	int				rayis_down;
}					t_dir;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_elem			elem;
	t_ray			ray;
	t_texture		*texture;
	t_sprite		*sprite;
	double			per_x;
	double			per_y;
	double			deg;
	char			**map;
	int				start_row;
	int				end_row;
	int				cent_line;
	int				norm_wall;
}					t_data;

char				**ft_map_pars(t_list **l_map, t_elem **elem);
t_elem				*ft_type_elem(t_list *l_map);
t_elem				*ft_lstnew_elem(void);
t_color				*ft_lstnew_color(void);
int					ft_if_one(t_list *tmp);

t_elem				*ft_resolution(t_list *tmp, t_elem *elem);
t_elem				*ft_sonowesea(t_list *tmp, t_elem *elem);
t_elem				*ft_cel_col(t_list *tmp, t_elem *elem);
t_elem				*ft_flo_col(t_list *tmp, t_elem *elem);

void				ft_check_valid(t_elem *elem);
char				*ft_check_elem(char *str, char *src, char stop);
int					ft_valid_map(t_elem *elem);
void				elem_if_not_true(t_list *tmp);
int					valid_end_map(t_list *l_map, t_elem **elem);

int					g_win_test(t_elem *elem);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					create_trgb(int t, int r, int g, int b);
int					all_all(t_data *vars);
void				minimapa(t_data *vars);
void				ft_wall(t_data *vars);
t_dir				ray_dir(double start);
int					ray_casting(t_data *vars, t_dir *dir, double start);
void				draw3dwall(t_data *vars, double h,
						int start_x, double start);
void				all_math(t_data *vars, int start_x);

void				open_texture(t_data *vars);
void				open_sprite(t_data *vars);

void				texture_mapping(t_data *vars, double h,
						double start, int start_x);
int					check_side(t_data *vars, double start);
int					create_ta(int t, int rgb);

void				draw_sprite(t_data *vars, int start_x);
void				get_coord_sprit(t_data *vars);

void				get_param_sprite(t_data *vars);
void				make_screenshot(t_data *vars);
void				initialization_var(t_data *vars, t_elem elem);
void				screen_limits(t_data *vars);
void				col_draw(t_data *vars, int i, int start_x);
void				param_sprite_norme(t_data *vars, int i, double delta);
void				arg_comang_shell(int argc, char **argv, t_elem *elem);
void				free_all_struct(t_elem *elem, t_list *l_map);
void				print_error(int	ident);
int					sprite_and_personage(char *s, t_elem *elem);
void				valid_valid(char **tmp, int x, int y);

void				move_forward(t_data *vars);
void				move_left(t_data *vars);
void				move_back(t_data *vars);
void				move_right(t_data *vars);

#endif
