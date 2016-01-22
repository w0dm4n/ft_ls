/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colored_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 01:38:13 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/21 01:38:20 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	print_char_with_color(char to_print, int color)
{
	if (!color)
		ft_putstr(COLOR_BLUE);
	else if (color == 1)
		ft_putstr(COLOR_PURPLE);
	else if (color == 2)
		ft_putstr(COLOR_YELLOW);
	else if (color == 3)
		ft_putstr(COLOR_GREEN);
	else if (color == 4)
		ft_putstr(COLOR_RED);
	else if (color == 5)
		ft_putstr(COLOR_LIGHT_RED);
	ft_putchar(to_print);
}

void	print_random_color_on_file_name(char *file_name)
{
	int		i;
	int		color;

	i = 0;
	color = 0;
	while (file_name[i])
	{
		if (color == 5)
			color = 0;
		print_char_with_color(file_name[i], color);
		color++;
		i++;
	}
	ft_putstr(COLOR_WHITE);
}

int		print_name_by_extension(char *file_name)
{
	int		ret;
	char	*extension;

	ret = 0;
	if (!(extension = get_file_extension(file_name)))
		return (-1);
	if (file_name[0] == '.')
	{
		ft_putstr(COLOR_LIGHT_RED);
		ft_putstr(file_name);
		ft_putstr(COLOR_WHITE);
		ret = 1;
	}
	if (!ft_strcmp(extension, "c") && ft_strchr(file_name, '.'))
	{
		print_random_color_on_file_name(file_name);
		ret = 1;
	}
	free(extension);
	return (ret);
}

int		print_name_by_permissions(char *permissions, char *file_name)
{
	int ret;

	ret = 0;
	if (permissions[0] == 'd')
	{
		ft_putstr(COLOR_YELLOW);
		ft_putstr(file_name);
		ft_putstr(COLOR_WHITE);
		ret++;
	}
	else if (permissions[0] == 'l')
	{
		ft_putstr(COLOR_PURPLE);
		ft_putstr(file_name);
		ft_putstr(COLOR_WHITE);
		ret++;
	}
	return (ret);
}
