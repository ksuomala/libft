#include "libft.h"

/*
** Compares 2 numeral strings. If a > than b, return > 0. If strings
** are not numeric, return 0.
*/

int	ft_strnbrcmp(char *a, char *b)
{
	int	i;

	i = 0;
	if (!ft_isnumeric_str(a) || !ft_isnumeric_str(b) || !a || !b)
		return (0);
	while (a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}
