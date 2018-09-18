#include "../headers/main.h"

void			mvcamup(t_main *a, int axis)
{
	t_vector	tmp;
	t_vector	tmp2;
	t_vector	tmp3;

	tmp = v_oper(a->camera->forward, NULL, cos(DEG_T_RAD * (5 * axis)), '*');
	tmp2 = v_oper(a->camera->up, NULL, sin(DEG_T_RAD * (5 * axis)), '*');
	tmp = v_oper(tmp, &tmp2, 0, '+');
	tmp2 = v_oper(a->camera->up, NULL, cos(DEG_T_RAD * (5 * axis)), '*');
	tmp3 = v_oper(a->camera->forward, NULL, sin(DEG_T_RAD * (5 * axis)), '*');
	a->camera->up = v_oper(tmp2, &tmp3, 0, '-');
	a->camera->forward = tmp;
}

void			mvcamfor(t_main *a, int axis)
{
	a->camera->origin = find_point(a->camera->origin, 
			a->camera->forward, 15 * axis);
}

void			mvcamright(t_main *a, int axis)
{
	t_vector	tmp;
	t_vector	tmp2;
	t_vector	tmp3;

	tmp = v_oper(a->camera->forward, NULL, cos(DEG_T_RAD * (5 * axis)), '*');
	tmp2 = v_oper(a->camera->right, NULL, sin(DEG_T_RAD * (5 * axis)), '*');
	tmp = v_oper(tmp, &tmp2, 0, '+');
	tmp2 = v_oper(a->camera->right, NULL, cos(DEG_T_RAD * (5 * axis)), '*');
	tmp3 = v_oper(a->camera->forward, NULL, sin(DEG_T_RAD * (5 * axis)), '*');
	a->camera->right = v_oper(tmp2, &tmp3, 0, '-');
	a->camera->forward = tmp;
}

void			mvcamera(int keycode, t_main *a, int shift_down)
{
	if (keycode == SDLK_UP && shift_down)
		mvcamup(a, 1);
	if (keycode == SDLK_DOWN && shift_down)
		mvcamup(a, -1);
	if (keycode == SDLK_UP && !shift_down)
		mvcamfor(a, 1);
	if (keycode == SDLK_DOWN && !shift_down)
		mvcamfor(a, -1);
	if (keycode == SDLK_RIGHT)
		mvcamright(a, 1);
	if (keycode == SDLK_LEFT)
		mvcamright(a, -1);
}
