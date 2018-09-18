/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:29:26 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/09/30 06:53:16 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void				put_pixel(t_main *a)
{
	SDL_Surface		*surface;
	unsigned int	*pixels;
	t_vvector		pos;

	surface = SDL_CreateRGBSurface(0, a->s->screen_d.x,
									a->s->screen_d.y, 32, 0, 0, 0, 1);
	pixels = (unsigned int *)surface->pixels;
	pos.y = -1;
	while (++pos.y < a->s->screen_d.y)
	{
		pos.x = -1;
		while (++pos.x < a->s->screen_d.x)
		{
			pixels[(int)(pos.x + (pos.y * a->s->screen_d.x))] =
				a->s_buffer[(int)pos.y][(int)pos.x];
		}
	}
	if (a->s->svimg)
		SDL_SaveBMP(surface, "pic.bmp");
	a->img = surface;
}
