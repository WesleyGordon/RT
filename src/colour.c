/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 10:44:10 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 12:41:49 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

t_colour			c_frac(t_insec insec, t_shapeset *ss, int rem)
{
	t_vector		ref;

	ref = refract(insec.ray.origin, get_normal(insec), 0.5);
	insec.ray = setr(calc_p(insec.ray, insec.t + 3), ref, RAY_T_MAX);
	insec.t = RAY_T_MAX;
	if (!intersect(ss, &insec))
		insec.colour = makec(0, 0, 0);
	if (rem > 1)
		return (c_frac(insec, ss, rem - 1));
	return (insec.colour);
}

double				c_shade(t_insec insec, t_shapeset *ss, int lsrc,
	t_vector cv)
{
	double			shade;
	double			dis;
	t_ray			tmp;
	t_vector		lv;
	t_vector		dir;

	shade = 0;
	lv = ss->lightsrc[lsrc]->origin;
	dir = normv(v_oper(cv, &lv, 0, '-'));
	dis = line_len(cv, ss->lightsrc[lsrc]->origin);
	tmp = mkrayv(cv, lv);
	tmp.t_max = dis;
	if (!does_intersect(ss, tmp))
		shade = v_dot(get_normal(insec), dir);
	if (dis < 1)
		shade = 1;
	return (shade);
}

double				c_spec(t_shapeset *ss, t_vector v1, t_insec insec, int lsrc)
{
	t_vector		l_;
	t_vector		r_;
	t_vector		n_;
	t_vector		v_;

	l_ = v_oper(v1, &ss->lightsrc[lsrc]->origin, 0, '-');
	n_ = get_normal(insec);
	r_ = v_oper(n_, NULL, 2 * v_dot(n_, l_), '*');
	r_ = normv(v_oper(r_, &l_, 0, '-'));
	v_ = normv(v_oper(insec.ray.direction, NULL, -1, '*'));
	return (pow(v_dot(v_, r_), 50));
}

double				c_ls(t_shapeset *ss, t_vector v1, t_insec insec)
{
	double			dmti[4];

	dmti[0] = 0;
	dmti[3] = ss->lightn + 1;
	dmti[2] = 0;
	while (--dmti[3] >= 0)
		colour_code(ss, v1, insec, dmti);
	return (dmti[2]);
}

int					cont_c(t_main *a, t_insec insec, int rem)
{
	t_colour		c;
	double			max;
	double			inten;
	int				i;

	c = insec.colour;
	if (c.r == 2)
		c = c_frac(insec, a->ss, 3);
	max = ft_clampf(a->s->amb, 1, c_ls(a->ss, calc_p(insec.ray, insec.t),
	insec));
	inten = (max * 2) - 1;
	i = combine_rgbm(c);
	i = add_col(i, (inten * 255));
	if (ft_strchr(a->s->effects, 'r') && a->ss->lightn - 1 > 0)
		if (max > 0 && rem != 0)
		{
			c = c_reflection(a, insec, a->s->rdepth - 1);
			i = mix_colors(i, combine_rgb(c), 0.5);
			i = mul_col(i, 2);
		}
	return (i);
}
