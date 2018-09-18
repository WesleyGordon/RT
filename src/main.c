/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:20:15 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 15:28:08 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void				winctrl(t_main *a)
{
	int				run;

	run = 1;
	while (run)
	{
		while (SDL_PollEvent(&a->event))
		{
			if (a->event.type == SDL_QUIT)
				run = 0;
			else if (a->event.type == SDL_KEYDOWN)
				key_hook(a->event.key.keysym.sym, a);
		}
		SDL_BlitSurface(a->img, NULL, a->canvis, NULL);
		SDL_UpdateWindowSurface(a->win);
	}
	SDL_FreeSurface(a->img);
	SDL_FreeSurface(a->canvis);
	SDL_DestroyWindow(a->win);
	SDL_Quit();
}

int					startup(t_main *a, int ac, char **av)
{
	int				rtr;

	srand(time(0));
	read_s_file(a);
	if (ac == 1)
	{
		ft_putendl("\033[0;32m- Loading default map -\033[0m\n");
		map_world(a);
		return (1);
	}
	else
	{
		ft_putendl("\033[0;33m- Attempting to load file -\033[0m\n");
		if ((rtr = read_m_file(a, av)) != 0)
		{
			ft_putstr("\n\033[0;31m- Theres an error from the -\033[0m\n");
			ft_putnbr(rtr);
			ft_putstr(" entry!\n");
			return (-1);
		}
	}
	return (0);
}

void				put_error(char *s)
{
	ft_putendl(s);
	exit(-1);
}

int					main(int ac, char **av)
{
	t_main			a;
	t_shapeset		ss;
	t_perc			c;

	a.ss = &ss;
	a.ss->shapen = -1;
	a.ss->lightn = -1;
	c.origin = makev(-15, 1, 0);
	c.t = makev(0, 1, 0);
	c.upguide = makev(0, 1, 0);
	a.camera = &c;
	a.s_buffer = NULL;
	if (startup(&a, ac, av) == -1)
		put_error("Failed during start up stage, check settings file");
	if (alloc_buf(&a) == -1)
		put_error("Failed to Malloc screen buffer");
	c = persc(c, a);
	ft_putstr("\033[0;32m------- STARTUP SUCCESS -------\033[0m\n");
	loop_hook(&a);
	put_pixel(&a);
	a.win = SDL_CreateWindow("RT - Project", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, a.s->screen_d.x, a.s->screen_d.y,
	SDL_WINDOW_OPENGL);
	a.canvis = SDL_GetWindowSurface(a.win);
	winctrl(&a);
}
