/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 22:19:51 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/20 21:52:47 by frmarinh         ###   ########.fr       */
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
	if (blocks_size > 0 || ft_strchr(flags, 'a') || files[0])
	{
		if (ft_strchr(flags, 'G'))
			ft_putstr(COLOR_WHITE);
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
			just_print_files(files, flags, ".");
		else
		{
			if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')
				|| ft_strchr(flags, 'o'))
				print_all_l_flag(files, flags);
		}
	}
	else
	{
		if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')
			|| ft_strchr(flags, 'o'))
			print_all_l_flag(files, flags);
		else
			just_print_files(files, flags, ".");
	}
	free_files(files);
}

void		print_dir(char *all_f)
{
	if (ft_strchr(all_f, 'R'))
		print_recursive(get_specified_dir(".", all_f), all_f, ".", 0);
	else
		print_current_dir_with_flags(get_specified_dir(".", all_f), all_f);
}

void		print_arg(int *i, char *f, char **fd)
{
	if (!i[2])
	{
		i[2] = ft_lenarray((void**)fd);
		i[2] = i[2] - i[0];
	}
	if (i[2] > 1 || i[1])
	{
		ft_putstr(fd[i[0]]);
		ft_putstr(":\n");
	}
	if (ft_strchr(f, 'R'))
		print_recursive(get_specified_dir(fd[i[0]], f), f, fd[i[0]], i[0]);
	else
		print_asked_dir_with_flags(get_specified_dir(fd[i[0]], f), f, fd[i[0]]);
	if (i[2] > 1 && fd[i[0] + 1])
		ft_putstr("\n");
}

void		print_file_or_dir(char *flags, char **av, int *pos)
{
	int				index[3];
	char			**all_file;
	char			**file_n_folder;

	index[0] = 0;
	index[1] = 0;
	if (!pos)
		return ;
	if (!flags || flags == NULL)
		if (!(flags = (char*)malloc(sizeof(char))))
			return ;
	if (!(file_n_folder = malloc(sizeof(char*) * ALL_DIR_AND_FILES)))
		return ;
	file_n_folder = ft_set_null(file_n_folder);
	while (pos[index[0]])
	{
		file_n_folder[index[0]] = av[pos[index[0]]];
		index[0]++;
	}
	index[0] = 0;
	index[2] = 0;
	all_file = range_byfilenfolder(file_n_folder, 0);
	file_n_folder = range_byfilenfolder(file_n_folder, 1);
	print_arg_2(index, flags, file_n_folder, all_file);
}
