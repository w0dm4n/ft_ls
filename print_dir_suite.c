/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 23:35:48 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/20 23:36:42 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	print_arg_2(int *i, char *f, char **fd, char **all_file)
{
	int				file_nbr;

	file_nbr = get_file_nbr(fd);
	while (fd[i[0]])
	{
		if (i[0] < file_nbr)
		{
			if (!i[1])
			{
				print_file_with_flags(all_file, f);
				i[1]++;
			}
			if ((i[0] + 1) == file_nbr && fd[i[0] + 1])
				ft_putstr("\n");
		}
		else
			print_arg(i, f, fd);
		i[0]++;
	}
}
