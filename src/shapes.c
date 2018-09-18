/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 09:53:48 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 09:53:48 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_vector		find_point(t_vector start, t_vector vect, double distance)
{
	t_vector	new_point;

	new_point.x = start.x + (vect.x * distance);
	new_point.y = start.y + (vect.y * distance);
	new_point.z = start.z + (vect.z * distance);
	return (new_point);
}

t_vector		get_normal(t_insec insec)
{
	t_shapes	curshape;
	t_vector	v1;

	v1 = calc_p(insec.ray, insec.t);
	curshape = insec.shape_info;
	if (curshape.contents == 's')
	{
		v1 = v_oper(curshape.sphere.centre, &v1, 0, '-');
		return (normv(v1));
	}
	if (curshape.contents == 'p')
		return (v_oper(curshape.plane.normal, NULL, -1, '*'));
	if (curshape.contents == 'c')
		return (cld_norm(insec));
	if (curshape.contents == 'n')
		return (cone_norm(insec));
	ft_putendl("NO SHAPE FOUND!");
	return (makev(0, 0, 0));
}

double			line_len(t_vector v1, t_vector v2)
{
	return (sqrt(sqr(v2.x - v1.x) + sqr(v2.y - v1.y) + sqr(v2.z - v1.z)));
}

t_plane			mkplane(t_point position, t_vector normal, t_colour colour)
{
	t_plane		p;

	p.position = position;
	p.normal = normal;
	p.colour = colour;
	return (p);
}

t_sphere		mksphere(t_point centre, double radius, t_colour colour)
{
	t_sphere	s;

	s.centre = centre;
	s.radius = radius;
	s.colour = colour;
	return (s);
}
