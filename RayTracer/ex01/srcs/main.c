/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test_user <test@student.42.ft>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:48:39 by test_user         #+#    #+#             */
/*   Updated: 2022/10/16 11:04:12 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

void	test_intersect00(void);
void	test_intersect01(void);
void	test_intersect02(void);

int	main(void)
{
	test_intersect00();
	test_intersect01();
	test_intersect02();
	return (0);
}

void	test_intersect00(void)
{
	t_Sphere	s;
	t_Ray		ray;

	s.center.x = 0;
	s.center.y = 0;
	s.center.z = 0;
	s.radius = 1;
	ray.origin.x = 0;
	ray.origin.y = -2;
	ray.origin.z = 0;
	ray.dir.x = 0;
	ray.dir.y = 1;
	ray.dir.z = 0;
	printf("Sphere:\torigin=[%f; %f; %f] ", s.center.x, s.center.y, s.center.z);
	printf("- radius=%f\n", s.radius);
	printf("Ray:\torigin=[%f; %f; %f] - dir=[%f; %f; %f]\n", ray.origin.x, \
			ray.origin.y, ray.origin.z, ray.dir.x, ray.dir.y, ray.dir.z);
	printf(">Intersect: expected=1\tres=%d\n\n", intersect_ray_sphere(ray, s));
}

void	test_intersect01(void)
{
	t_Sphere	s;
	t_Ray		ray;

	s.center.x = 0;
	s.center.y = 0;
	s.center.z = 0;
	s.radius = 1;
	ray.origin.x = 0;
	ray.origin.y = -2;
	ray.origin.z = 0;
	ray.dir.x = 0;
	ray.dir.y = -1;
	ray.dir.z = 0;
	printf("Sphere:\torigin=[%f; %f; %f] ", s.center.x, s.center.y, s.center.z);
	printf("- radius=%f\n", s.radius);
	printf("Ray:\torigin=[%f; %f; %f] - dir=[%f; %f; %f]\n", ray.origin.x, \
			ray.origin.y, ray.origin.z, ray.dir.x, ray.dir.y, ray.dir.z);
	printf(">Intersec: expected=0\tres=%d\n\n", intersect_ray_sphere(ray, s));
}

void	test_intersect02(void)
{
	t_Sphere	s;
	t_Ray		ray;

	s.center.x = 0;
	s.center.y = 0;
	s.center.z = 1;
	s.radius = 1;
	ray.origin.x = 0;
	ray.origin.y = 0;
	ray.origin.z = 0;
	ray.dir.x = 1;
	ray.dir.y = 1;
	ray.dir.z = 0;
	printf("Sphere:\torigin=[%f; %f; %f] ", s.center.x, s.center.y, s.center.z);
	printf("- radius=%f\n", s.radius);
	printf("Ray:\torigin=[%f; %f; %f] - dir=[%f; %f; %f]\n", ray.origin.x, \
			ray.origin.y, ray.origin.z, ray.dir.x, ray.dir.y, ray.dir.z);
	printf(">Intersect: expected=1\tres=%d\n\n", intersect_ray_sphere(ray, s));
}
