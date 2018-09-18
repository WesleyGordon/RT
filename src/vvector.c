/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 13:02:13 by gsferopo          #+#    #+#             */
/*   Updated: 2017/08/18 13:38:33 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void			clear_vvector(t_vvector *v)
{
	v->x = 0;
	v->y = 0;
}

t_vvector		vvcpy(t_vvector v)
{
	t_vvector	cv;

	cv.x = v.x;
	cv.y = v.x;
	return (cv);
}

t_vvector		vvmake(double u, double v)
{
	t_vvector	cv;

	cv.x = u;
	cv.y = v;
	return (cv);
}

t_vvector		vvmake_f(double f)
{
	t_vvector	cv;

	cv.x = f;
	cv.y = f;
	return (cv);
}
