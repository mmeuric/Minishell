/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:29:53 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:29:55 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_UTILS_H
# define CD_UTILS_H
# include <global_utils.h>

int		change_directory(char *dir);
char	*structure_path(char *curr_dir, char *dir);
char	*join_paths(char *dirname, char *basename);
char	*join_dir_chunks(char *dirname, char *basename);
char	**handle_dot_dot_path(char *path);
int		doesnt_exist(char *path);
char	*consume_path(char *joined_paths);
void	shift_slices(char **slices);
int		has_dot_dot(char **slices);
void	trim_slices(char **slices);
#endif
