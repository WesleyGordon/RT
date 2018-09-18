/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 09:44:23 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 09:46:04 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

static t_vector	refract_2(t_vector i, t_vector n, double *anntk)
{
	if (anntk[4] < 0)
		return (makev(0, 0, 0));
	else
	{
		i = v_oper(i, NULL, anntk[3], '*');
		anntk[4] = anntk[3] * anntk[0] - sqrtf(anntk[4]);
		n = v_oper(n, NULL, anntk[4], '*');
		i = v_oper(i, &n, 0, '+');
		return (i);
	}
}

t_vector		refract(t_vector i, t_vector n, double ior)
{
	double		anntk[5];

	anntk[1] = 1;
	anntk[2] = ior;
	anntk[0] = ft_clampf(-1, 1, v_dot(i, n));
	if (anntk[0] < 0)
		anntk[0] *= -1;
	else
	{
		n = v_oper(n, NULL, -1, '*');
		anntk[1] = ior;
		anntk[2] = 1;
	}
	anntk[3] = anntk[1] / anntk[2];
	anntk[4] = 1 - sqr(anntk[3]) * (1 - sqr(anntk[0]));
	return (refract_2(i, n, anntk));
}

t_vector		reflect(t_vector v1, t_vector v2)
{
	t_vector	tmp;
	double		n;

	n = 2 * v_dot(v1, v2);
	tmp = v_oper(v2, NULL, n, '*');
	return (v_oper(v1, &tmp, 0, '-'));
}

static t_insec	c_ref(t_main *a, t_insec insec, int depth)
{
	t_vector	v1;
	t_colour	old_c;
	t_vector	hit_normal;
	int			clsrc;

	old_c = insec.colour;
	v1 = calc_p(insec.ray, insec.t - RAY_T_MIN);
	clsrc = getcls(a->ss, v1);
	hit_normal = get_normal(insec);
	if (a->ss->lightsrc[clsrc]->sphere->contents == 'd')
		insec.t = INFINITY;
	else
		insec.t = a->ss->lightsrc[clsrc]->intensity;
	insec.ray = setr(v1, reflect(insec.ray.direction, hit_normal), RAY_T_MAX);
	intersect(a->ss, &insec);
	insec.t -= RAY_T_MIN;
	insec.colour = splitc(cont_c(a, insec, 0));
	insec.colour = splitc(mix_colors(combine_rgb(old_c),
	combine_rgb(insec.colour), 0.5));
	if (!(depth < 1))
		return (c_ref(a, insec, depth - 1));
	return (insec);
}

t_colour		c_reflection(t_main *a, t_insec insec, int depth)
{
	insec = c_ref(a, insec, depth);
	return (insec.colour);
}
