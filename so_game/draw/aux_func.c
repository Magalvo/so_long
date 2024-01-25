#include <stdlib.h>
#include <string.h>
#include "../so_long.h"


void    *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void    *new_ptr;

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    if (!ptr)
        return (malloc(new_size));
    if (new_size <= old_size)
        return (ptr);
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);
    ft_memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return (new_ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*altdest;
	unsigned char	*altsrc;

	altdest = (unsigned char *)dest;
	altsrc = (unsigned char *)src;
	if (!altdest && !altsrc)
		return (NULL);
	while (n-- > 0)
	{
		*altdest = *altsrc;
		altdest++;
		altsrc++;
	}
	return (dest);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}