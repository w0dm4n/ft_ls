/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 00:19:45 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/18 00:22:33 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char		**new_dir(char **path, char *toadd)
{
	int		i;

	i = 0;
	while (path[i])
		i++;
	path[i] = ft_strdup(toadd);
	return (path);
}

void		recursive_if(char **path, char *folder, char *flags)
{
	int 			i;
	char			*real_path;
	struct stat		*file_stat;

	i = 0;
	real_path = ft_strnew(DEFAULT_BUFFER);
	while (path[i])
	{
		ft_bzero(real_path, DEFAULT_BUFFER);
		real_path = realpath(folder, real_path);
		real_path = ft_strcat(real_path, "/");
		real_path = ft_strcat(real_path, path[i]);
		real_path = ft_strcat(real_path, "/");
		if (!(file_stat = get_file_stat(path[i], file_stat, folder)))
			return ;
		ft_putstr(real_path);
		ft_putstr(":\n");
		print_recursive(get_specified_dir(real_path, flags), flags, real_path);
		free(file_stat);
		i++;
	}
	free(real_path);
}

void		print_recursive(char **files, char *flags, char *folder)
{
	char			**path;
	int				i;
	struct stat		*file_stat;
	int				boolean;

	if (!files || !files[0] || !ft_strlen(files[0]))
		return ;
	i = 0;
	boolean = 0;
	if (!(path = malloc(sizeof(char*) * ALL_RECURSIVE_POSSIBILITY)))
		return ;
	path = ft_set_null(path);
	while (files[i])
	{
		if (!(file_stat = get_file_stat(files[i], file_stat, folder)))
			return ;
		//FLAGS
		print_line(file_stat, flags, files, i);
		if (S_ISDIR(file_stat->st_mode) && files[i][0] != '.')
		{
			path = new_dir(path, files[i]);
			boolean++;
		}
		free(file_stat);
		i++;
	}
	free_files(files);
	if (boolean)
		recursive_if(path, folder, flags);
	free_files(path);
}
