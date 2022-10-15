/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test_user <test@student.42.ft>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:39:07 by test_user         #+#    #+#             */
/*   Updated: 2022/10/15 21:05:16 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	main(void)
{
	int		height;
	int		width;
	t_Pixel	**pixels;
	int		i;

	height = 2;
	width = 3;
	i = 0;
	pixels = malloc(sizeof(t_Pixel *) * height);
	while (i < height)
	{
		pixels[i] = malloc(sizeof(t_Pixel) * width);
		i++;
	}
	pixels[0][0].color.red = 255;
	pixels[0][0].color.green = 0;
	pixels[0][0].color.blue = 0;
	pixels[0][1].color.red = 0;
	pixels[0][1].color.green = 255;
	pixels[0][1].color.blue = 0;
	pixels[0][2].color.red = 0;
	pixels[0][2].color.green = 0;
	pixels[0][2].color.blue = 255;
	pixels[1][0].color.red = 255;
	pixels[1][0].color.green = 255;
	pixels[1][0].color.blue = 0;
	pixels[1][1].color.red = 255;
	pixels[1][1].color.green = 255;
	pixels[1][1].color.blue = 255;
	pixels[1][2].color.red = 0;
	pixels[1][2].color.green = 0;
	pixels[1][2].color.blue = 0;
	save_ppm(width, height, pixels);
	i = 0;
	while (i < height)
	{
		free(pixels[i]);
		i++;
	}
	free(pixels);
	return (0);
}
