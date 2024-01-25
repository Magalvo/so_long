#include "so_long.h"

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


	//==========================================================================
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
