/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:45:57 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/14 04:13:45 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*all_flags;
	int		boolean;

	i = 1;
	boolean = 0;
	all_flags = NULL;
	if (argc != 1)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-' && !boolean)
			{
				if (!(all_flags = add_flags(all_flags, argv[i])))
					return (-1);
			}
			else
			{
				fd = 0;
				fd = open(argv[i], O_RDONLY);
				if (fd == -1)
					print_error(argv[i]);
				boolean++;
			}
			i++;
		}
		ft_putstr(all_flags);
	}
	else
		get_current_dir();
	return (0);
}
