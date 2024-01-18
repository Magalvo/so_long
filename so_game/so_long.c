#include "so_long.h"

void paintcanva(t_vars *varg, t_img *img, int sx, int sy) {
    int x;
    int y;

    y = 0;
    while (y < img->img_height) {
        x = 0;
        while (x < img->img_width) {
            my_mlx_pixel_put(&varg->canva, sx + x, sy + y, my_mlx_pixel_get(img, x, y));
            x++;
        }
        y++;
    }
}



void my_mlx_pixel_put(t_img *data, int x, int y, int color) {
    char *dst;

    if (color == -16777216) {
        return;
    }
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}



int my_mlx_pixel_get(t_img *data, int x, int y) {
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    return (*(unsigned int *)dst);
}




void loadallimg(t_vars *vars) {
    vars->person[0] = load_img("img/char/Idle64.xpm", vars);
    vars->person[1] = load_img("img/char/Grass64.xpm", vars);
}

int key_hook(int keycode, t_vars *vars) {
    vars->person[0].prev_sx = vars->person[0].curr_sx;
    vars->person[0].prev_sy = vars->person[0].curr_sy;
    if (keycode == XK_Escape) {
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
        exit(0);
    }
    if (keycode == XK_w) {
        vars->person[0].curr_sy -= 64;
    }
    if (keycode == XK_s) {
        vars->person[0].curr_sy += 64;
    }
    if (keycode == XK_a) {
        vars->person[0].curr_sx -= 64;
    }
    if (keycode == XK_d) {
        vars->person[0].curr_sx += 64;
    }
    printf("keycode: %d\n", keycode);
    return (0);
}


t_img load_img(char *path, t_vars *varg) {
    t_img img;
    img.img = mlx_xpm_file_to_image(varg->mlx, path, &img.img_width, &img.img_height);
    if (img.img == NULL) {
        printf("Error\n");
        exit(1);
    }
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    return (img);
}

void    paint_canvaw(t_vars *varg, t_img *img)
{

    int frame_width = img -> img_width / img -> total_frames;
    int frame_x_offset = img -> curr_sprite * frame_width;
    
    int y = 0;
    while (y < img->img_height)
    {
        int x = 0;
        while (x < frame_width)
        {
            int color = my_mlx_pixel_get(img, frame_x_offset + x, y);
            my_mlx_pixel_put(&varg->canva, img->curr_sx + x, img->curr_sy + y, color);
            ++x;
        }
        ++y;
    }
}

void    update_sprite(t_img *img)
{
    img -> curr_sprite = (img -> curr_sprite + 1) % img -> total_frames;
}


int animation_loop(t_vars *varg)
{
    const int frame_delay = 100000;

    // Redraw the background at the sprite's current and previous positions
    paintcanva(varg, &varg->person[1], varg->person[0].prev_sx, varg->person[0].prev_sy);
    if (varg->person[0].prev_sx != varg->person[0].curr_sx || varg->person[0].prev_sy != varg->person[0].curr_sy) {
        paintcanva(varg, &varg->person[1], varg->person[0].curr_sx, varg->person[0].curr_sy);
    }

    // Draw the sprite at the new position
    paint_canvaw(varg, &varg->person[0]);
    update_sprite(&varg->person[0]);

    mlx_put_image_to_window(varg->mlx, varg->win, varg->canva.img, 0, 0);
   
    usleep(frame_delay);
   
    return (0);
}

int main()
{
    t_vars varg;

    varg.mlx = mlx_init();
    varg.win = mlx_new_window(varg.mlx, 640, 640, "so_long");
    varg.person = malloc(sizeof(t_img) * 2);
    varg.canva.img = mlx_new_image(varg.mlx, 640, 640);
    varg.canva.addr = mlx_get_data_addr(varg.canva.img, &varg.canva.bits_per_pixel, &varg.canva.line_length, &varg.canva.endian); 
    loadallimg(&varg);
    varg.person[0].total_frames = 9; 
    varg.person[0].curr_sx = 0;
    varg.person[0].curr_sy = 0;
    varg.person[0].curr_sprite = 0;
    varg.person[0].tamsprite = 64;
    int num_blocks_x = 640 / varg.person[0].tamsprite;
    int num_blocks_y = 640 / varg.person[0].tamsprite;

    int y = 0;
    while (y < num_blocks_y)
    {
        int x = 0;
        while (x < num_blocks_x)
        {
            paintcanva(&varg, &varg.person[1], x * varg.person[0].tamsprite, y * varg.person[0].tamsprite);
            ++x;
        }
        y++;
    }
    //paintcanva(&varg, &varg.person[0], 0, 0); 
    paint_canvaw(&varg, &varg.person[0]);
    mlx_put_image_to_window(varg.mlx, varg.win, varg.canva.img, 0, 0);
    mlx_key_hook(varg.win, key_hook, &varg);
    mlx_loop_hook(varg.mlx, &animation_loop, &varg);
    mlx_loop(varg.mlx);
}
















/* 
    paintcanva(&varg, &varg.person[1], 0, 0);
    paintcanva(&varg, &varg.person[1], 64, 0);
    paintcanva(&varg, &varg.person[1], 128, 0);
    paintcanva(&varg, &varg.person[1], 192, 0);
    paintcanva(&varg, &varg.person[1], 0, 64);
    paintcanva(&varg, &varg.person[1], 0, 128);
    paintcanva(&varg, &varg.person[1], 0, 192); */
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
            my_mlx_pixel_put(&p->img, (img->curr_sx + j), (img->curr_sy + k), (my_mlx_pixel_get(img, (int)x, (int)y)));
            x += w;
            j++;
        }
        k++;
        y += h;
    }
} */