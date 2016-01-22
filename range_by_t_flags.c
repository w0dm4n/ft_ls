/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_by_t_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 22:34:33 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/18 22:35:40 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	**get_in_order(int *t, char **files, int i, int final_size)
{
	int		tmp_value;
	char	*tmp;

	if (!t || !t[0])
		return (NULL);
	while (t[final_size])
		final_size++;
	while (i < (final_size - 1))
	{
		if (t[i] <= t[i + 1])
			i++;
		else
		{
			tmp_value = t[i];
			tmp = files[i];
			t[i] = t[i + 1];
			t[i + 1] = tmp_value;
			files[i] = files[i + 1];
			files[i + 1] = tmp;
			i = 0;
		}
	}
	files = reverse_array(files);
	return (files);
}

char	**set_in_t_order(char **files, int *t)
{
	files = get_in_order(t, files, 0, 0);
	return (files);
}

int		*get_timestamp(char **files, char *folder)
{
	int				*tmp;
	int				i;
	struct stat		*file_stat;

	i = 0;
	while (files[i])
		i++;
	if (!(tmp = malloc(sizeof(int) * MAX_FILES_PER_FOLDER)))
		return (NULL);
	i = 0;
	while (files[i])
	{
		if (!(file_stat = get_file_stat(files[i], file_stat, folder)))
			return (NULL);
		tmp[i] = file_stat->st_mtime;
		free(file_stat);
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	**range_by_t_flags(char **files, char *folder)
{
	int				*all_timestamp;

	all_timestamp = get_timestamp(files, folder);
	files = set_in_t_order(files, all_timestamp);
	free(all_timestamp);
	return (files);
}
