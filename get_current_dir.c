/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 01:50:36 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/14 01:52:01 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	**get_files_in_order(char **files, char **tmp, int i_maj)
{
	int		i;

	i = 0;
	while (files[i])
	{
		if (files[i][0] >= 'A' && files[i][0] <= 'Z')
		{
			tmp[i_maj] = files[i];
			i_maj++;
		}
		i++;
	}
	i = 0;
	while (files[i])
	{
		if (files[i][0] >= 'a' && files[i][0] <= 'z')
		{
			tmp[i_maj] = files[i];
			i_maj++;
		}
		i++;
	}
	return (tmp);
}

char	**range_byascii(char **files)
{
	char	**tmp;
	int		i;
	int		i_maj;

	i = 0;
	i_maj = 0;
	if (!(tmp = malloc(sizeof(char*) * MAX_FILES_PER_FOLDER)))
		return (NULL);
	while (files[i])
	{
		if (!(files[i][0] >= 'A' && files[i][0] <= 'Z')
			&& !(files[i][0] >= 'a' && files[i][0] <= 'z'))
		{
			tmp[i_maj] = files[i];
			i_maj++;
		}
		i++;
	}
	tmp = get_files_in_order(files, tmp, i_maj);
	free(files);
	return (tmp);
}

void	print_current_dir(char **files)
{
	int		i;

	i = 0;
	while (files[i])
	{
		ft_putstr(files[i]);
		ft_putstr("\n");
		i++;
	}
}

char	**modify_if_flags(char *flags, char **files)
{
	if (ft_strchr(flags, 'r'))
		files = reverse_array(files);
	return (files);
}

void	get_current_dir(char *flags, char *folder)
{
	DIR				*current_dir;
	char			**files;
	int				i;

	i = 0;
	if (!flags)
		if (!(flags = ft_strnew(1)))
			return ;
	current_dir = opendir(folder);
	if (current_dir == NULL)
		print_error(folder);
	if (!(files = malloc(sizeof(char*) * MAX_FILES_PER_FOLDER)))
		return ;
	files = ft_set_null(files);
	if (ft_strchr(flags, 'a'))
		files = read_with_hidden_files(files, current_dir);
	else
		files = read_without_hidden_files(files, current_dir);
	closedir(current_dir);
	files = range_byascii(files);
	files = modify_if_flags(flags, files);
	print_current_dir(files);
	free(files);
}
