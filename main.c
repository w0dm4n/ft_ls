/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:45:57 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/12 19:11:17 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		main(int argc, char **argv)
{
	int i;
	int fd;

	i = 1;
	if (argc != 1)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-')
			{

			}
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
		//only list dir
	return (0);
}
