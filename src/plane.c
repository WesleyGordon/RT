/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:39:18 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/09/30 15:51:48 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int			p_intersect(t_plane p, t_insec *int_r)
{
	double	ddotn;
	double	t;

	ddotn = v_dot(int_r->ray.direction, p.normal);
	if (ddotn == 0.0f)
		return (0);
	t = v_dot(v_oper(p.position, &int_r->ray.origin, 0, '-'), p.normal) / ddotn;
	if (t <= RAY_T_MIN || t >= int_r->t)
		return (0);
	if (t < int_r->t)
	{
		int_r->t = t;
		int_r->shape_info.contents = 'p';
		int_r->shape_info.plane = p;
		int_r->colour = p.colour;
	}
	return (1);
}

double		p_does_insect(t_plane p, t_ray ray)
{
	double	ddotn;
	double	t;

	ddotn = v_dot(ray.direction, p.normal);
	if (ddotn == 0)
		return (0);
	t = v_dot(v_oper(p.position, &ray.origin, 0, '-'), p.normal) / ddotn;
	if (t <= RAY_T_MIN || t >= ray.t_max)
		return (0);
	return (1);
}
