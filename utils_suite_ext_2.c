/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_suite_ext_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 03:09:28 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/19 03:12:45 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		*reverse_int_array(int *array)
{
	int		i;
	int		i_2;
	int		*tmp;

	i = 0;
	i_2 = 0;
	while (array[i])
		i++;
	if (!(tmp = malloc(sizeof(int) * i)))
		return (NULL);
	i--;
	while (array[i])
	{
		tmp[i_2] = array[i];
		i_2++;
		i--;
	}
	return (tmp);
}

void	print_with_nl(char *to_print, char *flags)
{
	if (ft_strchr(flags, 'G'))
	{
		if (!print_name_by_extension(to_print))
			ft_putstr(to_print);
	}
	else
		ft_putstr(to_print);
	ft_putstr("\n");
}

char	*get_file_extension(char *file)
{
	char	*extension;
	int		i;
	int		extension_size;
	int		i_2;

	i_2 = 0;
	i = ft_strlen(file);
	while (file[i] != '.')
		i--;
	extension_size = (ft_strlen(file) - i);
	if (!(extension = malloc(sizeof(char) * extension_size)))
		return (NULL);
	i++;
	while (file[i])
	{
		extension[i_2] = file[i];
		i_2++;
		i++;
	}
	extension[i_2] = '\0';
	return (extension);
}
