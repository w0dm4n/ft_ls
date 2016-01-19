/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_suite_ext_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 03:09:28 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/19 03:12:45 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		*reverse_int_array(int *array)
{
	int		i;
	int		i_2;
	int		*tmp;

	i = 0;
	i_2 = 0;
	while (array[i])
		i++;
	if (!(tmp = malloc(sizeof(int) * i)))
		return (NULL);
	i--;
	while (array[i])
	{
		tmp[i_2] = array[i];
		i_2++;
		i--;
	}
	return (tmp);
}
