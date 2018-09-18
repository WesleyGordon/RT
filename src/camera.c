/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 09:10:45 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 09:10:46 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_perc			persc(t_perc cam, t_main a)
{
	t_perc		c;
	double		ar;

	ar = a.s->screen_d.x / a.s->screen_d.y;
	c.origin = cam.origin;
	c.forward = normv(v_oper(cam.t, &cam.origin, 0, '-'));
	c.right = normv(v_cross(c.forward, cam.upguide));
	c.up = v_cross(c.right, c.forward);
	c.h = atan(DEG_T_RAD * a.s->fov);
	c.w = c.h * ar;
	return (c);
}
