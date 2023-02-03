/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:50:04 by mtagemou          #+#    #+#             */
/*   Updated: 2023/02/01 21:50:05 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_expand(char **limiter)
{
	if (contains(*limiter, '"') || contains(*limiter, '\''))
	{
		*limiter = quotes_removal(*limiter);
		return (0);
	}
	return (1);
}

void change_flag(int s)
{
	(void)s;
	g_global.heredoc_flag = dup(0);
 	close(0);
}

void sigint_heredoc()
{
	struct sigaction sa_SIGINT;

	sa_SIGINT.sa_handler = &change_flag;
	sigaction(SIGINT,&sa_SIGINT,NULL);
}

int	handle_heredoc(t_cmd *cmd, char *limiter, char *file)
{
	int		expand_mode;
	char	*line;
	char	*joined_line;
	int		fd;

	expand_mode = is_expand(&limiter);
	sigint_heredoc();
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (0);
	line = readline("> ");
	while (line && ft_strcmp(line, limiter))
	{
		if (expand_mode && *line)
			line = parameter_expansion(line);
		joined_line = ft_strjoin(line, "\n");
		write(fd, joined_line, ft_strlen(joined_line));
		free(line);
		free(joined_line);
		line = readline("> ");
	}
	handle_signals();
	if (g_global.heredoc_flag)
	{
		ft_dup2(g_global.heredoc_flag,0);
		ft_close(g_global.heredoc_flag);
		g_global.exit_status =1;
	}
	free(line);
	close(fd);
	free(limiter);
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		return (0);
	cmd->infile = fd;
	free(file);
	return (1);
}
