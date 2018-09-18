/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:28:02 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 08:28:03 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

double			ft_clampf(double min, double max, double n)
{
	if (n > max)
		return (max);
	if (n < min)
		return (min);
	return (n);
}
