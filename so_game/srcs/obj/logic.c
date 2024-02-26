#include "../../headers/so_long.h"

void    collect_item(t_vars *vars, int x, int y)
{
    t_object *current = vars->objects;
    while (current != NULL)
    {
        if(current->x == x && current->y == y && !current->collected)
        {
            current->collected = 1;
            break;
        }
        current = current->next;
    }
    vars->game.collectibles_count -= 1;
}