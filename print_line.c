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

void		print_line(struct stat *file_stat, char *flags, char **f, int i)
{
	if (ft_strchr(flags, 'G'))
	{
		// HANDLES COLORS !
	}
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
	ft_putstr(get_last_modification_time(file_stat));
	ft_putstr(" ");
	ft_putstr(f[i]);
	ft_putstr("\n");
}
