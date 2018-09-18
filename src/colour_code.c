/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:51:29 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/09/30 14:27:25 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void	colour_code(t_shapeset *ss, t_vector v1, t_insec insec, double dmti[4])
{
	t_ray	tmp;

	dmti[0] = line_len(v1, ss->lightsrc[(int)dmti[3]]->origin);
	dmti[1] = ss->lightsrc[(int)dmti[3]]->intensity;
	if (ss->lightsrc[(int)dmti[3]]->sphere->contents == 'd')
	{
		tmp = setr(v1, normv(ss->lightsrc[(int)dmti[3]]->origin), RAY_T_MAX);
		if (!does_intersect(ss, tmp))
			dmti[2] += (dmti[1] / 2) * -v_dot(get_normal(insec),
					normv(ss->lightsrc[(int)dmti[3]]->origin));
	}
	else
	{
		tmp = mkrayv(v1, ss->lightsrc[(int)dmti[3]]->origin);
		tmp.t_max = dmti[0];
		if (dmti[0] < dmti[1])
			if (!does_intersect(ss, tmp))
				dmti[2] += ((dmti[1] - dmti[0]) / dmti[1]) *
						c_shade(insec, ss, (int)dmti[3], v1) +
							c_spec(ss, v1, insec, (int)dmti[3]) *
								c_shade(insec, ss, (int)dmti[3], v1);
	}
}
