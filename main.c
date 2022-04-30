/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:24:48 by ltacos            #+#    #+#             */
/*   Updated: 2022/04/30 16:38:52 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path_cmd(char **envp, char *arg_cmd)
{
	char	**pp_path;
	char	**pp_tmp;
	char	*p_cmd_path;
	char	*p_tmp;
	int		i;

	while (*arg_cmd && *arg_cmd == ' ')
		arg_cmd++;
	if (!*arg_cmd)
		return (NULL);
	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	pp_path = ft_split(*envp + 5, ':');
	pp_tmp = ft_split(arg_cmd, ' ');
	p_tmp = ft_strjoin("/", pp_tmp[0]);
	free_mtx_ch(pp_tmp);
	i = 0;
	while (pp_path[i])
	{
		p_cmd_path = ft_strjoin(pp_path[i++], p_tmp);
		if (!access(p_cmd_path, 0))
			return (free_mtx_ch(pp_path), free(p_tmp), p_cmd_path);
		free(p_cmd_path);
	}
	return (free(p_tmp), free_mtx_ch(pp_path), NULL);
}

static void	first_proc_child(char **argv, char **envp, int pipe_fd[2])
{
	int		fd;
	char	*path;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("File");
	if (dup2(fd, 0) < 0)
		error_msg("dup2");
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], 1) < 0)
		error_msg("dup2");
	path = find_path_cmd(envp, argv[2]);
	if (!path)
		error_msg("command");
	if (execve(path, ft_split(argv[2], ' '), envp) == -1)
		error_msg("execuve");
}

static void	second_proc_child(char **argv, char **envp, int pipe_fd[2])
{
	int		fd;
	char	*path;

	fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
		error_msg("File");
	if (dup2(fd, 1) < 0)
		error_msg("dup2");
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], 0) < 0)
		error_msg("dup2");
	path = find_path_cmd(envp, argv[3]);
	if (!path)
		error_msg("command");
	if (execve(path, ft_split(argv[3], ' '), envp) == -1)
		error_msg("execuve");
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	child_0;
	pid_t	child_1;

	if (argc != 5)
		return (ft_putstr_fd("Error: use ./pipex file cmd1 cmd2 file\n", 2), 0);
	if (pipe(pipe_fd) < 0)
		error_msg("pipe");
	child_0 = fork();
	if (child_0 < 0)
		error_msg("fork");
	if (child_0 == 0)
		first_proc_child(argv, envp, pipe_fd);
	child_1 = fork();
	if (child_1 < 0)
		error_msg("fork");
	if (child_1 == 0)
		second_proc_child(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child_0, NULL, 0);
	waitpid(child_1, NULL, 0);
	return (0);
}
