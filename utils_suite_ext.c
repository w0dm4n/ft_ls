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

void		just_print_files(char **files)
{
	int		i;

	i = 0;
	// SEGV WITH ./ft_ls test dir
	while (files[i])
	{
		ft_putstr(files[i]);
		ft_putstr("\n");
		i++;
	}
}

void		free_files(char **files)
{
	int	i;

	i = 0;
	while (files[i])
	{
		if (files[i])
			free(files[i]);
		i++;
	}
}
