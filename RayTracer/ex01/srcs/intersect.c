/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test_user <test@student.42.ft>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:03:52 by test_user         #+#    #+#             */
/*   Updated: 2022/10/16 10:50:40 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

// Determine if ray intersect the sphere
// NOTE: working on squarred distances to avoid sqrt() computing
// l = Vector (sphere.center, ray.origin)
// tc = projection of l on ray.direction
// distsqr = square distance between sphere center and ray.closestPoint
int	intersect_ray_sphere(const t_Ray ray, const t_Sphere sphere)
{
	t_Vector3	l;
	float		tc;
	float		dist_sqr;

	l.x = sphere.center.x - ray.origin.x;
	l.y = sphere.center.y - ray.origin.y;
	l.z = sphere.center.z - ray.origin.z;
	tc = dot_product(l, ray.dir);
	if (sphere.radius <= 0.0f || tc < 0.0f)
		return (0);
	dist_sqr = (tc * tc) - (vector_sqrmagnitude(l));
	if (dist_sqr > sphere.radius * sphere.radius)
		return (0);
	return (1);
}

// Scalar product
float	dot_product(t_Vector3 a, t_Vector3 b)
{
	float	dot;

	dot = a.x * b.x;
	dot += a.y * b.y;
	dot += a.z * b.z;
	return (dot);
}

// Return the square magnitude of a vector
float	vector_sqrmagnitude(t_Vector3 vec)
{
	float	sqrmag;

	sqrmag = vec.x * vec.x;
	sqrmag += vec.y * vec.y;
	sqrmag += vec.z * vec.z;
	return (sqrmag);
}
