/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_suite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 01:50:27 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/15 01:51:28 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char		**range_byfilenfolder(char **file_n_folder)
{
	return (file_n_folder);
}

int			check_l_or_1(char *flags)
{
	int i;
	int l_pos;
	int one_pos;

	i = 0;
	l_pos = 0;
	one_pos = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			l_pos = i;
		if (flags[i] == '1')
			one_pos = i;
		i++;
	}
	if (ft_strchr(flags, '1') && !ft_strchr(flags, 'l'))
		return (1);
	if (l_pos < one_pos)
		return (1);
	else
		return (0);
}

int			*initialise_array(int *array)
{
	int i;

	i = 0;
	if (!(array = (int*)malloc(sizeof(int) * ALL_DIR_AND_FILES)))
		return (NULL);
	while (array[i])
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

size_t		get_total_blocks(char **files, struct stat *file_stat)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (files[i])
	{
		if (!(file_stat = get_file_stat(files[i], file_stat, ".")))
			return (-1);
		size = size + file_stat->st_blocks;
		free(file_stat);
		i++;
	}
	return (size);
}

char		*get_last_modification_time(struct stat *file_stat)
{
	struct tm		*time_file;
	char			*month;
	char			*final_date;
	char			*rest;

	if (file_stat)
	{
		if (!(time_file = (struct tm*)malloc(sizeof(struct tm))))
			return (NULL);
		if (!(month = ft_strnew(20)))
			return (NULL);
		if (!(final_date = ft_strnew(50)))
			return (NULL);
		if (!(rest = ft_strnew(20)))
		return (NULL);
		time_file = localtime(&file_stat->st_mtime);
		strftime(month, sizeof(char*), "%B", time_file);
		strftime(rest, sizeof(char*), "%d %H:%M", time_file);
		month = ft_strsub(month, 0, 3);
		final_date = ft_strcat(final_date, month);
		final_date = ft_strcat(final_date, " ");
		final_date = ft_strcat(final_date, rest);
		return (final_date);
	}
	return (NULL);
}
