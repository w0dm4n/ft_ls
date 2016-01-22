/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 00:28:37 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/15 00:28:47 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char		*get_group(struct stat *file_stat)
{
	struct group *gr;

	if (!(gr = (struct group*)malloc(sizeof(struct group))))
		return (NULL);
	gr = getgrgid(file_stat->st_gid);
	return (gr->gr_name);
}

char		*get_user(struct stat *file_stat)
{
	struct passwd *tmp;

	if (!(tmp = (struct passwd*)malloc(sizeof(struct passwd))))
		return (NULL);
	tmp = getpwuid(file_stat->st_uid);
	return (tmp->pw_name);
}

struct stat	*get_file_stat(char *name, struct stat *file_stat, char *folder)
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

char		*add_p(char *permissions, char to_add)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char*) * (ft_strlen(permissions) + 2))))
		return (NULL);
	while (permissions[i])
	{
		tmp[i] = permissions[i];
		i++;
	}
	tmp[i] = to_add;
	tmp[i + 1] = '\0';
	return (tmp);
}

char		*get_permissions(struct stat *file_stat)
{
	char	*p;

	if (!(p = (char*)malloc(sizeof(char*) * PERMISSIONS_BUFFER)))
		return (NULL);
	ft_bzero(p, PERMISSIONS_BUFFER);
	p = get_state(p, file_stat);
	return (p);
}
