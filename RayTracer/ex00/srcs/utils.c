/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test_user <test@student.42.ft>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:36:32 by test_user         #+#    #+#             */
/*   Updated: 2022/10/15 21:16:50 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	d;
	int	s;

	d = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s])
		dest[d++] = src[s++];
	dest[d] = 0;
	return (dest);
}

int	get_int_len(int nb)
{
	int				len;
	unsigned int	num;

	len = 1;
	num = nb;
	if (nb < 0)
	{
		len++;
		num = -nb;
	}
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	int				i;
	unsigned int	num;
	char			*buffer;

	buffer = malloc(sizeof(int) * get_int_len(nb) + 1);
	if (buffer == NULL)
		return (NULL);
	i = get_int_len(nb);
	num = nb;
	if (nb < 0)
	{
		num = -nb;
		buffer[0] = '-';
	}
	buffer[i] = 0;
	buffer[i - 1] = '0';
	while (num > 0)
	{
		i--;
		buffer[i] = num % 10 + '0';
		num /= 10;
	}
	return (buffer);
}

char	*pixel_colors_tostr(t_Pixel pixel, char *dest)
{
	char	*c;

	c = ft_itoa(pixel.color.red);
	dest = ft_strcat(dest, c);
	free(c);
	dest = ft_strcat(dest, " ");
	c = ft_itoa(pixel.color.green);
	dest = ft_strcat(dest, c);
	free(c);
	dest = ft_strcat(dest, " ");
	c = ft_itoa(pixel.color.blue);
	dest = ft_strcat(dest, c);
	free(c);
	dest = ft_strcat(dest, "\n");
	return (dest);
}
