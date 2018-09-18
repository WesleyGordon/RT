/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:27:03 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 07:32:51 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

double		gaussian(double n)
{
	return (exp(-sqr(n) * 4));
}

double		dist(double x1, double y1, double x2, double y2)
{
	return (sqrt(sqr(x2 - x1) + sqr(y2 - y1)));
}

void		draw_dot(t_vvector sd, int **buff, t_vvector v, int col)
{
	double		size;
	t_vvector	s;
	t_vvector	c;
	double		mix;

	size = 1.2;
	s.x = (int)v.x - size;
	s.y = (int)v.y - size;
	c.x = s.x;
	while (c.x < ceil(size * 2) + (int)v.x)
	{
		c.y = s.y;
		while (c.y < ceil(size * 2) + (int)v.y)
		{
			if (0 <= c.x && c.x < sd.x && 0 <= c.y && c.y < sd.y)
			{
				mix = gaussian(dist(c.x + 0.5, c.y + 0.5, v.x, v.y)
				/ size) / size;
				buff[(int)c.y][(int)c.x] = mix_colors(buff[(int)c.y][(int)c.x],
													col, mix);
			}
			c.y++;
		}
		c.x++;
	}
}
