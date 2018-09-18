/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:48:56 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 16:49:00 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "ray.h"
# include "proto.h"
# include "shapes.h"
# include "vectors.h"
# include "time.h"

# include <SDL2/SDL.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <pthread.h>
# include <semaphore.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define SDX		a->s->screen_d.x
# define SDY		a->s->screen_d.y
# define GREEN		0x0000FF00
# define RED		0x00FF0000
# define BLUE		0x000000FF
# define WHITE		0x00FFFFFF
# define BLACK		0x00000000
# define CYAN		0x7fffc
# define SKYBLUE	0x008bfe
# define DEG_T_RAD	2 * M_PI / 180
# define RAY_T_MIN	0.0001f
# define RAY_T_MAX	INFINITY

#endif
