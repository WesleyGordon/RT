/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:29:15 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 08:29:15 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_point			calc_p(t_ray r, double t)
{
	r.origin.x += r.direction.x * t;
	r.origin.y += r.direction.y * t;
	r.origin.z += r.direction.z * t;
	return (r.origin);
}

t_ray			mkrayv(t_vector v1, t_vector v2)
{
	t_vector	direction;
	t_ray		ray;

	direction = v_oper(v2, &v1, 0, '-');
	ray = setr(makev(v1.x, v1.y, v1.z), normv(direction), RAY_T_MAX);
	return (ray);
}

t_ray			mkray(t_perc *c, t_vvector point)
{
	t_vector	direction;
	t_ray		ray;
	t_vector	a;
	t_vector	b;
	t_vector	z;

	a = v_oper(c->right, NULL, c->w * point.x, '*');
	b = v_oper(c->up, NULL, c->h * point.y, '*');
	z = v_oper(a, &b, 0, '+');
	direction = v_oper(c->forward, &z, 0, '+');
	ray = setr(c->origin, normv(direction), RAY_T_MAX);
	return (ray);
}

t_ray			setr(t_point origin, t_vector direction, double t_max)
{
	t_ray		r;

	r.origin = origin;
	r.direction = direction;
	r.t_max = t_max;
	return (r);
}
