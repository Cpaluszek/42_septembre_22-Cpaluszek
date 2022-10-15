/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test_user <test@student.42.ft>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:37:51 by test_user         #+#    #+#             */
/*   Updated: 2022/10/15 21:17:42 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define HEADER_LEN = 3

typedef struct s_Color {
	int	red;
	int	green;
	int	blue;
}	t_Color;

typedef struct s_Pixel {
	t_Color	color;
}	t_Pixel;

void	save_ppm(int width, int height, t_Pixel **pixels);
char	*generate_content(int w, int h, t_Pixel **pixels);
char	*loop_pixels(int w, int h, t_Pixel **pixels, int len);
char	*pixel_colors_tostr(t_Pixel pixel, char *dest);
int		get_content_len(int w, int h, t_Pixel **pixels);
int		get_int_len(int nb);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *s);
char	*ft_itoa(int nb);

#endif
