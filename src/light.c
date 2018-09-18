/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:49:14 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/09/30 06:57:14 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int					getcls(t_shapeset *ss, t_vector v)
{
	int				i;
	int				closest;
	double			dist;

	i = ss->lightn;
	closest = i;
	dist = RAY_T_MAX;
	while (--i >= 0)
	{
		if (line_len(v, ss->lightsrc[i]->origin) < dist)
		{
			dist = line_len(v, ss->lightsrc[i]->origin);
			closest = i;
		}
	}
	return (closest);
}

void				addlight(t_shapeset *ss, t_lsrc *lsrc)
{
	ss->lightn += 1;
	ss->lightsrc[ss->lightn] = lsrc;
}

void				mkplight(t_main *a, t_vector loc, double ix)
{
	t_shapes		*s_light_sphere;
	t_lsrc			*lsrc;

	s_light_sphere = (t_shapes *)malloc(sizeof(t_shapes));
	lsrc = (t_lsrc *)malloc(sizeof(t_lsrc));
	s_light_sphere->contents = 'l';
	s_light_sphere->sphere = mksphere(loc, 0.5f, makec(1.0f, 1.0f, 1.0f));
	addshape(a->ss, s_light_sphere);
	lsrc->sphere = s_light_sphere;
	lsrc->origin = lsrc->sphere->sphere.centre;
	lsrc->intensity = ix;
	addlight(a->ss, lsrc);
}

void				mkdlight(t_main *a, t_vector dir, double ix)
{
	t_shapes		*s_light_sphere;
	t_lsrc			*lsrc;

	s_light_sphere = (t_shapes *)malloc(sizeof(t_shapes));
	lsrc = (t_lsrc *)malloc(sizeof(t_lsrc));
	s_light_sphere->contents = 'd';
	lsrc->sphere = s_light_sphere;
	lsrc->origin = dir;
	lsrc->intensity = ix;
	addlight(a->ss, lsrc);
}
