/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:33:34 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:34:23 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	ft_pipe(int fd[2])
{
	if (pipe(fd) == -1)
		ft_exit(errno, strerror(errno));
}
