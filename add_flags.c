/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 23:00:41 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/12 23:24:54 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		new_flags(char *current_flags, char *flag_toadd)
{
	if (!current_flags)
		return (1);
	//check if there is all character of flag_toadd in current_flags
}

char	*add_new_flags(char *current_flags, char *flag_toadd)
{
	int		i;
	char	*new;

	i = 1; // due to -
}

char	*add_flags(char *current_flags, char *flag_toadd)
{
	size_t		flag_len;

	flag_len = ft_strlen(flag_toadd);
	if (new_flags(current_flags, flag_toadd))
	{
		if (!current_flags)
			if (!(current_flags = malloc(sizeof(char) * flag_len)))
				return (NULL);
		current_flags = add_new_flags(current_flags, flag_toadd);
		// add new_flags that are not in current_flags & parsing them
	}
	else
		return (current_flags);
}
