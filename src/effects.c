/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:27:41 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 17:09:32 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int				greyscale(int col)
{
	t_colour	c;
	double		average;

	c = splitc(col);
	average = (c.r + c.g + c.b) / 3;
	c.r = average;
	c.g = average;
	c.b = average;
	return (combine_rgb(c));
}

int				sepia(int col)
{
	t_colour	gs;

	gs = splitc((col));
	gs.r = ft_clampf(0, 255, (gs.r * 0.393) + (gs.g * 0.769) + (gs.b * 0.189));
	gs.g = ft_clampf(0, 255, (gs.r * 0.349) + (gs.g * 0.686) + (gs.b * 0.168));
	gs.b = ft_clampf(0, 255, (gs.r * 0.272) + (gs.g * 0.534) + (gs.b * 0.131));
	gs.r *= 0.44 * 2;
	gs.g *= 0.26 * 2;
	gs.b *= 0.08 * 2;
	return (combine_rgb(gs));
}

void			effects(t_main *a, double x, double y, int c)
{
	if (ft_strchr(a->s->effects, 'g') != NULL)
		c = greyscale(c);
	if (ft_strchr(a->s->effects, 's') != NULL)
		c = sepia(c);
	if (ft_strchr(a->s->effects, 'c') != NULL)
		c = cartoonify(c, 64);
	if (ft_strchr(a->s->effects, 'a') != NULL)
		draw_dot(a->s->screen_d, a->s_buffer, vvmake(x, y), c);
	else
		a->s_buffer[(int)y][(int)x] = c;
}
