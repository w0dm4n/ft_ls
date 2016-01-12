/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:45:57 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/12 23:22:38 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*all_flags;

	i = 1;
	if (argc != 1)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-')
				all_flags = add_flags(all_flags, argv[i]);
			else
			{
				fd = 0;
				fd = open(argv[i], O_RDONLY);
				if (fd == -1)
					print_error(argv[i]);
			}
			i++;
		}
	}
	//else
		//get_current_dir
	return (0);
}
