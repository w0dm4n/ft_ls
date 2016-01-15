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
	int			i;
	struct stat		*file_stat;
	//struct passwd	*pw;

	flags = NULL;
	i = 0;
	while (files[i])
	{
		if (!(file_stat = get_file_stat(files[i], file_stat)))
			return ;
		ft_putstr(get_permissions(file_stat));
		ft_putstr("  ");
		ft_putnbr(file_stat->st_nlink);
		ft_putstr(" ");
		ft_putstr(get_user(file_stat));
		ft_putstr(" ");
		ft_putstr(get_group(file_stat));
		ft_putstr("   ");
		ft_putnbr(file_stat->st_size);
		ft_putstr(" ");
		ft_putnbr(file_stat->st_mtime);
		//ft_putstr("Jan 15 01:33");
		ft_putstr(" ");
		ft_putstr(files[i]);
		ft_putstr("\n");
		i++;
	}
}

void		print_current_dir_with_flags(char **files, char *flags)
{
	if (ft_strchr(flags, 'l'))
		print_all_l_flag(files, flags);
	free(files);
}

void		print_dir(char *all_flags, char **argv, int folder_nbr)
{
	int i;

	i = 1;
	if (!folder_nbr)
		print_current_dir_with_flags(get_specified_dir(".", all_flags), all_flags);
	else
	{
		while (i <= folder_nbr)
		{
			//if one file/dir(on argv) is invalid that's all fucked
			//print_dir_or_files_with_flags(get_dir_or_files(argv[i]), all_flags);
			ft_putstr(argv[i]);
			i++;
		}
	}
}
