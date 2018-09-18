/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 13:02:13 by gsferopo          #+#    #+#             */
/*   Updated: 2017/08/18 13:42:49 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_colour		makec(double r, double g, double b)
{
	t_colour	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_vector		makev(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector		makev_f(double f)
{
	t_vector	v;

	v.x = f;
	v.y = f;
	v.z = f;
	return (v);
}

double			v_len_sqr(t_vector v)
{
	return (sqr(v.x) + sqr(v.y) + sqr(v.z));
}

double			v_len(t_vector v)
{
	return (sqrt(v_len_sqr(v)));
}
