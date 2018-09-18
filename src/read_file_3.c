/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:32:38 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 15:33:41 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int				getv(int fd, t_vector *v)
{
	char		*s;
	char		**slt;
	int			nslt;

	get_next_line(fd, &s);
	slt = ft_strnsplit(s, ' ', &nslt);
	if (nslt != 3)
		return (-1);
	*v = makev(ft_atof(slt[0]), ft_atof(slt[1]), ft_atof(slt[2]));
	return (nslt);
}

static int		cld_str(int fd, t_main *a)
{
	char		*s;
	t_cylinder	cld;
	t_vector	col;

	if (getv(fd, &cld.centre) == -1)
		return (-1);
	if (getv(fd, &cld.dir) == -1)
		return (-1);
	get_next_line(fd, &s);
	if (ft_atof(s) < 1 || !ft_strlen(s))
		return (-1);
	cld.radius = ft_atof(s);
	get_next_line(fd, &s);
	if (ft_atof(s) < 1 || !ft_strlen(s))
		return (-1);
	cld.height = ft_atof(s);
	if (getv(fd, &col) == -1)
		return (-1);
	cld.colour = makec(col.x, col.y, col.z);
	add_cld(a, cld);
	return (1);
}

static int		cone_str(int fd, t_main *a)
{
	char		*s;
	t_cone		cld;
	t_vector	col;

	if (getv(fd, &cld.centre) == -1)
		return (-1);
	if (getv(fd, &cld.dir) == -1)
		return (-1);
	get_next_line(fd, &s);
	if (ft_atof(s) < 1 || !ft_strlen(s))
		return (-1);
	cld.angle = ft_atof(s);
	get_next_line(fd, &s);
	if (ft_atof(s) < 1 || !ft_strlen(s))
		return (-1);
	cld.height = ft_atof(s);
	if (getv(fd, &col) == -1)
		return (-1);
	cld.colour = makec(col.x, col.y, col.z);
	add_cone(a, cld);
	return (1);
}

int				cmd_read(int fd, t_main *a, char *s)
{
	int			cmd;

	cmd = ckstr(s);
	if (cmd == 1 && p_str(fd, a) == -1)
		return (-1);
	if (cmd == 2 && s_str(fd, a) == -1)
		return (-1);
	if (cmd == 3 && pl_str(fd, a) == -1)
		return (-1);
	if (cmd == 4 && dl_str(fd, a) == -1)
		return (-1);
	if (cmd == 5 && cam_str(fd, a) == -1)
		return (-1);
	if (cmd == 6 && cld_str(fd, a) == -1)
		return (-1);
	if (cmd == 7 && cone_str(fd, a) == -1)
		return (-1);
	if (cmd == 0)
	{
		ft_putendl(" is an incorrect command!");
		return (-1);
	}
	return (1);
}
