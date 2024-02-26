#include "../../headers/so_long.h"

void    load_digit_images(t_vars *vars) 
{
    char *digit_paths[NUM_DIGITS] = {
        "img/numbers/0.xpm", "img/numbers/1.xpm", "img/numbers/2.xpm",
        "img/numbers/3.xpm", "img/numbers/4.xpm", "img/numbers/5.xpm",
        "img/numbers/6.xpm", "img/numbers/7.xpm", "img/numbers/8.xpm",
        "img/numbers/9.xpm"
    };

    
    vars->digit_imgs = malloc(NUM_DIGITS * sizeof(t_img));
    if (!vars->digit_imgs) 
    {
        exit_game(vars, "Failed to allocate memory for digit images");
    }
    for (int i = 0; i < NUM_DIGITS; i++) 
    {
        vars->digit_imgs[i] = load_img(digit_paths[i], vars);
    }
}

void    display_counter(t_vars *vars, int x, int y, int number) 
{
    char num_str[12]; 
    sprintf(num_str, "%d", number);

    int digit_x = x;
    for (int i = 0; num_str[i] != '\0'; i++) 
    {
        int digit = num_str[i] - '0'; 
        if (digit >= 0 && digit <= 9) 
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->digit_imgs[digit].img, digit_x, y);
            digit_x += vars->digit_imgs[digit].img_width; 
        }
    }
}