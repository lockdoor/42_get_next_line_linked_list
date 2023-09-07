#include "libft.h"

char	*ft_strcat(const char *s1, const char *s2)
{
	int		len;
	char	*tmp;
	char	*tab;

	len = strlen (s1);
	len += strlen (s2);
	tab = (char *) malloc (sizeof (char) * (len + 1));
	tmp = tab;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (tab);
}
