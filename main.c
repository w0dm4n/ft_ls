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

int		main_suite(int *index, int *all_d, char **argv, char *f)
{
	if (!(all_d = initialise_array(all_d)))
		return (-1);
	while (argv[index[0]])
	{
		if (argv[index[0]][0] == '-' && !index[2] && argv[index[0]][1])
		{
			if (!(f = add_flags(f, argv[index[0]])))
				return (-1);
		}
		else if (!(index[1] = 0))
		{
			index[1] = open(argv[index[0]], O_RDONLY);
			if (index[1] == -1)
				print_error(argv[index[0]]);
			else if ((all_d[index[3]] = index[0]))
				index[3]++;
			index[2]++;
			close(index[1]);
		}
		index[0]++;
	}
	(!index[2]) ? print_dir(f) : print_file_or_dir(f, argv, all_d);
	return (1);
}

int		main(int argc, char **argv)
{
	int		index[4];
	char	*f;
	int		*all_d;
	int		res;

	index[0] = 1;
	index[3] = 0;
	index[2] = 0;
	res = 0;
	f = NULL;
	all_d = NULL;
	if (argc != 1)
	{
		res = main_suite(index, all_d, argv, f);
		if (!res)
			return (res);
	}
	else
		get_current_dir(f, ".");
	return (0);
}
