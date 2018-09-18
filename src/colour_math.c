/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:27:03 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 17:57:34 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_colour			splitc(int n)
{
	t_colour o;

	o.b = n % 256;
	o.g = (n >> 8) % 256;
	o.r = n >> 16;
	return (o);
}

t_colour			mkcolour(double r, double g, double b)
{
	t_colour	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

int					mul_col(int c, double n)
{
	t_colour		slt;

	slt = splitc(c);
	slt.r *= n;
	slt.r = ft_clampf(0, 255, slt.r);
	slt.g *= n;
	slt.g = ft_clampf(0, 255, slt.g);
	slt.b *= n;
	slt.b = ft_clampf(0, 255, slt.b);
	return (combine_rgb(slt));
}

int					add_col(int c, double n)
{
	t_colour		slt;

	slt = splitc(c);
	slt.r += n;
	slt.r = ft_clampf(0, 255, slt.r);
	slt.g += n;
	slt.g = ft_clampf(0, 255, slt.g);
	slt.b += n;
	slt.b = ft_clampf(0, 255, slt.b);
	return (combine_rgb(slt));
}

int					min_cols(int c1, int c2)
{
	t_colour		slt;
	t_colour		slt2;

	slt = splitc(c1);
	slt2 = splitc(c2);
	slt.r -= slt2.r;
	slt.r = ft_clampf(0, 255, slt.r);
	slt.g -= slt2.g;
	slt.g = ft_clampf(0, 255, slt.g);
	slt.b -= slt2.b;
	slt.b = ft_clampf(0, 255, slt.b);
	return (combine_rgb(slt));
}
