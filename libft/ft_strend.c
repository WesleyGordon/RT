#include "libft.h"

char		*ft_strend(char *dst, char *src)
{
	char	*nstr;

	nstr = (char *)malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src)));
	ft_bzero(nstr, ft_strlen(dst) + ft_strlen(src));
	ft_strcpy(nstr, dst);
	ft_strcat(nstr, src);
	return (nstr);
}