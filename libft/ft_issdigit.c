/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 10:38:48 by gsferopo          #+#    #+#             */
/*   Updated: 2017/07/10 10:38:56 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_issdigit(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		if (!('0' <= s[i] && s[i] <= '9'))
			return (0);
	return (1);
}
