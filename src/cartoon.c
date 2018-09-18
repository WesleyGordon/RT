/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartoon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 06:47:23 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 17:08:45 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

double			cto32(int c, int base)
{
	t_colour	n;

	n = splitc(c);
	n.r -= ((int)n.r % base);
	n.g -= ((int)n.g % base);
	n.b -= ((int)n.b % base);
	return (combine_rgb(n));
}

int				cartoonify(int n, int base)
{
	return (cto32(n, base));
}
