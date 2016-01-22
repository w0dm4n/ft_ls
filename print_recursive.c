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

void		print_total(char **files, char *flags, char *folder)
{
	int				blocks_size;
	struct stat		*file_stat;

	blocks_size = 0;
	file_stat = NULL;
	if (!check_l_or_1(flags))
	{
		blocks_size = get_total_blocks(files, file_stat, folder);
		if (blocks_size > 0 || ft_strchr(flags, 'a') || files[0])
		{
			ft_putstr("total ");
			ft_putnbr(blocks_size);
			ft_putstr("\n");
		}
	}
}

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
	int				i;
	char			*rl;
	struct stat		*file_stat;

	i = 0;
	rl = ft_strnew(DEFAULT_BUFFER);
	while (path[i])
	{
		ft_bzero(rl, DEFAULT_BUFFER);
		rl = realpath(folder, rl);
		rl = ft_strcat(rl, "/");
		rl = ft_strcat(rl, path[i]);
		rl = ft_strcat(rl, "/");
		if (!(file_stat = get_file_stat(path[i], file_stat, folder)))
			return ;
		ft_putstr(rl);
		ft_putstr(":\n");
		print_recursive(get_specified_dir(rl, flags), flags, rl, 0);
		free(file_stat);
		i++;
	}
	free(rl);
	free_files(path);
}

void		print_by_flags(struct stat *f_stat, char *flags, char **f, int i)
{
	if (!ft_strcmp(flags, "R"))
		print_with_nl(f[i], flags);
	else if (ft_strchr(flags, '1'))
	{
		if (check_l_or_1(flags))
		{
			ft_putstr(f[i]);
			ft_putstr("\n");
		}
		else
		{
			if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')
				|| ft_strchr(flags, 'o'))
				print_line(f_stat, flags, f, i);
		}
	}
	else
	{
		if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')
			|| ft_strchr(flags, 'o'))
			print_line(f_stat, flags, f, i);
		else
			print_with_nl(f[i], flags);
	}
}

void		print_recursive(char **files, char *flags, char *folder, int i)
{
	char			**path;
	struct stat		*file_stat;
	int				boolean;

	if (!files || !files[0] || !ft_strlen(files[0]))
		return ;
	boolean = 0;
	if (!(path = malloc(sizeof(char*) * ALL_RECURSIVE_POSSIBILITY)))
		return ;
	path = ft_set_null(path);
	print_total(files, flags, folder);
	while (files[i])
	{
		if (!(file_stat = get_file_stat(files[i], file_stat, folder)))
			return ;
		print_by_flags(file_stat, flags, files, i);
		if (S_ISDIR(file_stat->st_mode) && files[i][0] != '.' && (boolean += 1))
			path = new_dir(path, files[i]);
		free(file_stat);
		i++;
	}
	ft_putstr("\n");
	free_files(files);
	(boolean) ? recursive_if(path, folder, flags) : free_files(path);
}
