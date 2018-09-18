/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:30:11 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/29 14:34:36 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi_base(char *str, int base)
{
	int		ret = 0;
	int 	i ;

	i = 0;
	while (str[i])
	{
		ret *= base;
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret += str[i] - '0';
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			ret += str[i] - 'A' + 10;
		}
		i++;
	}
	return (ret);
}
