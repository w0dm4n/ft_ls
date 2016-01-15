/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specified_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 22:29:15 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/14 22:30:20 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	**read_with_hidden_files(char **files, DIR *current_dir)
{
	struct dirent	*files_info;
	int				i;

	i = 0;
	while ((files_info = readdir(current_dir)) != NULL)
	{
		files[i] = files_info->d_name;
		i++;
	}
	return (files);
}

char	**read_without_hidden_files(char **files, DIR *current_dir)
{
	struct dirent	*files_info;
	int				i;

	i = 0;
	while ((files_info = readdir(current_dir)) != NULL)
	{
		if (files_info->d_name[0] != '.')
		{
			files[i] = files_info->d_name;
			i++;
		}
	}
	return (files);
}

char	**get_specified_dir(char *dir, char *all_flags)
{
	char			**files;
	DIR				*current_dir;

	current_dir = opendir(dir);
	if (current_dir == NULL)
		print_error(dir);
	if (!(files = malloc(sizeof(char*) * MAX_FILES_PER_FOLDER)))
		return (NULL);
	files = ft_set_null(files);
	if (ft_strchr(all_flags, 'a'))
		files = read_with_hidden_files(files, current_dir);
	else
		files = read_without_hidden_files(files, current_dir);
	files = range_byascii(files);
	closedir(current_dir);
	return (files);
}
