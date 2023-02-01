/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:36:46 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:36:47 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		size_of_env(void);
void	index_envs(void);

void	cd(char **args, int fd);
void	pwd(char **args, int fd);
void	echo(char **args, int fd);
void	env(char **args, int fd);
void	unset(char **args, int fd);
void	export(char **args, int fd);
int		shell_exit(char **args);
int		is_builtins(char *cmd);
int		exec_builtins(char **args, int outfile);

#endif // BUILITIN_H
