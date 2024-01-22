#include "so_long.h"

void	paintcanva(t_vars *varg, t_img *img, int sx, int sy)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			my_mlx_pixel_put(&varg->canva, sx + x, sy + y, my_mlx_pixel_get(img,
						x, y));
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (color == -16777216)
	{
		return ;
	}
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	loadallimg(t_vars *vars)
{
	vars->person[0] = load_img("img/char/Idle64.xpm", vars);
	vars->person[1] = load_img("img/char/Grass64.xpm", vars);
	vars->person[2] = load_img("img/char/Pavement.xpm", vars);
	vars->person[3] = load_img("img/char/ChickenLit.xpm", vars);
	vars->person[4] = load_img("img/char/Lion.xpm", vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars->person[0].prev_sx = vars->person[0].curr_sx;
	vars->person[0].prev_sy = vars->person[0].curr_sy;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	else if (keycode == XK_w && vars->person[0].curr_sy > 0)
	{
		vars->move_y -= 64;
		printf("curr_sy: %d\n", vars->person[0].curr_sy);
		printf("curr_sx: %d\n", vars->person[0].curr_sx);
	}
	else if (keycode == XK_s && vars->person[0].curr_sy < 576)
	{
		vars->move_y += 64;
		printf("curr_sy: %d\n", vars->person[0].curr_sy);
		printf("curr_sx: %d\n", vars->person[0].curr_sx);
	}
	else if (keycode == XK_a && vars->person[0].curr_sx > 0)
	{
		vars->move_x -= 64;
		printf("curr_sx: %d\n", vars->person[0].curr_sx);
		printf("curr_sy: %d\n", vars->person[0].curr_sy);
	}
	else if (keycode == XK_d && vars->person[0].curr_sx < 576)
	{
		vars->move_x += 64;
		printf("curr_sx: %d\n", vars->person[0].curr_sx);
		printf("curr_sy: %d\n", vars->person[0].curr_sy);
	}
	//printf("keycode: %d\n", keycode);
	return (0);
}

t_img	load_img(char *path, t_vars *varg)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(varg->mlx, path, &img.img_width,
			&img.img_height);
	if (!img.img)
	{
		printf("Error\n");
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	paint_canvaw(t_vars *varg, t_img *img)
{
	int	frame_width;
	int	frame_x_offset;
	int	y;
	int	x;
	int	color;

	frame_width = img->img_width / img->total_frames;
	frame_x_offset = img->curr_sprite * frame_width;
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < frame_width)
		{
			color = my_mlx_pixel_get(img, frame_x_offset + x, y);
			my_mlx_pixel_put(&varg->canva, img->curr_sx + x, img->curr_sy + y,
					color);
			++x;
		}
		++y;
	}
}

void	update_sprite(t_img *img)
{
	img->curr_sprite = (img->curr_sprite + 1) % img->total_frames;
}

int	animation_loop(t_vars *varg)
{
	const int frame_delay = 100000;

	if (varg->move_x != 0 || varg->move_y != 0)
	{
		varg->person[0].prev_sx = varg->person[0].curr_sx;
		varg->person[0].prev_sy = varg->person[0].curr_sy;
		varg->person[0].curr_sx += varg->move_x;
		varg->person[0].curr_sy += varg->move_y;
		varg->move_x = 0;
		varg->move_y = 0;
		paintcanva(varg, &varg->person[2], varg->person[0].prev_sx,
				varg->person[0].prev_sy);
		paintcanva(varg, &varg->person[2], varg->person[0].curr_sx,
				varg->person[0].curr_sy);
	}

	// Redraw the background at the sprite's current and previous positions
	paintcanva(varg, &varg->person[2], varg->person[0].prev_sx,
			varg->person[0].prev_sy);
	paintcanva(varg, &varg->person[2], varg->person[3].curr_sx,
			varg->person[3].curr_sy);
	paintcanva(varg, &varg->person[2], varg->person[4].curr_sx,
			varg->person[4].curr_sy);
	if (varg->person[0].prev_sx != varg->person[0].curr_sx
		|| varg->person[0].prev_sy != varg->person[0].curr_sy)
	{
		paintcanva(varg, &varg->person[2], varg->person[0].curr_sx,
				varg->person[0].curr_sy);
	}
	paint_canvaw(varg, &varg->person[0]);
	paint_canvaw(varg, &varg->person[3]);
	paint_canvaw(varg, &varg->person[4]);
	update_sprite(&varg->person[0]);
	update_sprite(&varg->person[3]);
	update_sprite(&varg->person[4]);
	mlx_put_image_to_window(varg->mlx, varg->win, varg->canva.img, 0, 0);
	usleep(frame_delay);
	return (0);
}

