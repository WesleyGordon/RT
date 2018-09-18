/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:23:28 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/09/30 15:30:57 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int		s_intersect(t_sphere s, t_insec *int_r)
{
	t_ray	local_ray;
	double	t;
	double	a;
	double	b;
	double	c;

	local_ray = int_r->ray;
	local_ray.origin = v_oper(local_ray.origin, &s.centre, 0, '-');
	a = v_len_sqr(local_ray.direction);
	b = 2 * v_dot(local_ray.direction, local_ray.origin);
	c = v_len_sqr(local_ray.origin) - sqr(s.radius);
	t = solve_quadratic(a, b, c);
	if (t == 0)
		return (0);
	if (t < int_r->t && t > RAY_T_MIN)
	{
		int_r->t = t;
		int_r->shape_info.contents = 's';
		int_r->shape_info.sphere = s;
		int_r->colour = s.colour;
	}
	return (1);
}

double	s_does_insect(t_sphere s, t_ray ray)
{
	t_ray	local_ray;
	double	t;
	double	a;
	double	b;
	double	c;

	local_ray = ray;
	local_ray.origin = v_oper(local_ray.origin, &s.centre, 0, '-');
	a = v_len_sqr(local_ray.direction);
	b = 2 * v_dot(local_ray.direction, local_ray.origin);
	c = v_len_sqr(local_ray.origin) - sqr(s.radius);
	t = solve_quadratic(a, b, c);
	if (t == 0)
		return (0);
	return (t < ray.t_max);
}
