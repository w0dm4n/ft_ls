/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 04:23:46 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/15 04:29:22 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		print_user_if(char *flags, struct stat *file_stat)
{
	if (!ft_strchr(flags, 'g'))
	{
		ft_putstr(COLOR_GREEN);
		ft_putstr(get_user(file_stat));
		ft_putstr(COLOR_WHITE);
		ft_putstr(" ");
	}
}

void		print_group_if(char *flags, struct stat *f_t)
{
	if (!ft_strchr(flags, 'o'))
	{
		ft_putstr(COLOR_CYAN);
		ft_putstr(get_group(f_t));
		ft_putstr(COLOR_WHITE);
	}
}

void		print_line_colored(struct stat *f_t, char **f, int i, char *f_l)
{
	char	*permissions;

	permissions = get_permissions(f_t);
	ft_putstr(COLOR_BLUE);
	ft_putstr(permissions);
	ft_putstr(COLOR_WHITE);
	ft_putstr("  ");
	ft_putnbr(f_t->st_nlink);
	ft_putstr(" ");
	print_user_if(f_l, f_t);
	ft_putstr(" ");
	print_group_if(f_l, f_t);
	ft_putstr("   ");
	ft_putnbr(f_t->st_size);
	ft_putstr(" ");
	ft_putstr(get_last_modification_time(f_t));
	ft_putstr(" ");
	if (!print_name_by_permissions(permissions, f[i]))
		if (!print_name_by_extension(f[i]))
			ft_putstr(f[i]);
	ft_putstr("\n");
}

void		print_line(struct stat *file_stat, char *flags, char **f, int i)
{
	if (ft_strchr(flags, 'G'))
		print_line_colored(file_stat, f, i, flags);
	else
	{
		ft_putstr(get_permissions(file_stat));
		ft_putstr("  ");
		ft_putnbr(file_stat->st_nlink);
		ft_putstr(" ");
		if (!ft_strchr(flags, 'g'))
		{
			ft_putstr(get_user(file_stat));
			ft_putstr(" ");
		}
		if (!ft_strchr(flags, 'o'))
			ft_putstr(get_group(file_stat));
		ft_putstr("   ");
		ft_putnbr(file_stat->st_size);
		ft_putstr(" ");
		ft_putstr(get_last_modification_time(file_stat));
		ft_putstr(" ");
		ft_putstr(f[i]);
		ft_putstr("\n");
	}
}
