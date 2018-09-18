/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 09:23:46 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 18:12:34 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void			spawn_cld(t_main *a, int f, int r, int u)
{
	t_cylinder	c;

	c.centre = makev(f, u, r);
	c.dir = makev(0, 1, 0);
	c.radius = f % 15;
	c.height = r % 15;
	c.colour = makec255(
		ft_wrap(50, 255, rand() % ((f * r * u) + 1)),
			ft_wrap(50, 255, rand() % ((f * r * u) + 1)),
				ft_wrap(50, 255, rand() % ((f * r * u) + 1)));
	add_cld(a, c);
}

void			spawn_obj(t_main *a, char obj)
{
	int			f;
	int			r;
	int			u;

	f = rand() % 200 - 100;
	r = rand() % 50 - 25;
	u = rand() % 20 - 10;
	if (obj == 's')
		add_sphere(a, makev(f, u, r), f % 15,
			makec255(ft_wrap(50, 255, rand() % ((f * r * u) + 1)),
				ft_wrap(50, 255, rand() % ((f * r * u) + 1)),
					ft_wrap(50, 255, rand() % ((f * r * u) + 1))));
	if (obj == 'c')
		spawn_cld(a, f, r, u);
	if (obj == 'l')
		mkplight(a, makev(f, ft_wrap(2, 30, u), r),
		ft_wrap(10, 100, ((f * r * u) + 1)));
	if (a->s_buffer)
	{
		loop_hook(a);
		put_pixel(a);
	}
}

void			rand_scene(t_main *a)
{
	int			rnum;
	int			icount;

	rnum = rand() % 2000;
	icount = ft_wrap(0, 10, rand() % rnum);
	while (icount-- >= 0)
		spawn_obj(a, 's');
	icount = ft_wrap(0, 10, rand() % rnum);
	while (icount-- >= 0)
		spawn_obj(a, 'c');
	icount = ft_wrap(0, 10, rand() % rnum);
	while (icount-- >= 0)
		spawn_obj(a, 'l');
	add_plane(a, makev(-5, -5, 0), makev(0, 1, 0), makec(0.46, 0.85, 0.18));
}

void			map_world(t_main *a)
{
	rand_scene(a);
}
