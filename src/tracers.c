/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 09:55:40 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 16:12:59 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void			*ray_trace_treaded(void *v)
{
	t_main		*a;
	t_vvector	n;
	t_vvector	s_cord;
	t_insec		insec;

	a = ((t_trace *)v)->a;
	n.y = ((t_trace *)v)->starty * a->s->anti_a - 1;
	while (++n.y < ((t_trace *)v)->endy * a->s->anti_a)
	{
		n.x = ((t_trace *)v)->startx * a->s->anti_a - 1;
		while (++n.x < ((t_trace *)v)->endx * a->s->anti_a)
		{
			progress(a, 0);
			s_cord.x = ((2 * n.x / a->s->anti_a) / SDX - 1);
			s_cord.y = ((-2 * n.y / a->s->anti_a) / SDY + 1);
			insec.ray = mkray(a->camera, s_cord);
			insec.t = insec.ray.t_max;
			if (intersect(a->ss, &insec))
				effects(a, n.x / a->s->anti_a, n.y / a->s->anti_a,
					cont_c(a, insec, 1));
			else
				effects(a, n.x / a->s->anti_a, n.y / a->s->anti_a, a->s->sky_c);
		}
	}
	return (NULL);
}

void			ray_tracer(t_main *a)
{
	int			x;
	int			y;
	t_vvector	s_cord;
	t_insec		insec;

	y = -1 * a->s->anti_a;
	while (++y < SDY * a->s->anti_a)
	{
		x = -1 * a->s->anti_a;
		while (++x < SDX * a->s->anti_a)
		{
			progress(a, 0);
			s_cord.x = ((2 * x / a->s->anti_a) / SDX - 1);
			s_cord.y = ((-2 * y / a->s->anti_a) / SDY + 1);
			insec.ray = mkray(a->camera, s_cord);
			insec.t = insec.ray.t_max;
			if (intersect(a->ss, &insec))
				effects(a, x / a->s->anti_a, y / a->s->anti_a,
					cont_c(a, insec, 1));
			else
				effects(a, x / a->s->anti_a, y / a->s->anti_a, a->s->sky_c);
		}
	}
}

t_trace			settrace(int s1, int s2, int e1, int e2)
{
	t_trace		t;

	t.startx = s1;
	t.starty = s2;
	t.endx = e1;
	t.endy = e2;
	return (t);
}

void			thread_trace(t_main *a)
{
	t_tracers	tracers;
	pthread_t	pth1;
	pthread_t	pth2;
	pthread_t	pth3;
	pthread_t	pth4;

	tracers.t1 = settrace(0, 0, SDX / 2, SDY + 1 / 2);
	tracers.t1.a = a;
	pthread_create(&pth1, NULL, &ray_trace_treaded, &tracers.t1);
	tracers.t2 = settrace(SDX / 2, 0, SDX, SDY / 2);
	tracers.t2.a = a;
	pthread_create(&pth2, NULL, &ray_trace_treaded, &tracers.t2);
	tracers.t3 = settrace(0, SDY / 2, SDX / 2, SDY);
	tracers.t3.a = a;
	pthread_create(&pth3, NULL, &ray_trace_treaded, &tracers.t3);
	tracers.t4 = settrace(SDX / 2, SDY / 2, SDX, SDY);
	tracers.t4.a = a;
	pthread_create(&pth4, NULL, &ray_trace_treaded, &tracers.t4);
	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);
	pthread_join(pth3, NULL);
	pthread_join(pth4, NULL);
}
