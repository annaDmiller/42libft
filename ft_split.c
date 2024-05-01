#include "libft.h"

static int	ft_count_str(const char *str, char car);

static int	ft_strlen_char(const char *src, char car);

static void	ft_free_arr(char **arr);

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		num_str;
	int		index;
	int		len_word;

	num_str = ft_count_str(s, c);
	ret = (char **) malloc(sizeof(char *) * (num_str + 1));
	if (ret == NULL)
		return (NULL);
	index = -1;
	while (++index < num_str)
	{
		while (*s == c)
			s++;
		len_word = ft_strlen_char(s, c);
		ret[index] = (char *) malloc(sizeof(char) * (len_word + 1));
		if (ret[index] == NULL)
			return (ft_free_arr(ret), NULL);
		ft_strlcpy(ret[index], s, len_word + 1);
		s += len_word + 1;
	}
	ret[index] = NULL;
	return (ret);
}

static int	ft_count_str(const char *str, char car)
{
	int	index;
	int	num_words;

	index = -1;
	num_words = 0;
	if (car != 0)
	{
		while (str[++index])
		{
			if (str[index] != car && str[index + 1] == car)
				num_words++;
			if (str[index] != car && str[index + 1] == '\0')
				num_words++;
		}
	}
	else if (ft_strlen(str) > 0)
		return (1);
	return (num_words);
}

static int	ft_strlen_char(const char *src, char car)
{
	int	index;

	index = -1;
	while (src[++index] != car && src[index]) ;
	return (index);
}

static void	ft_free_arr(char **arr)
{
	int	index;

	index = -1;
	while (arr[++index])
		free(arr[index]);
	free(arr);
}
