#include "../libft.h"

char	*ft_word(char const *str, char c, int *i)
{
	char	*wrd;
	int 	k;

	k = *i;
	while (str[k] != c && str[k] != '\0')
		k++;
	if(!(wrd = malloc(sizeof(char) * (k + 1))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i] != '\0')
		wrd[k++] = str[(*i)++];
	wrd[k] = '\0';
	return (wrd);
}