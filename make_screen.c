/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:41:18 by stune             #+#    #+#             */
/*   Updated: 2021/04/02 15:44:27 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	bmp_header(t_bmp_header *bmp_h, t_data *vars)
{
	bmp_h->bf_type[0] = 0x42;
	bmp_h->bf_type[1] = 0x4D;
	bmp_h->bf_size = (vars->elem.r_x * vars->elem.r_y * 4) + 54;
	bmp_h->bf_reserved1 = 0x00000000;
	bmp_h->bf_off_bits = 54;
	bmp_h->header_bi = 40;
	bmp_h->width = vars->elem.r_x;
	bmp_h->height = -vars->elem.r_y;
	bmp_h->planes = 1;
	bmp_h->bpp = 24;
	bmp_h->compresion = 0;
	bmp_h->bi_size_image = vars->elem.r_x * vars->elem.r_y * 4;
	bmp_h->bi_x_pels_per_meter = 2835;
	bmp_h->bi_y_pels_per_meter = 2835;
	bmp_h->bi_clr_used = 0;
	bmp_h->bi_clr_inportant = 0;
}

static void	put_header(int fd, t_bmp_header bmp_h)
{
	write(fd, &bmp_h.bf_type, 2);
	write(fd, &bmp_h.bf_size, 4);
	write(fd, &bmp_h.bf_reserved1, 4);
	write(fd, &bmp_h.bf_off_bits, 4);
	write(fd, &bmp_h.header_bi, 4);
	write(fd, &bmp_h.width, 4);
	write(fd, &bmp_h.height, 4);
	write(fd, &bmp_h.planes, 2);
	write(fd, &bmp_h.bpp, 2);
	write(fd, &bmp_h.compresion, 4);
	write(fd, &bmp_h.bi_size_image, 4);
	write(fd, &bmp_h.bi_x_pels_per_meter, 4);
	write(fd, &bmp_h.bi_y_pels_per_meter, 4);
	write(fd, &bmp_h.bi_clr_used, 4);
	write(fd, &bmp_h.bi_clr_inportant, 4);
}

static int	put_pix(int fd, t_data *vars, int padsize, int *adr)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	y = -1;
	ft_bzero(zero, 3);
	while (++y < vars->elem.r_y)
	{
		x = -1;
		while (++x < vars->elem.r_x)
		{
			pixel = *(adr + x + y * vars->line_length / 4);
			write(fd, &pixel, 3);
		}
		if (padsize > 0 && write(fd, &zero, padsize) < 0)
			return (0);
	}
	return (1);
}

void		make_screenshot(t_data *vars)
{
	t_bmp_header	bmp_h;
	int				padsize;
	int				fd;
	int				*adr;

	adr = (int *)mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
				&vars->line_length, &vars->endian);
	padsize = (4 - ((int)vars->elem.r_x * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT,
			0777 | O_TRUNC | O_APPEND)) < 0)
	{
		ft_putendl_fd("ERROR:\nNo screenshot was taken", 2);
		exit(0);
	}
	bmp_header(&bmp_h, vars);
	put_header(fd, bmp_h);
	if (!(put_pix(fd, vars, padsize, adr)))
	{
		ft_putendl_fd("ERROR:\nNo screenshot was taken", 2);
		exit(0);
	}
	close(fd);
	exit(0);
}
