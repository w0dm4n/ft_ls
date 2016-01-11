/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:33:38 by frmarinh          #+#    #+#             */
/*   Updated: 2015/12/08 22:17:36 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;
	int len;
	int boolean;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	boolean = 0;
	if (s1 && s2)
	{
		while (i < (int)n && s1[i] == s2[i])
			i++;
		if (i >= (int)n ||
			(i >= (int)ft_strlen(s1) && i >= (int)ft_strlen(s2)))
			boolean = 1;
	}
	return (boolean);
}
