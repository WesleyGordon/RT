/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 09:58:25 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 09:58:25 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

double			sqr(double n)
{
	return (n * n);
}

double			v_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double			vv_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

t_vector		v_cross(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

t_vector		normv(t_vector v)
{
	double		l;

	l = v_len(v);
	v.x /= l;
	v.y /= l;
	v.z /= l;
	return (v);
}
