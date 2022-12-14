/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/12/14 16:46:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_pointer(int (*hit[8])(t_record *rec, t_ray r, t_vec2 limit, t_point light))
{
	hit[SP] = &hit_sphere;
	hit[L] = &hit_light;
	hit[PL] = &hit_plane;
	hit[CY] = &hit_cylinder;
	hit[CE] = &hit_circle;	
}

int	hit_global(t_ray r, t_record *rec, t_point light)
{
	t_hit_lst	*list;
	t_record	rec_tmp;
	t_vec2		limit;
	int			hit_any;
	int 		(*hit[8])(t_record *rec, t_ray r, t_vec2 limit, t_point light);
	
	init_pointer(hit);
	limit.x = 0;
	limit.y = DBL_MAX;
	hit_any = 0;
	list = get_hit(NULL, 0);
	while (list)
	{
		rec_tmp.closest = list->object;
		rec_tmp.type = 0;
		if (list->type != L && hit[list->type](&rec_tmp, r, limit, light))
		{
			if (rec_tmp.t < limit.y)
			{
				hit_any = 1;
				limit.y = rec_tmp.t;
				*rec = rec_tmp;
				rec->obj_id = list->id;
			}
		}
		list = list->next;
	}
	if (!hit_any)
		return (0);
	return (1);
}
