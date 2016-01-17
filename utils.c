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

char 		*get_user(struct stat *file_stat)
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
	size_t		size;

	size = (ft_strlen(folder + 1) + ft_strlen(name + 1) + 10);
	file_stat = NULL;
	if (!(tmp = (struct stat*)malloc(sizeof(struct stat))))
		return (NULL);
	if (!ft_strcmp(folder, "."))
	{
		if (stat(name, tmp) < 0)
			return (NULL);
	}
	else
	{
		if (!(full_path = malloc(sizeof(char) * size)))
			return (NULL);
		full_path = ft_strcat(full_path, folder);
		full_path = ft_strcat(full_path, "/");
		full_path = ft_strcat(full_path, name);
		if (stat(full_path, tmp) < 0)
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
	(S_ISDIR(file_stat->st_mode)) ? (p = add_p(p, 'd')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IRUSR) ? (p = add_p(p, 'r')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IWUSR) ? (p = add_p(p, 'w')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IXUSR) ? (p = add_p(p, 'x')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IRGRP) ? (p = add_p(p, 'r')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IWGRP) ? (p = add_p(p, 'w')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IXGRP) ? (p = add_p(p, 'x')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IROTH) ? (p = add_p(p, 'r')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IWOTH) ? (p = add_p(p, 'w')) : (p = add_p(p, '-'));
	(file_stat->st_mode & S_IXOTH) ? (p = add_p(p, 'x')) : (p = add_p(p, '-'));
	return (p);
}