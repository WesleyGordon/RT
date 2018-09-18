/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 13:47:33 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 13:51:13 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void			print_cam(t_main *a)
{
	ft_putendl("Camera:");
	ft_printf(6, "Up: ", ft_itoa((int)a->camera->up.x), " ",
	ft_itoa((int)a->camera->up.y), " ", ft_itoa((int)a->camera->up.z));
	ft_printf(6, "Right: ", ft_itoa((int)a->camera->right.x),
	" ", ft_itoa((int)a->camera->right.y), " ",
	ft_itoa((int)a->camera->right.z));
}

void			print_sphere(t_sphere sphere, int i)
{
	ft_printf(13, "Sphere [", ft_itoa(i), "] ",
	ft_itoa((int)sphere.centre.x), " ", ft_itoa((int)sphere.centre.y), " ",
	ft_itoa((int)sphere.centre.z), " [", ft_itoa((int)sphere.radius),
	"] RGB[", ft_itoa(combine_rgbm(sphere.colour)), "]");
}

void			print_cld(t_cylinder cld, int i)
{
	ft_printf(15, "Cylinder [", ft_itoa(i), "] ",
	ft_itoa((int)cld.centre.x), " ",
	ft_itoa((int)cld.centre.y), " ",
	ft_itoa((int)cld.centre.z), " [",
	ft_itoa((int)cld.radius), "] [",
	ft_itoa((int)cld.height), "] RGB[",
	ft_itoa(combine_rgbm(cld.colour)), "]");
}

void			print_lit(t_lsrc l, int i)
{
	ft_printf(11, "Light [", ft_itoa(i), "] ",
	ft_itoa((int)l.origin.x),
	" ", ft_itoa((int)l.origin.y),
	" ", ft_itoa((int)l.origin.z),
	" [", ft_itoa((int)l.intensity), "]");
}

void			print_coord(t_main *a)
{
	int			shp;
	int			lgt;
	int			i;
	t_shapes	*curshp;

	shp = a->ss->shapen;
	lgt = a->ss->lightn;
	i = -1;
	print_cam(a);
	while (++i < shp && ((curshp = a->ss->shapes[i]) != NULL))
	{
		if (curshp->contents == 's')
			print_sphere(curshp->sphere, i);
		if (curshp->contents == 'c')
			print_cld(curshp->cylinder, i);
	}
	i = -1;
	while (++i < lgt + 1)
		print_lit(*a->ss->lightsrc[i], i);
}
