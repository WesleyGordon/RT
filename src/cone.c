/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:06:19 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 16:45:55 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_cone			mkcone(t_point centre, t_vector dir,
	t_vvector ah, t_colour colour)
{
	t_cone	n;

	n.centre = centre;
	n.dir = dir;
	n.angle = ah.x;
	n.height = ah.y;
	n.colour = colour;
	return (n);
}

t_vector		cone_norm(t_insec insec)
{
	t_cone		cone;
	t_vector	a;
	t_vector	p;
	double		cp;
	double		ca;

	cone = insec.shape_info.cone;
	p = calc_p(insec.ray, insec.t);
	cp = line_len(p, cone.centre);
	ca = cp / (cos(DEG_T_RAD * cone.angle / 2));
	a = find_point(cone.centre, cone.dir, ca);
	a = v_oper(p, &a, 0, '-');
	return (normv(a));
}

int				n_intersect(t_cone n, t_insec *int_r)
{
	t_vector	x;
	t_vector	p;
	double		mabcd[5];

	x = v_oper(int_r->ray.origin, &n.centre, 0, '-');
	p = calc_p(int_r->ray, int_r->t);
	mabcd[1] = sqr(v_dot(int_r->ray.direction, n.dir))
	- sqr(cos(n.angle * DEG_T_RAD));
	mabcd[2] = 2 * (v_dot(int_r->ray.direction, n.dir) * v_dot(x, n.dir)
	- (v_dot(int_r->ray.direction, x) * sqr(cos(n.angle * DEG_T_RAD))));
	mabcd[3] = sqr(v_dot(x, n.dir)) - v_dot(x, x)
	* sqr(cos(n.angle * DEG_T_RAD));
	mabcd[4] = solve_quadratic(mabcd[1], mabcd[2], mabcd[3]);
	p = calc_p(int_r->ray, mabcd[4]);
	mabcd[0] = line_len(p, n.centre) / (cos(DEG_T_RAD * n.angle / 2));
	if (mabcd[0] > n.height || mabcd[4] < 1 ||
		(v_dot(v_oper(p, &n.centre, 0, '-'), n.dir) > 0))
		return (0);
	if (!(mabcd[4] < int_r->t))
		return (1);
	int_r->t = mabcd[4] - RAY_T_MIN;
	int_r->shape_info.contents = 'n';
	int_r->shape_info.cone = n;
	int_r->colour = n.colour;
	return (mabcd[4]);
}

int				n_does_intersect(t_cone n, t_ray ray)
{
	t_vector	x;
	t_vector	p;
	double		mabcd[5];

	x = v_oper(ray.origin, &n.centre, 0, '-');
	mabcd[1] = sqr(v_dot(ray.direction, n.dir)) - sqr(cos(n.angle * DEG_T_RAD));
	mabcd[2] = 2 * (v_dot(ray.direction, n.dir) * v_dot(x, n.dir)
	- (v_dot(ray.direction, x) * sqr(cos(n.angle * DEG_T_RAD))));
	mabcd[3] = sqr(v_dot(x, n.dir)) - v_dot(x, x)
	* sqr(cos(n.angle * DEG_T_RAD));
	mabcd[4] = solve_quadratic(mabcd[1], mabcd[2], mabcd[3]);
	p = calc_p(ray, mabcd[4]);
	if (v_dot(v_oper(p, &n.centre, 0, '-'), n.dir) > 0)
		return (0);
	mabcd[0] = line_len(p, n.centre) / (cos(DEG_T_RAD * n.angle / 2));
	if (mabcd[0] > n.height || mabcd[4] < 1)
		return (0);
	return (1);
}
