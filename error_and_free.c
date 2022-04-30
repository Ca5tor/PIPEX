/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:45:39 by ltacos            #+#    #+#             */
/*   Updated: 2022/04/29 20:47:57 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *msg)
{
	perror(msg);
	exit(1);
}

void	free_mtx_ch(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		free(mtx[i++]);
	free(mtx);
}
