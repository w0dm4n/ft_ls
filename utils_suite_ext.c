/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_suite_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 23:43:32 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/16 23:47:12 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int			get_file_nbr(char **file_n_folder)
{
	struct stat		*file_stat;
	int				i;
	int				nbr;

	i = 0;
	nbr = 0;
	while (file_n_folder[i])
	{
		if (!(file_stat = get_file_stat(file_n_folder[i], file_stat, ".")))
			return (-1);
		if (!S_ISDIR(file_stat->st_mode))
			nbr++;
		i++;
		free(file_stat);
	}
	return (nbr);
}

char		**set_dir_on_array(char **tmp, char **old, int index)
{
	struct stat		*file_stat;
	int				i;

	i = 0;
	while (old[i])
	{
		if (!(file_stat = get_file_stat(old[i], file_stat, ".")))
			return (NULL);
		if (S_ISDIR(file_stat->st_mode))
		{
			tmp[index] = ft_strdup(old[i]);
			index++;
		}
		i++;
		free(file_stat);
	}
	free(old);
	return (tmp);
}

void		just_print_files(char **files, char *flags, char *folder)
{
	struct stat	*f_t;
	int			i;

	if (!files || !files[0] || !ft_strlen(files[0]))
		return ;
	i = 0;
	while (files[i])
	{
		if (ft_strchr(flags, 'G'))
		{
			if (!(f_t = get_file_stat(files[i], f_t, folder)))
				return ;
			if (!print_name_by_extension(files[i]))
				if (!print_name_by_permissions(get_permissions(f_t), files[i]))
					ft_putstr(files[i]);
			free(f_t);
		}
		else
			ft_putstr(files[i]);
		ft_putstr("\n");
		i++;
	}
}

void		free_files(char **files)
{
	int	i;

	if (!files || !files[0] || !ft_strlen(files[0]))
		return ;
	i = 0;
	while (files[i])
	{
		if (files[i])
			free(files[i]);
		i++;
	}
}

struct stat	*get_file_lstat(char *name, struct stat *file_stat, char *folder)
{
	struct stat *tmp;
	char		*full_path;

	file_stat = NULL;
	if (!(tmp = (struct stat*)malloc(sizeof(struct stat))))
		return (NULL);
	if (!ft_strcmp(folder, "."))
	{
		if (lstat(name, tmp) < 0)
			return (NULL);
	}
	else
	{
		if (!(full_path = malloc(sizeof(char) * DEFAULT_BUFFER)))
			return (NULL);
		ft_bzero(full_path, DEFAULT_BUFFER);
		full_path = ft_strcat(full_path, folder);
		full_path = ft_strcat(full_path, "/");
		full_path = ft_strcat(full_path, name);
		if (lstat(full_path, tmp) < 0)
			return (NULL);
		free(full_path);
	}
	return (tmp);
}
