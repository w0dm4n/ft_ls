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

int		check_ifvalid(char flag)
{
	if (flag == 'l' || flag == 'R' || flag == 'a'
		|| flag == 'r' || flag == 't' || flag == '1' || flag == '-')
		return (1);
	return (0);
}

int		new_flags(char *current_flags, char *flag_toadd)
{
	int		i;
	int		new;

	i = 1;
	new = 0;
	if (!current_flags)
		return (1);
	while (flag_toadd[i])
	{
		if (ft_strchr(current_flags, flag_toadd[i]) == NULL)
			new++;
		i++;
	}
	return ((new) ? 1 : 0);
}

int		flag_notpresent(char *current_flags, char flag)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (current_flags[i])
	{
		if (current_flags[i] == flag)
		{
			result++;
			break ;
		}
		i++;
	}
	return ((result) ? 0 : 1);
}

char	*add_new_flags(char *current_flags, char *flag_toadd)
{
	int		i;
	char	*new;

	i = 1;
	if (!(new = malloc(sizeof(char) * (ft_strlen(flag_toadd) + 1))))
		return (NULL);
	new = ft_strcat(new, current_flags);
	while (flag_toadd[i])
	{
		if (ft_strchr(current_flags, flag_toadd[i]) == NULL)
		{
			if (check_ifvalid(flag_toadd[i]))
			{
				if (flag_notpresent(new, flag_toadd[i]))
					new = ft_charcat(new, flag_toadd[i]);
			}
			else
			{
				print_error_usage(flag_toadd[i]);
				return (NULL);
			}
		}
		i++;
	}
	return (new);
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
		if (!(current_flags = add_new_flags(current_flags, flag_toadd)))
			return (NULL);
	}
	return (current_flags);
}
