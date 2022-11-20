/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:19:57 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/20 17:36:57 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/*Print les valeurs x, y, z du vecteur u*/
void	printv(t_vec3 u)
{
	printf("x:%f y:%f z:%f\n", u.x, u.y, u.z);
}

/*Résultat d'une multiplication des vecteurs u et v*/
double	dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

/*??????????????????*/
t_vec3	cross(t_vec3 u, t_vec3 v)
{
	t_vec3 new;

	new.x = u.y * v.z - u.z * v.y;
	new.y = u.z * v.x - u.x * v.z;
	new.z = u.x * v.y - u.y * v.x;
	return (new);
}

/*Crée un nouveau vecteur qui est la mutiplication de u par la constante t*/
t_vec3	unit_vector(t_vec3 v)
{
	return (divis(v, length(&v)));
}

/*Crée un nouveau vecteur avec des valeurs arbitraires*/
t_vec3	new_vec(double x, double y, double z)
{
	t_vec3 new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec3	max(t_vec3 v1, t_vec3 v2)
{
	if (length(&v1) > length(&v2))
		return (v1);
	else
		return (v2);	
}