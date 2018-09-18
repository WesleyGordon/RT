/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 09:45:38 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 15:36:19 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int		alloc_buf(t_main *a)
{
	int i;

	i = -1;
	a->s_buffer = (int **)malloc(sizeof(int *)
	* a->s->screen_d.y * a->s->anti_a);
	ft_bzero(a->s_buffer, sizeof(a->s_buffer));
	while (++i < a->s->screen_d.y * a->s->anti_a)
	{
		if ((a->s_buffer[i] = (int *)malloc(sizeof(int) *
						a->s->screen_d.x * a->s->anti_a)) == NULL)
			return (-1);
		ft_bzero(a->s_buffer[i], sizeof(a->s_buffer[i]));
	}
	return (0);
}
