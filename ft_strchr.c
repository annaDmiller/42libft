#include "libft.h"

char	*ft_strchr(char	*src, int c)
{
	int		index;
	char	car;

	car = (char) c; 
	if (car == '\0')
		return (src + ft_strlen(src));
	index = -1;
	while (src[++index])
	{
		if (src[index] == car)
			return (src + index);
	}
	return (NULL);
}
