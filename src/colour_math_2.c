/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_math_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:46:47 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 07:33:44 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_colour		makec255(double r, double g, double b)
{
	t_colour	c;

	c.r = r / 255.0;
	c.g = g / 255.0;
	c.b = b / 255.0;
	return (c);
}

int				combine_rgb(t_colour c)
{
	return ((int)(c.r) * 256 * 256 + (int)(c.g) * 256 + (int)(c.b));
}

int				combine_rgbm(t_colour c)
{
	c.r = ft_clampf(0, 255, c.r * 255);
	c.g = ft_clampf(0, 255, c.g * 255);
	c.b = ft_clampf(0, 255, c.b * 255);
	return ((int)(c.r) * 256 * 256 + (int)(c.g) * 256 + (int)(c.b));
}

int				mix_colors(int c1, int c2, double a)
{
	t_colour	col1;
	t_colour	col2;
	t_colour	o;

	col1 = splitc(c1);
	col2 = splitc(c2);
	o.r = col1.r * (1 - a) + col2.r * a;
	o.g = col1.g * (1 - a) + col2.g * a;
	o.b = col1.b * (1 - a) + col2.b * a;
	return (combine_rgb(o));
}
