#include "mlx.h"
#include "utils/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// char		**ft_split(char const *s, char c);
// int         ft_atoi(char *s);

typedef struct{
    int x;
    int y;
    int radius;
    unsigned int colorPlayer;
}circle;

typedef struct{
    
}update;
typedef struct{
        int x;
        int y;
        int radius;
        int turnDirection; // -1 if left, +1 if right
        int walkDirection; // -1 if back, +1 if front
        int rotationAngle; // = Math.PI / 2;
        int moveSpeed; // = 3.0;
        int rotationSpeed; // = 3 * (Math.PI / 180);
}player;

void    put_square(int x, int y, void *mlx_ptr, void *win_ptr,unsigned int color)
{
    int y_last;
    int x_last;
    int c;
    int e;

    x_last = x + 32;
    y_last = y + 32;
    c = y;
    while(x < x_last)
    {
        y = c;
        while(y < y_last)
        {
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
            y++;
        }
        x++;
    }
}
char    **ft_cube3d(int fd)
{
    char    **line;
    int i;
    int j;
    int c;

    i = 0;
    j = 0;
    line = malloc(sizeof(char ** ) * 10);
    while(get_next_line(fd, &line[j]))
        j++;
    line[++j] = NULL;
    j = 0;
    return(line);
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int x;
    int y;
    char **lines;
    int fd;
    int a;
    int b;
    int height;
    int Weight;
    player p;
    circle c;

    // p.x = 640 / 2;
    // p.y = 640 / 2;
    // p.radius = 3;
    // p.turnDirection = 0;
    // p.walkDirection = 0;
    // p.rotationAngle = Math.Pi / 2;
    // p.moveSpeed = 3;
    // p.rotationSpeed = 3 * (Math.P / 2);
    // c.x = p.x;
    // c.y = p.y;
    // c.radius = p.radius;
    // c.colorPlayer = 0xbbff22;
    fd = open("map.txt", O_RDWR);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 640, 640, "mlx 42");
    x = 0;
    lines = ft_cube3d(fd);
    a = 0;
    b = 0;
    
    while(lines[a])
        a++;
    height = 32 * a;
    while(lines[0][b])
        b++;
    Weight = 32 * b;
    a = 0;
    while(y < height)
    {
        x = 0;
        b = 0;
        while(x < Weight)
        {
            //printf("|%c|", lines[a][b]);
            if(lines[a][b] == '0')
                put_square(x, y, mlx_ptr, win_ptr, 0xff0500);
            else
                put_square(x, y, mlx_ptr, win_ptr, 0x0000ff);
            //if(player.x && player.y)

            x+=32;
            b++;
        }
        printf("\n");
        y+=32;
        a++;
    }
    mlx_loop(mlx_ptr);
}