/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 01:36:13 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/17 01:37:15 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		print_all_flag(char **files, char *flags, char *folder, int only_f)
{
	int				i;
	struct stat		*file_stat;
	int				blocks_size;

	i = 0;
	file_stat = NULL;
	if (!only_f)
	{
		blocks_size = get_total_blocks(files, file_stat, folder);
		if (blocks_size > 0 || ft_strchr(flags, 'a') || files[0])
		{
			(ft_strchr(flags, 'G')) ? ft_putstr(COLOR_WHITE) : ft_putstr(DEF);
			ft_putstr("total ");
			ft_putnbr(blocks_size);
			ft_putstr("\n");
		}
	}
	while (files[i])
	{
		if (!(file_stat = get_file_stat(files[i], file_stat, folder)))
			return ;
		print_line(file_stat, flags, files, i);
		free(file_stat);
		i++;
	}
}

void		print_file_with_flags(char **files, char *f)
{
	files = modify_if_flags(f, files, ".");
	if (!f || f == NULL || !ft_strlen(f))
		just_print_files(files, "\0", ".");
	else
	{
		if (ft_strchr(f, '1'))
		{
			if (check_l_or_1(f))
				just_print_files(files, f, ".");
			else
			{
				if (ft_strchr(f, 'l') || ft_strchr(f, 'g') || ft_strchr(f, 'o'))
					print_all_flag(files, f, ".", 1);
			}
		}
		else
		{
			if (ft_strchr(f, 'l') || ft_strchr(f, 'g') || ft_strchr(f, 'o'))
				print_all_flag(files, f, ".", 1);
			else
				just_print_files(files, f, ".");
		}
	}
	free_files(files);
}

void		print_asked_dir_with_flags(char **files, char *flags, char *folder)
{
	if (!flags || flags == NULL || !ft_strlen(flags))
		just_print_files(files, flags, folder);
	else
	{
		if (ft_strchr(flags, '1'))
		{
			if (check_l_or_1(flags))
				just_print_files(files, flags, folder);
			else
			{
				if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')
					|| ft_strchr(flags, 'o'))
					print_all_flag(files, flags, folder, 0);
			}
		}
		else
		{
			if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')
				|| ft_strchr(flags, 'o'))
				print_all_flag(files, flags, folder, 0);
			else
				just_print_files(files, flags, folder);
		}
	}
	free_files(files);
}
