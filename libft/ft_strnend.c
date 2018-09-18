#include "libft.h"

char		*ft_strnend(char *dst, const char *src, int n)
{
	char	*nstr;

	n++;
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(dst) + n));
	ft_bzero(nstr, ft_strlen(dst) + n);
	ft_strcpy(nstr, dst);
	ft_strlcat(nstr, src, n + ft_strlen(dst));
	return (nstr);
}