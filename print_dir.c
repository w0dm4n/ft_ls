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

	i = 0;
	file_stat = NULL;
	ft_putstr("total ");
	ft_putnbr(get_total_blocks(files, file_stat));
	ft_putstr("\n");
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
			get_current_dir(flags);
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
	}
	free(files);
}

void		print_dir(char *all_flags)
{
	print_current_dir_with_flags(get_specified_dir(".", all_flags), all_flags);
}

void		print_file_or_dir(char *flags, char **av, int *pos)
{
	int				i;
	int				i_2;
	char			**file_n_folder;
	//char	**files;
	struct stat		*file_stat;

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
	file_n_folder = range_byfilenfolder(file_n_folder);
	while (file_n_folder[i])
	{
		if (!(file_stat = get_file_stat(file_n_folder[i], file_stat, ".")))
			return ;
		if (S_ISDIR(file_stat->st_mode))
		{
			ft_putstr("folder");
		}
		else
			ft_putstr("file");
		ft_putstr("\n");
		/*ft_putstr(file_n_folder[i]);
		ft_putstr(":\n");
		if (file_n_folder[i][0] == '-')
			ft_putstr("\n");*/
		//print_current_dir_with_flags(get_specified_dir(file_n_folder[i], flags), flags);
		// get_file_stat DOESNT LOOK IN THE GOOD FOLDER
		/*while (files[i_2])
		{
			ft_putstr(files[i_2]);
			i_2++;
		}
		free(files);*/
		free(file_stat);
		i++;
	}
}