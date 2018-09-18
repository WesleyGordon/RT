/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <gsferopo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:50:10 by gsferopo          #+#    #+#             */
/*   Updated: 2017/10/01 17:07:49 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "main.h"
# include "ray.h"
# include "proto.h"
# include "shapes.h"
# include "vectors.h"

int			p_str(int fd, t_main *a);
int			s_str(int fd, t_main *a);
int			pl_str(int fd, t_main *a);
int			dl_str(int fd, t_main *a);
int			cam_str(int fd, t_main *a);
int			getv(int fd, t_vector *v);
int			ckstr(char *s);
int			cmd_read(int fd, t_main *a, char *s);
void		mvcamera(int keycode, t_main *a, int shift_down);
void		thread_trace(t_main *a);
void		effects(t_main *a, double x, double y, int c);
void		print_coord(t_main *a);
t_vector	v_oper_add(t_vector v1, t_vector *v2, double n, char o);
t_vector	cone_norm(t_insec insec);
t_vector	cld_norm(t_insec insec);
t_vector	find_point(t_vector start, t_vector vect, double distance);
void		spawn_obj(t_main *a, char obj);
double		c_spec(t_shapeset *ss, t_vector v1, t_insec insec, int lsrc);
double		c_shade(t_insec insec, t_shapeset *ss, int lsrc, t_vector cv);
t_vector	v_oper_add(t_vector v1, t_vector *v2, double n, char o);
int			n_does_intersect(t_cone n, t_ray ray);
int			c_does_intersect(t_cylinder c, t_ray ray);
t_colour	makec255(double r, double g, double b);
double		c_shade(t_insec insec, t_shapeset *ss, int lsrc, t_vector cv);
void		add_cone(t_main *a, t_cone c);
int			n_intersect(t_cone n, t_insec *int_r);
t_cone		mkcone(t_point centre, t_vector dir, t_vvector ah, t_colour colour);
t_vector	refract(t_vector i, t_vector n, double ior);
double		get_closest(double t1, double t2);
double		c_ls(t_shapeset *ss, t_vector v1, t_insec insec);
double		cylinder_equation(t_cylinder *cld, t_ray *ray);
double		dist(double x1, double y1, double x2, double y2);
double		ft_clampf(double min, double max, double n);
double		gaussian(double n);
double		line_len(t_vector v1, t_vector v2);
double		p_does_insect(t_plane p, t_ray ray);
double		positive_smallest(double a, double b);
double		s_does_insect(t_sphere s, t_ray ray);
double		solve_quadratic(double a, double b, double c);
double		sqr(double n);
double		v_dot(t_vector v1, t_vector v2);
double		v_len(t_vector v);
double		v_len_sqr(t_vector v);
double		vv_dot(t_vector v1, t_vector v2);
int			alloc_buf(t_main *a);
int			does_intersec(t_insec s);
int			add_col(int c, double n);
int			c_intersect(t_cylinder c, t_insec *int_r);
int			cartoonify(int n, int base);
int			chkcol_neg(t_colour c);
int			combine_rgb(t_colour c);
int			combine_rgbm(t_colour c);
int			cont_c(t_main *a, t_insec insec, int rem);
int			does_intersect(t_shapeset *ss, t_ray ray);
int			intersect(t_shapeset *ss, t_insec *ray);
int			loop_hook(t_main *a);
int			min_cols(int c1, int c2);
int			mix_colors(int c1, int c2, double a);
int			mul_col(int c, double n);
int			p_intersect(t_plane p, t_insec *int_r);
int			read_file(t_main *a, char **av);
int			s_intersect(t_sphere s, t_insec *int_r);
t_colour	c_reflection(t_main *a, t_insec insec, int depth);
t_colour	makec(double r, double g, double b);
t_colour	mkcolour(double r, double g, double b);
t_colour	splitc(int n);
t_cylinder	mkcylinder(t_point centre, t_vector dir,
			t_vvector rh, t_colour colour);
t_insec		cpyi(t_insec s);
t_insec		seti(t_ray ray);
t_insec		makei();
t_perc		persc(t_perc cam, t_main a);
t_plane		mkplane(t_point position, t_vector normal, t_colour colour);
t_point		calc_p(t_ray r, double t);
t_ray		setr(t_point origin, t_vector direction, double t_max);
t_ray		mkray(t_perc *c, t_vvector point);
t_ray		mkrayv(t_vector v1, t_vector v2);
t_sphere	mksphere(t_point centre, double radius, t_colour colour);
t_vector	clearv();
t_vector	cpyv(t_vector v);
t_vector	get_normal(t_insec insec);
t_vector	makev(double x, double y, double z);
t_vector	makev_f(double f);
t_vector	normv(t_vector v);
t_vector	normv_cpy(t_vector v);
t_vector	reflect(t_vector v1, t_vector v2);
t_vector	v_cross(t_vector v1, t_vector v2);
t_vector	v_neg(t_vector v);
t_vector	v_oper(t_vector v1, t_vector *v2, double n, char o);
t_vvector	vvcpy(t_vvector v);
t_vvector	vvmake(double u, double v);
t_vvector	vvmake_f(double f);
void		dither(t_main *a);
void		colour_code(t_shapeset *ss, t_vector v1, t_insec insec,
			double dmti[4]);
void		add_cld(t_main *a, t_cylinder c);
void		add_plane(t_main *a, t_vector pos, t_vector rot, t_colour c);
void		add_sphere(t_main *a, t_vector pos, double size, t_colour c);
void		addlight(t_shapeset *ss, t_lsrc *lsrc);
void		addshape(t_shapeset *ss, t_shapes *s);
void		clear_vvector(t_vvector *v);
void		draw_dot(t_vvector sd, int **buff, t_vvector v, int col);
void		key_hook(int keycode, t_main *a);
void		map_world(t_main *a);
void		mkdlight(t_main *a, t_vector dir, double ix);
void		mkplight(t_main *a, t_vector loc, double ix);
void		progress(t_main *a, int n);
void		put_pixel(t_main *a);
void		*ray_trace_treaded(void *v);
void		ray_tracer(t_main *a);
t_param		mkdparam(t_colour c, double t, double r);
int			read_m_file(t_main *a, char **av);
int			read_s_file(t_main *a);
int			getcls(t_shapeset *ss, t_vector v);

#endif
