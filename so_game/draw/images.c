#include "../so_long.h"

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

void	loadallimg(t_vars *vars)
{
	vars->person[0] = load_img("../img/char/Idle64.xpm", vars);
	vars->person[1] = load_img("../img/char/Grass64.xpm", vars);
	vars->person[2] = load_img("../img/char/Pavement.xpm", vars);
	vars->person[3] = load_img("../img/char/ChickenLit.xpm", vars);
	vars->person[4] = load_img("../img/char/Lion.xpm", vars);
}