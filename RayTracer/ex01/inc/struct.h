/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test_user <test@student.42.ft>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:44:16 by test_user         #+#    #+#             */
/*   Updated: 2022/10/16 10:47:07 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_Vector3 {
	float	x;
	float	y;
	float	z;
}	t_Vector3;

typedef struct s_Color {
	int	red;
	int	green;
	int	blue;
}	t_Color;

typedef struct s_Ray {
	t_Vector3	origin;
	t_Vector3	dir;
}	t_Ray;

typedef struct s_Sphere {
	t_Vector3	center;
	float		radius;
	t_Color		col;
}	t_Sphere;

int		intersect_ray_sphere(const t_Ray ray, const t_Sphere sphere);
float	dot_product(t_Vector3 a, t_Vector3 b);
float	vector_sqrmagnitude(t_Vector3 vec);

#endif
