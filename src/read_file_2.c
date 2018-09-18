/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:32:31 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 15:32:31 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int				p_str(int fd, t_main *a)
{
	t_plane		p;
	t_vector	col;

	if (getv(fd, &p.position) == -1)
		return (-1);
	if (getv(fd, &p.normal) == -1)
		return (-1);
	if (getv(fd, &col) == -1)
		return (-1);
	p.colour = makec(col.x, col.y, col.z);
	add_plane(a, p.position, p.normal, p.colour);
	return (1);
}

int				s_str(int fd, t_main *a)
{
	char		*s;
	t_sphere	sr;
	t_vector	col;

	if (getv(fd, &sr.centre) == -1)
		return (-1);
	get_next_line(fd, &s);
	if (ft_atof(s) < 1 || !ft_strlen(s))
		return (-1);
	sr.radius = ft_atof(s);
	if (getv(fd, &col) == -1)
		return (-1);
	sr.colour = makec(col.x, col.y, col.z);
	add_sphere(a, sr.centre, sr.radius, sr.colour);
	return (1);
}

int				pl_str(int fd, t_main *a)
{
	char		*s;
	t_vector	loc;
	double		itx;

	if (getv(fd, &loc) == -1)
		return (-1);
	get_next_line(fd, &s);
	if (ft_atof(s) < 1 || !ft_strlen(s))
		return (-1);
	itx = ft_atof(s);
	mkplight(a, loc, itx);
	return (1);
}

int				dl_str(int fd, t_main *a)
{
	char		*s;
	t_vector	dir;
	double		itx;

	if (getv(fd, &dir) == -1)
		return (-1);
	get_next_line(fd, &s);
	if (ft_atof(s) < 1 || !ft_strlen(s))
		return (-1);
	itx = ft_atof(s) / 100.0f;
	mkdlight(a, dir, itx);
	return (1);
}

int				cam_str(int fd, t_main *a)
{
	if (getv(fd, &a->camera->origin) == -1)
		return (-1);
	if (getv(fd, &a->camera->t) == -1)
		return (-1);
	if (getv(fd, &a->camera->upguide) == -1)
		return (-1);
	return (1);
}
