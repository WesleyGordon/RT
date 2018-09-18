/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:52:13 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 16:52:30 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "main.h"

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;

	double		length_sqr;
	double		length;
}				t_vector;

typedef struct	s_vvector
{
	double		x;
	double		y;
}				t_vvector;

typedef struct s_vector	t_point;

typedef struct	s_colour
{
	double		r;
	double		g;
	double		b;
	double		a;
}				t_colour;

#endif
