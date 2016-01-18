/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 22:19:51 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/14 22:21:09 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		print_all_l_flag(char **files, char *flags)
{
	int				i;
	struct stat		*file_stat;
	int				blocks_size;

	i = 0;
	file_stat = NULL;
	blocks_size = get_total_blocks(files, file_stat, ".");
	if (blocks_size > 0 || ft_strchr(flags, 'a'))
	{
		ft_putstr("total ");
		ft_putnbr(blocks_size);
		ft_putstr("\n");
	}
	while (files[i])
	{
		if (!(file_stat = get_file_stat(files[i], file_stat, ".")))
			return ;
		print_line(file_stat, flags, files, i);
		free(file_stat);
		i++;
	}
}

void		print_current_dir_with_flags(char **files, char *flags)
{
	if (ft_strchr(flags, '1'))
	{
		if (check_l_or_1(flags))
			get_current_dir(flags, ".");
		else
		{
			if (ft_strchr(flags, 'l'))
				print_all_l_flag(files, flags);
		}
	}
	else
	{
		if (ft_strchr(flags, 'l'))
			print_all_l_flag(files, flags);
		else
			get_current_dir(flags, ".");			
	}
	free_files(files);
}

void		print_dir(char *all_flags)
{
	if (ft_strchr(all_flags, 'R'))
		print_recursive(get_specified_dir(".", all_flags), all_flags, ".");
	else
		print_current_dir_with_flags(get_specified_dir(".", all_flags), all_flags);
}

void		print_file_or_dir(char *flags, char **av, int *pos)
{
	int				i;
	int				i_2;
	char			**all_file;
	char			**file_n_folder;
	int				file_nbr;
	int				array_len;

	i = 0;
	i_2 = 0;
	if (!pos)
		return ;
	if (!flags || flags == NULL)
		if(!(flags = (char*)malloc(sizeof(char))))
			return ;
	if (!(file_n_folder = malloc(sizeof(char*) * ALL_DIR_AND_FILES)))
		return ;
	file_n_folder = ft_set_null(file_n_folder);
	while (pos[i])
	{
		file_n_folder[i] = av[pos[i]];
		i++;
	}
	// range them by ascii order [file_n_folder]

	i = 0;
	array_len = 0;
	all_file = range_byfilenfolder(file_n_folder, 0);
	file_n_folder = range_byfilenfolder(file_n_folder, 1);
	file_nbr = get_file_nbr(file_n_folder);
	while (file_n_folder[i])
	{
		if (i < file_nbr)
		{
			if (!i_2)
			{
				print_file_with_flags(all_file, flags);
				i_2++;
			}
			if ((i + 1) == file_nbr && file_n_folder[i + 1])
				ft_putstr("\n");
		}
		else
		{
			if (!array_len)
			{
				array_len = ft_lenarray((void**)file_n_folder);
				array_len = array_len - i;
			}
			if (array_len > 1 || i_2)
			{
				ft_putstr(file_n_folder[i]);
				ft_putstr(":\n");
			}
			//ADD PRINT RECURSIVE if -R
			print_asked_dir_with_flags(get_specified_dir(file_n_folder[i], flags), flags, file_n_folder[i]);
			if (array_len > 1 && file_n_folder[i + 1])
				ft_putstr("\n");
		}
		i++;
	}
}