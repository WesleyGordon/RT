/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_editor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 10:01:10 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 15:36:36 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void			addshape(t_shapeset *ss, t_shapes *s)
{
	ss->shapen += 1;
	ss->shapes[ss->shapen] = s;
}

void			add_plane(t_main *a, t_vector pos, t_vector rot, t_colour c)
{
	t_shapes	*s_plane;

	s_plane = (t_shapes *)malloc(sizeof(t_shapes));
	s_plane->contents = 'p';
	s_plane->plane = mkplane(pos, rot, c);
	addshape(a->ss, s_plane);
}

void			add_sphere(t_main *a, t_vector pos, double size, t_colour c)
{
	t_shapes	*s_sphere;

	s_sphere = (t_shapes *)malloc(sizeof(t_shapes));
	s_sphere->contents = 's';
	s_sphere->sphere = mksphere(pos, size, c);
	addshape(a->ss, s_sphere);
}

void			add_cld(t_main *a, t_cylinder c)
{
	t_shapes	*s_cld;

	s_cld = (t_shapes *)malloc(sizeof(t_shapes));
	s_cld->contents = 'c';
	s_cld->cylinder = mkcylinder(c.centre, c.dir, vvmake(c.radius, c.height),
	c.colour);
	addshape(a->ss, s_cld);
}

void			add_cone(t_main *a, t_cone c)
{
	t_shapes	*s_cone;

	s_cone = (t_shapes *)malloc(sizeof(t_shapes));
	s_cone->contents = 'n';
	s_cone->cone = mkcone(c.centre, c.dir, vvmake(c.angle, c.height), c.colour);
	addshape(a->ss, s_cone);
}
