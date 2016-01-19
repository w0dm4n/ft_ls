/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:47:12 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/12 23:23:36 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <stdio.h>
# define MAX_FILES_PER_FOLDER 40960
# define PERMISSIONS_BUFFER 12
# define ALL_DIR_AND_FILES 40960
# define ALL_RECURSIVE_POSSIBILITY 40960
# define DEFAULT_BUFFER 1024
void			print_error(char *name);
char			*add_flags(char *current_flags, char *flag_toadd);
void			get_current_dir(char *flags, char *folder);
void			print_error_usage(char invalid_flag);
void			print_dir(char *all_flags);
void			print_file_or_dir(char *flags, char **av, int *pos);
char			**get_specified_dir(char *dir, char *all_flags);
char			**range_byascii(char **files);
struct stat		*get_file_stat(char *name, struct stat *file_stat, char *folder);
char			*get_permissions(struct stat *file_stat);
char			*get_user(struct stat *file_stat);
char			*get_group(struct stat *file_stat);
char			*get_last_modification_time(struct stat *file_stat);
size_t			get_total_blocks(char **files, struct stat *file_stat, char *folder);
void			print_line(struct stat *file_stat, char *flags, char **f, int i);
int				*initialise_array(int *array);
int				check_l_or_1(char *flags);
char			**range_byfilenfolder(char **file_n_folder, int folder);
char			**set_dir_on_array(char **tmp, char **old, int index);
int				get_file_nbr(char **file_n_folder);
void			print_asked_dir_with_flags(char **files, char *flags, char *folder);
void			just_print_files(char **files);
char			**reverse_array(char **files);
char			**read_without_hidden_files(char **files, DIR *current_dir);
char			**read_with_hidden_files(char **files, DIR *current_dir);
void			free_files(char **files);
char			**modify_if_flags(char *flags, char **files, char *folder);
void			print_file_with_flags(char **files, char *flags);
void			print_recursive(char **files, char *flags, char *folder);
void			print_current_dir_with_flags(char **files, char *flags);
char			**range_by_t_flags(char **files, char *folder);
int				*reverse_int_array(int *array);
#endif
