/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test_user <test@student.42.ft>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:34:48 by test_user         #+#    #+#             */
/*   Updated: 2022/10/15 21:25:00 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	save_ppm(int width, int height, t_Pixel **pixels)
{
	int		fd;
	char	*filename;
	char	*content;
	mode_t	mode;

	filename = "img.ppm";
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Image can't be open.\n", 21);
		return ;
	}
	content = generate_content(width, height, pixels);
	if (content == NULL)
		write(STDERR_FILENO, "Malloc fail.\n", 13);
	else
	{
		write(fd, content, ft_strlen(content));
		free(content);
	}
	close(fd);
}

char	*generate_content(int w, int h, t_Pixel **pixels)
{
	char	*content;
	char	*pixels_c;
	char	*nb;
	int		len;

	len = get_content_len(w, h, pixels);
	content = malloc (sizeof(char) * len + 1);
	if (content == NULL)
		return (NULL);
	content[0] = 0;
	content = ft_strcat(content, "P3\n");
	nb = ft_itoa(h);
	content = ft_strcat(content, ft_strcat(nb, " "));
	free(nb);
	nb = ft_itoa(w);
	content = ft_strcat(content, ft_strcat(nb, "\n"));
	free(nb);
	content = ft_strcat(content, "255\n\n");
	pixels_c = loop_pixels(w, h, pixels, len - ft_strlen(content));
	if (pixels_c == NULL)
		return (NULL);
	ft_strcat(content, pixels_c);
	free(pixels_c);
	return (content);
}

char	*loop_pixels(int w, int h, t_Pixel **pixels, int len)
{
	char	*content;
	int		i;
	int		j;

	content = malloc (sizeof(char) * len + 1);
	if (content == NULL)
		return (NULL);
	content[0] = 0;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			content = pixel_colors_tostr(pixels[i][j], content);
			j++;
		}
		i++;
	}
	return (content);
}

int	get_content_len(int w, int h, t_Pixel **pixels)
{
	int	len;
	int	i;
	int	j;

	len = 3;
	len += get_int_len(w) + 1;
	len += get_int_len(h) + 1;
	len += ft_strlen("255\n\n");
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			len += get_int_len(pixels[i][j].color.red) + 1;
			len += get_int_len(pixels[i][j].color.green) + 1;
			len += get_int_len(pixels[i][j].color.blue) + 1;
			j++;
		}
		i++;
	}
	return (len);
}
