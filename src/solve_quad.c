/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:39:04 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/09/30 15:51:52 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

double			get_closest(double t1, double t2)
{
	if (t1 > RAY_T_MIN)
		if (t1 < t2 || t2 < 0)
			return (t1);
	if (t2 > RAY_T_MIN)
		return (t2);
	return (0);
}

double			solve_quadratic(double a, double b, double c)
{
	double		discriminant;
	double		t[3];

	if ((discriminant = sqr(b) - 4 * a * c) < 0)
	{
		return (0);
	}
	t[0] = (-b - sqrt(discriminant)) / (2 * a);
	t[1] = (-b + sqrt(discriminant)) / (2 * a);
	if (((t[2] = get_closest(t[0], t[1])) == 0))
		return (0);
	return (t[2]);
}
