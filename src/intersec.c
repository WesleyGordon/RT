/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 10:55:27 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 01:33:47 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int					intersect(t_shapeset *ss, t_insec *ray)
{
	t_shapes		*curshape;
	int				neg;
	int				b;
	int				i;

	i = ss->shapen + 1;
	b = 0;
	neg = 0;
	while (--i >= 0)
	{
		curshape = ss->shapes[i];
		if (curshape->contents == 'p')
			if (p_intersect(curshape->plane, ray))
				b = 1;
		if (curshape->contents == 's' || curshape->contents == 'l')
			if (s_intersect(curshape->sphere, ray))
				b = 1;
		if (curshape->contents == 'c')
			if (c_intersect(curshape->cylinder, ray))
				b = 1;
		if (curshape->contents == 'n')
			if (n_intersect(curshape->cone, ray))
				b = 1;
	}
	return (b > 0);
}

int					does_intersect(t_shapeset *ss, t_ray ray)
{
	t_shapes		*curshape;
	int				i;

	i = ss->shapen + 1;
	while (--i >= 0)
	{
		curshape = ss->shapes[i];
		if (curshape->contents == 'p')
			if (p_does_insect(curshape->plane, ray))
				return (1);
		if (curshape->contents == 's')
			if (s_does_insect(curshape->sphere, ray))
				return (1);
		if (curshape->contents == 'c')
			if (c_does_intersect(curshape->cylinder, ray))
				return (1);
		if (curshape->contents == 'n')
			if (n_does_intersect(curshape->cone, ray))
				return (1);
	}
	return (0);
}
