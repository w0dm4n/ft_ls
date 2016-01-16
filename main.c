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
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*all_flags;
	int		boolean;
	int		*all_d;
	int		case_alldir;

	i = 1;
	case_alldir = 0;
	boolean = 0;
	all_flags = NULL;
	if (argc != 1)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-' && !boolean && argv[i][1])
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
				else
				{
					if (!case_alldir)
						if (!(all_d = initialise_array(all_d)))
							return (-1);
					all_d[case_alldir] = i;
					case_alldir++;
				}
				boolean++;
				close(fd);
			}
			i++;
		}
		if (!boolean)
			print_dir(all_flags);
		else
			print_file_or_dir(all_flags, argv, all_d);
	}
	else
		get_current_dir(all_flags);
	return (0);
}
