/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_permissions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 00:28:37 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/20 00:28:47 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	*add_p_suite_ext(char *p, struct stat *file_stat)
{
	if (file_stat->st_mode & S_IWOTH)
		p = add_p(p, 'w');
	else
		p = add_p(p, '-');
	if (file_stat->st_mode & S_IXOTH)
		p = add_p(p, 'x');
	else
		p = add_p(p, '-');
	return (p);
}

char	*add_p_suite(char *p, struct stat *file_stat)
{
	if (file_stat->st_mode & S_IRGRP)
		p = add_p(p, 'r');
	else
		p = add_p(p, '-');
	if (file_stat->st_mode & S_IWGRP)
		p = add_p(p, 'w');
	else
		p = add_p(p, '-');
	if (file_stat->st_mode & S_IXGRP)
		p = add_p(p, 'x');
	else
		p = add_p(p, '-');
	if (file_stat->st_mode & S_IROTH)
		p = add_p(p, 'r');
	else
		p = add_p(p, '-');
	p = add_p_suite_ext(p, file_stat);
	return (p);
}

char	*get_state(char *p, struct stat *file_stat)
{
	if (S_ISDIR(file_stat->st_mode))
		p = add_p(p, 'd');
	else if (S_ISLNK(file_stat->st_mode))
		p = add_p(p, 'l');
	else
		p = add_p(p, '-');
	if (file_stat->st_mode & S_IRUSR)
		p = add_p(p, 'r');
	else
		add_p(p, '-');
	if (file_stat->st_mode & S_IWUSR)
		p = add_p(p, 'w');
	else
		p = add_p(p, '-');
	if (file_stat->st_mode & S_IXUSR)
		p = add_p(p, 'x');
	else
		p = add_p(p, '-');
	p = add_p_suite(p, file_stat);
	return (p);
}