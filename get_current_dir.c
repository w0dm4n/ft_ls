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
	flags = NULL;
	// ADD MODIFICATIONS !
	return (files);
}

void	get_current_dir(char *flags)
{
	DIR				*current_dir;
	struct dirent	*files_info;
	char			**files;
	int				i;

	i = 0;
	current_dir = opendir(".");
	if (current_dir == NULL)
		print_error(".");
	if (!(files = malloc(sizeof(char*) * MAX_FILES_PER_FOLDER)))
		return ;
	files = ft_set_null(files);
	while ((files_info = readdir(current_dir)) != NULL)
	{
		if (files_info->d_name[0] != '.')
		{
			files[i] = files_info->d_name;
			i++;
		}
	}
	closedir(current_dir);
	files = range_byascii(files);
	files = modify_if_flags(flags, files);
	print_current_dir(files);
	free(files);
}