int	main(void)
{
	t_vars	varg;
	int		num_blocks_x;
	int		num_blocks_y;
	int		y;
	int		x;

	varg.mlx = mlx_init();
	varg.win = mlx_new_window(varg.mlx, 640, 640, "so_long");
	varg.person = malloc(sizeof(t_img) * 5);
	varg.move_x = 0;
	varg.move_y = 0;
	varg.canva.img = mlx_new_image(varg.mlx, 640, 640);
	varg.canva.addr = mlx_get_data_addr(varg.canva.img,
										&varg.canva.bits_per_pixel,
										&varg.canva.line_length,
										&varg.canva.endian);
	loadallimg(&varg);
	varg.person[0].total_frames = 9;
	varg.person[3].total_frames = 4;
	varg.person[4].total_frames = 4;
	//===============================
	varg.person[0].curr_sx = 0;
	varg.person[3].curr_sx = 384;
	varg.person[4].curr_sx = 0;
	//===============================
	varg.person[0].curr_sy = 0;
	varg.person[3].curr_sy = 384;
	varg.person[4].curr_sy = 192;
	//===============================
	varg.person[0].curr_sprite = 0;
	varg.person[3].curr_sprite = 0;
	varg.person[4].curr_sprite = 0;
	//===============================
	varg.person[0].tamsprite = 64;
	varg.person[3].tamsprite = 64;
	varg.person[4].tamsprite = 64;
	//===============================
	num_blocks_x = 640 / varg.person[0].tamsprite;
	num_blocks_y = 640 / varg.person[0].tamsprite;
	//==============================
	y = 0;
	while (y < num_blocks_y)
	{
		x = 0;
		while (x < num_blocks_x)
		{
			paintcanva(&varg, &varg.person[2], x * varg.person[0].tamsprite, y
					* varg.person[0].tamsprite);
			++x;
		}
		y++;
	}
	//paintcanva(&varg, &varg.person[0], 0, 0);
	paint_canvaw(&varg, &varg.person[3]);
	paint_canvaw(&varg, &varg.person[0]);
	mlx_put_image_to_window(varg.mlx, varg.win, varg.canva.img, 0, 0);
	mlx_key_hook(varg.win, key_hook, &varg);
	mlx_loop_hook(varg.mlx, &animation_loop, &varg);
	mlx_loop(varg.mlx);
}

/* 
    paintcanva(&varg, &varg.person[2], 0, 0);
    paintcanva(&varg, &varg.person[2], 64, 0);
    paintcanva(&varg, &varg.person[2], 128, 0);
    paintcanva(&varg, &varg.person[2], 192, 0);
    paintcanva(&varg, &varg.person[2], 0, 64);
    paintcanva(&varg, &varg.person[2], 0, 128);
    paintcanva(&varg, &varg.person[2], 0, 192); */
/* void paint_canvaw(t_vars *varg, t_img *img, float w, float h) {
    float x;
    float y;
    int k;
    int j;
    t_vars *p;

    k = 0;
    y = 0;
    w = (img->img_width) / w;
    h = (img->img_height) / h;
    p = varg;
    while (y < img->img_height) {
        j = 0;
        x = img->curr_sprite * w;
        while (x < img->img_width && (j + img->curr_sprite) < img->tamsprite) {
            my_mlx_pixel_put(&p->img, (img->curr_sx + j), (img->curr_sy + k),
		(my_mlx_pixel_get(img, (int)x, (int)y)));
            x += w;
            j++;
        }
        k++;
        y += h;
    }
} */