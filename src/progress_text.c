/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:28:42 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 17:33:31 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

void				ft_putbs(unsigned int n)
{
	while (n-- > 0)
		ft_putstr("\x08");
}

void				progress(t_main *a, int n)
{
	static double	p = -1;
	static double	counter = 0;
	double			t;

	counter++;
	t = SDX * SDY * sqr(a->s->anti_a);
	if (n)
	{
		p = -1;
		counter = 0;
	}
	else if (round((counter / t) * 100) != p)
	{
		p = round((counter / t) * 100);
		if ((int)p > 100)
			return ;
		if ((int)p > 0 && (a->s->shwbar == 0))
			ft_putbs(ft_numlen((int)p) + 3);
		if (!a->s->shwbar)
			ft_putstr(ft_strjoin(ft_itoa((int)p), "%"));
		else if ((int)p % 2)
			ft_putchar('-');
	}
}
