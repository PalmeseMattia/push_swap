#include "push_swap.h"

int	ft_strisnum(char *str)
{
	while(*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (1);
}
