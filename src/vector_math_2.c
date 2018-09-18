/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 13:02:13 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 09:59:17 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

static t_vector		v_oper_min(t_vector v1, t_vector *v2, double n, char o)
{
	if (o == '+')
	{
		if (n != 0.0f)
		{
			v1.x += n;
			v1.y += n;
			v1.z += n;
		}
		else
		{
			v1.x += v2->x;
			v1.y += v2->y;
			v1.z += v2->z;
		}
	}
	return (v_oper_add(v1, v2, n, o));
}

static t_vector		v_oper_tim(t_vector v1, double n, char o)
{
	if (o == '*')
	{
		v1.x *= n;
		v1.y *= n;
		v1.z *= n;
	}
	else if (o == '/')
	{
		v1.x /= n;
		v1.y /= n;
		v1.z /= n;
	}
	return (v1);
}

t_vector			v_oper_add(t_vector v1, t_vector *v2, double n, char o)
{
	if (o == '-')
	{
		if (n != 0.0f)
		{
			v1.x += n;
			v1.y += n;
			v1.z += n;
		}
		else
		{
			v1.x -= v2->x;
			v1.y -= v2->y;
			v1.z -= v2->z;
		}
	}
	return (v_oper_tim(v1, n, o));
}

t_vector			v_oper(t_vector v1, t_vector *v2, double n, char o)
{
	if (o == '=')
	{
		if (n != 0.0f)
		{
			v1.x = n;
			v1.y = n;
			v1.z = n;
		}
		else
		{
			v1.x = v2->x;
			v1.y = v2->y;
			v1.z = v2->z;
		}
	}
	return (v_oper_min(v1, v2, n, o));
}
