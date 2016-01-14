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

char	**range_byascii(char **files)
{
	int 	i;
	char	*tmp;

	i = 0;
	while (files[i])
	{
		if (files[i] && files[i + 1])
		{
			while (files[i][0] < files[i + 1][0])
			{
				tmp = files[i];
				files[i] = files[i + 1];
				files[i + 1] = tmp;
			}
		}
		i++;
	}
	return (files);
}

void	get_current_dir(void)
{
	DIR				*current_dir;
	struct dirent	*files_info;
	int				i;
	char			**files;

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
	i = 0;
	files = range_byascii(files);
	while (files[i])
	{
		ft_putstr(files[i]);
		ft_putstr("\n");
		i++;
	}
	free(files);
}
