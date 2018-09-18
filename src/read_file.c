/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:51:20 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 16:09:34 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int				ckstr(char *s)
{
	if (ft_strstr(s, "plane") != NULL)
		return (1);
	if (ft_strstr(s, "sphere") != NULL)
		return (2);
	if (ft_strstr(s, "plight") != NULL)
		return (3);
	if (ft_strstr(s, "dlight") != NULL)
		return (4);
	if (ft_strstr(s, "camera") != NULL)
		return (5);
	if (ft_strstr(s, "cylinder") != NULL)
		return (6);
	if (ft_strstr(s, "cone") != NULL)
		return (7);
	return (0);
}

int				read_m_file(t_main *a, char **av)
{
	char		*s;
	int			i;
	int			fd;

	(av)++;
	ft_putendl(*av);
	if ((fd = open(*av, O_RDONLY)) == -1)
		return (-1);
	i = 0;
	while (get_next_line(fd, &s))
	{
		write(1, s, ft_strlen(s) - 1);
		i++;
		if (cmd_read(fd, a, s) == -1)
			return (i);
		ft_putendl(" added successfully!");
	}
	return (0);
}

void			put_default(void)
{
	ft_putendl("No setting file found or theres an error");
	ft_putendl("Please create one these parameters as default:");
	ft_putendl("Seperate them with tabs");
	ft_putendl("THREAD		1");
	ft_putendl("SAVEIMG		1");
	ft_putendl("SKY		SKYBLUE");
	ft_putendl("FOV		70");
	ft_putendl("AMBIENCE	15");
	ft_putendl("ANTI_A		1");
	ft_putendl("REFDEPTH	1");
	ft_putendl("EFFECTS		<string goes here [cradsg]>");
	ft_putendl("SCREENX		500");
	ft_putendl("SCREENY		500");
	ft_putendl("SHWBAR		0");
	exit(-1);
}

void			read_p2(t_main *a, char **slt)
{
	if (ft_strcmp(slt[0], "SKY") == 0)
		a->s->sky_c = ft_atoi_base(slt[1], 16);
	if (ft_strcmp(slt[0], "FOV") == 0)
		a->s->fov = ft_atof(slt[1]);
	if (ft_strcmp(slt[0], "AMBIENCE") == 0)
		a->s->amb = ft_atof(slt[1]) / 100.0;
	if (ft_strcmp(slt[0], "ANTI_A") == 0)
		a->s->anti_a = ft_atof(slt[1]);
	if (ft_strcmp(slt[0], "REFDEPTH") == 0)
		a->s->rdepth = ft_atof(slt[1]);
	if (ft_strcmp(slt[0], "EFFECTS") == 0)
		a->s->effects = slt[1];
	if (ft_strcmp(slt[0], "SCREENX") == 0)
		a->s->screen_d.x = ft_atof(slt[1]);
	if (ft_strcmp(slt[0], "SCREENY") == 0)
		a->s->screen_d.y = ft_atof(slt[1]);
	if (ft_strcmp(slt[0], "SHWBAR") == 0)
		a->s->shwbar = ft_atof(slt[1]);
	if (ft_strcmp(slt[0], "SAVEIMG") == 0)
		a->s->svimg = ft_atof(slt[1]);
	if (ft_strcmp(slt[0], "THREAD") == 0)
		a->s->tread = ft_atoi(slt[1]);
}

int				read_s_file(t_main *a)
{
	int		fd;
	int		n;
	int		i;
	char	*str;
	char	**slt;

	i = 0;
	ft_putendl("\033[0;33m--- READING SETTINGS ---");
	if ((fd = open("./settings.g", O_RDONLY)) == -1)
		put_default();
	a->s = (t_settings *)malloc(sizeof(t_settings));
	while (get_next_line(fd, &str))
	{
		i++;
		slt = ft_strnsplit(str, '\t', &n);
		if (n != 2)
			put_default();
		read_p2(a, slt);
	}
	if (i != 11)
		put_default();
	ft_putendl("\033[0;33m--- READ SETTINGS ---");
	return (1);
}
