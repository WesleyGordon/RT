/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:41:39 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 16:09:48 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int				loop_hook(t_main *a)
{
	ft_putstr("\033[0;32m------- STARTING TRACE --------\n");
	if (a->s->shwbar)
	{
		ft_putstr("\033[0;31mDISTANCE: ");
		ft_putstr("\033[0;34m-----------");
		ft_putstr("--------------------------------------\n");
		ft_putstr("\033[0;31mProgress: ");
	}
	if (a->s->tread)
		thread_trace(a);
	else
		ray_tracer(a);
	ft_putendl("");
	if (ft_strchr(a->s->effects, 'd') != NULL)
	{
		ft_putstr("\033[0;33m------- DITHER --------\n");
		dither(a);
	}
	progress(a, 1);
	ft_putstr("\033[0;32m------- TRACED --------\n");
	return (1);
}

void			mvlight(int keycode, t_main *a, int idx, int sd)
{
	if (keycode == SDLK_RIGHT)
		a->ss->lightsrc[idx]->sphere->sphere.centre.z += 5;
	if (keycode == SDLK_LEFT)
		a->ss->lightsrc[idx]->sphere->sphere.centre.z -= 5;
	if (sd)
	{
		if (keycode == SDLK_UP)
			a->ss->lightsrc[idx]->sphere->sphere.centre.y += 5;
		if (keycode == SDLK_DOWN)
			a->ss->lightsrc[idx]->sphere->sphere.centre.y -= 5;
	}
	else
	{
		if (keycode == SDLK_UP)
			a->ss->lightsrc[idx]->sphere->sphere.centre.x += 5;
		if (keycode == SDLK_DOWN)
			a->ss->lightsrc[idx]->sphere->sphere.centre.x -= 5;
	}
	a->ss->lightsrc[idx]->origin = a->ss->lightsrc[idx]->sphere->sphere.centre;
}

void			world_hook(int keycode, t_main *a)
{
	static int	shift_down;
	static int	ctrl_down;
	static int	idx = 0;

	ft_printf(3, "Light[", ft_itoa(idx), "] selected");
	if (keycode == SDLK_KP_PLUS && idx < a->ss->lightn)
		idx++;
	if (keycode == SDLK_KP_MINUS && idx > 0)
		idx--;
	(ctrl_down) ? mvlight(keycode, a, idx, shift_down)
	: mvcamera(keycode, a, shift_down);
	if (keycode == SDLK_LSHIFT)
	{
		if (shift_down == 0)
			shift_down = 1;
		else
			shift_down = 0;
	}
	if (keycode == SDLK_LCTRL)
	{
		if (ctrl_down == 0)
			ctrl_down = 1;
		else
			ctrl_down = 0;
	}
}

void			key_hook(int keycode, t_main *a)
{
	world_hook(keycode, a);
	if (keycode == SDLK_ESCAPE)
		exit(-1);
	if (keycode == SDLK_SPACE)
	{
		loop_hook(a);
		put_pixel(a);
	}
	if (keycode == SDLK_s)
		spawn_obj(a, 's');
	if (keycode == SDLK_d)
		spawn_obj(a, 'c');
	if (keycode == SDLK_a)
		spawn_obj(a, 'l');
	if (keycode == SDLK_p)
		print_coord(a);
	if (keycode == SDLK_i)
		ft_printf(5, "UP - move light/camera up OR move it forwards or back\n",
		"DOWN - move light/camera down OR move it forwards or back\n",
		"Toggle up and down using SHIFT!\n",
		"Toggle light or camera using CTRL!\n",
		"SPACE - Re-trace!\n");
}
