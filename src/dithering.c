/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dithering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:27:46 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 17:59:15 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int				add_d_col(int c, double n)
{
	t_colour	slt;
	t_colour	col;

	slt = splitc(c);
	col = splitc(n);
	slt.r += col.r;
	slt.r = ft_clampf(0, 255, slt.r);
	slt.g += col.g;
	slt.g = ft_clampf(0, 255, slt.g);
	slt.b += col.b;
	slt.b = ft_clampf(0, 255, slt.b);
	return (combine_rgb(slt));
}

void			ft_filter(t_main *a, t_vvector v)
{
	int			quant_error;
	int			oldpixel;
	int			newpixel;

	oldpixel = a->s_buffer[(int)v.y][(int)v.x];
	newpixel = cartoonify(oldpixel, 64);
	a->s_buffer[(int)v.y][(int)v.x] = newpixel;
	quant_error = min_cols(oldpixel, newpixel);
	a->s_buffer[(int)v.y][(int)v.x + 1] = add_d_col(
		a->s_buffer[(int)v.y][(int)v.x + 1], mul_col(quant_error, 0.4375));
	a->s_buffer[(int)v.y + 1][(int)v.x - 1] = add_d_col(
		a->s_buffer[(int)v.y + 1][(int)v.x - 1], mul_col(quant_error, 0.1875));
	a->s_buffer[(int)v.y + 1][(int)v.x] = add_d_col(
		a->s_buffer[(int)v.y + 1][(int)v.x], mul_col(quant_error, 0.3125));
	a->s_buffer[(int)v.y + 1][(int)v.x + 1] = add_d_col(
		a->s_buffer[(int)v.y + 1][(int)v.x + 1], mul_col(quant_error, 0.0625));
}

double			cto256(int c)
{
	t_colour	n;

	n = splitc(c);
	n.r = n.r - ((int)n.r % 16);
	n.g = n.g - ((int)n.g % 16);
	n.b = n.b - ((int)n.b % 16);
	return (combine_rgb(n));
}

void			dither(t_main *a)
{
	t_vvector	v;

	v.y = -1;
	while (++v.y < a->s->screen_d.y - 2)
	{
		v.x = -1;
		while (++v.x < a->s->screen_d.x - 2)
		{
			ft_filter(a, v);
		}
	}
}
