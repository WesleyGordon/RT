/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 13:40:50 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 15:08:36 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_cylinder		mkcylinder(t_point centre, t_vector dir,
	t_vvector rh, t_colour colour)
{
	t_cylinder	c;

	c.centre = centre;
	c.dir = normv(dir);
	c.radius = rh.x;
	c.height = rh.y;
	c.colour = colour;
	return (c);
}

t_vector		cld_norm(t_insec insec)
{
	t_shapes	curshape;
	t_vector	vm;
	t_vector	tmp;
	double		m;
	t_vector	v1;

	v1 = calc_p(insec.ray, insec.t);
	curshape = insec.shape_info;
	m = v_dot(insec.ray.direction, curshape.cylinder.dir) * insec.t;
	m += v_dot(v_oper(insec.ray.origin, &curshape.cylinder.centre, 0, '-'),
	curshape.cylinder.dir);
	vm = (v_oper(curshape.cylinder.dir, NULL, m, '*'));
	tmp = (v_oper(v1, &curshape.cylinder.centre, 0, '-'));
	tmp = (v_oper(tmp, &vm, 0, '-'));
	tmp = (v_oper(tmp, NULL, -1, '*'));
	return (normv(tmp));
}

double			cylinder_equation(t_cylinder *cld, t_ray *ray)
{
	t_vector	x;
	double		a;
	double		b;
	double		c;
	double		disc;

	x = v_oper(ray->origin, &cld->centre, 0, '-');
	a = v_dot(ray->direction, ray->direction)
	- sqr(v_dot(ray->direction, cld->dir));
	b = (v_dot(ray->direction, x) - (v_dot(ray->direction, cld->dir)
	* v_dot(x, cld->dir))) * 2;
	c = v_dot(x, x) - sqr(v_dot(x, cld->dir)) - sqr(cld->radius);
	disc = solve_quadratic(a, b, c);
	if (disc < 1)
		return (0);
	return (disc);
}

int				c_intersect(t_cylinder c, t_insec *int_r)
{
	double		t;
	t_vector	p;

	t = cylinder_equation(&c, &int_r->ray);
	if (t == 0)
		return (0);
	p = calc_p(int_r->ray, t);
	if ((v_dot(v_oper(p, &c.centre, 0, '-'), c.dir) > 0))
		return (0);
	if (t < int_r->t)
	{
		int_r->t = t;
		int_r->shape_info.contents = 'c';
		int_r->shape_info.cylinder = c;
		int_r->colour = c.colour;
	}
	return (1);
}

int				c_does_intersect(t_cylinder c, t_ray ray)
{
	double		t;
	t_vector	p;

	t = cylinder_equation(&c, &ray);
	if (t == 0)
		return (0);
	p = calc_p(ray, t);
	if ((v_dot(v_oper(p, &c.centre, 0, '-'), c.dir) > 0))
		return (0);
	return (1);
}
