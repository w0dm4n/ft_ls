/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:04:39 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/12 20:41:42 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	print_error(char *name)
{
	ft_putstr("ft_ls: ");
	perror(name);
}

void	print_error_usage(char invalid_flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(invalid_flag);
	ft_putstr("\n");
	ft_putstr("usage: ft_ls [-lRart] [file ...]\n");
}
