#include "mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	int		i;

	i = 0;
	mlx_ptr = mlx_init();
	mlx_win_ptr = mlx_new_window(mlx_ptr, 1600, 1080, "lessgo");
	while (i < 500)
	{
		mlx_pixel_put(mlx_ptr, mlx_win_ptr, 300, 300 + i, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, mlx_win_ptr, 300 + i, 300, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, mlx_win_ptr, 800, 800 - i, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, mlx_win_ptr, 800 - i, 800, 0xFFFFFF);
		i++;
	}
	mlx_loop(mlx_ptr);

}
