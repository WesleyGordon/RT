/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:34:26 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/10/01 16:04:58 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vectors.h"
# include "shapes.h"
# include <SDL2/SDL.h>

typedef struct		s_settings
{
	char			*effects;
	double			amb;
	double			anti_a;
	unsigned int	sky_c;
	unsigned int	fov;
	unsigned int	rdepth;
	unsigned int	shwbar;
	unsigned int	svimg;
	unsigned int	tread;
	t_vvector		screen_d;
}					t_settings;

typedef struct		s_perspective_camera
{
	t_point			origin;
	t_vector		forward;
	t_vector		up;
	t_vector		right;
	t_vector		t;
	t_vector		upguide;
	double			h;
	double			w;
}					t_perc;

typedef struct		s_main
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	SDL_Surface		*img;
	SDL_Surface		*canvis;
	t_perc			*camera;
	t_settings		*s;
	t_shapeset		*ss;
	int				**s_buffer;
}					t_main;

typedef struct		s_trace
{
	t_main			*a;
	int				startx;
	int				starty;
	int				endx;
	int				endy;
}					t_trace;

typedef struct		s_tracers
{
	t_trace			t1;
	t_trace			t2;
	t_trace			t3;
	t_trace			t4;
}					t_tracers;

#endif
