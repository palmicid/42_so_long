#include <stdio.h>
#include "../libft/libft.h"

typedef struct dimen
{
	int		x;
	int 	y;
}			dimen;


typedef struct fuck
{
	int		x;
	char	**split;
	dimen	twoD;
}			fuck;

void	printsplit(char **strtwo)
{
	int	i = 0;
	int	j = 0;
	
	while(strtwo[i])
	{
		j = 0;
		while (strtwo[i][j])
		{
			printf("%c", strtwo[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	fuck	*test = NULL;

	test = (fuck *)malloc(sizeof(fuck));
	printf("BUG-11\n");
	test->x = 10;
	printf("BUG-00\n");
	test->split = ft_split(av[1], ' ');
	printf("BUG-01\n");
	printf("test00 = %c\n", test->split[0][4]);
	printsplit(test->split);
	test->twoD.x = 4;
	test->twoD.y = 9;
	printf("BUG-12\n");
	printf("x = %d\ny = %d\n", test->twoD.x, test->twoD.y);
	return (0);
}