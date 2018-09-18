/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:51:19 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 16:51:34 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "vectors.h"

typedef struct	s_parameters
{
	t_colour	colour;
	double		trans_obj;
	double		reflec;
}				t_param;

typedef struct	s_ray
{
	t_point		origin;
	t_vector	direction;
	double		t_max;
}				t_ray;

typedef struct	s_shape_details
{
	int			intersect;
	int			does_intersect;
}				t_shape_d;

typedef struct	s_plane
{
	t_point		position;
	t_vector	normal;
	t_colour	colour;
	t_shape_d	insec;
}				t_plane;

typedef struct	s_sphere
{
	t_point		centre;
	double		radius;
	t_colour	colour;
	t_shape_d	insec;
}				t_sphere;

typedef struct	s_cylinder
{
	t_point		centre;
	t_vector	dir;
	double		radius;
	double		height;
	t_colour	colour;
	t_shape_d	insec;
}				t_cylinder;

typedef struct	s_cone
{
	t_point		centre;
	t_vector	dir;
	double		angle;
	double		height;
	t_colour	colour;
	t_shape_d	insec;
}				t_cone;

typedef struct	s_shapes
{
	char		contents;
	double		refrac;
	int			neg_elem;
	t_plane		plane;
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_cone		cone;
}				t_shapes;

typedef struct	s_intersection
{
	t_ray		ray;
	double		t;
	t_shapes	shape_info;
	t_colour	colour;
	int			nshhit;
}				t_insec;

typedef struct	s_light_source
{
	t_shapes	*sphere;
	t_point		origin;
	double		intensity;
	t_colour	colour;
}				t_lsrc;

typedef struct	s_shapeset
{
	t_shapes	*shapes[50];
	t_lsrc		*lightsrc[50];
	int			shapen;
	int			lightn;
}				t_shapeset;

#endif
