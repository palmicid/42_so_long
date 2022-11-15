#include "../libft/libft.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (EXIT_FAILURE);
	else
	{
		int fdin = open(av[1], O_RDONLY);
		char	*fname;
		fname = ft_strjoin(av[1], "_fix");
		int fdout = open(fname, O_RDWR | O_CREAT | O_TRUNC, 0644);

		char buf[2];
		int	rd = 1;

		buf[1] = 0;
		while (rd)
		{
			rd = read(fdin, buf, 1);
			if (ft_isprint(buf[0]) || buf[0] == 10)
				ft_putchar_fd(buf[0], fdout);
		}
		close(fdin);
		close(fdout);
		free(fname);
	}
	return (0);
}
