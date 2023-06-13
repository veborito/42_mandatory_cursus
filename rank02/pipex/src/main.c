/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:12:33 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/13 11:43:27 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_paths(char **env)
{
	char	**paths;
	char	*temp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	temp = ft_substr(env[i], 5, ft_strlen(env[i]));
	if (!temp)
		exit(1);
	paths = ft_split(temp, ':');
	if (!paths)
		exit(1);
	free(temp);
	return (paths);
}

static void	exec_cmd(char **cmds, char **paths, char **env)
{
	int		i;
	char	*path_cmd;
	char	*cmd;

	i = 0;
	cmd = ft_strjoin("/", cmds[0]);
	if (!cmd)
		exit(1);
	while (paths[i])
	{
		path_cmd = ft_strjoin(paths[i], cmd);
		if (!path_cmd)
			exit(1);
		if (access(path_cmd, F_OK) == 0)
		{
			if (execve(path_cmd, cmds, env) == -1)
				throw_error(NULL);
		}
		i++;
		free(path_cmd);
	}
	free(cmd);
	ft_putendl_fd("Command not found", 2);
	exit(1);
}

static void	process_exec(char **av, char **env, int pid)
{
	char	**paths;
	char	**cmds;

	if (pid == 0)
	{
		cmds = ft_split(av[2], ' ');
		if (!cmds || !cmds[0])
			throw_error(NULL);
		paths = get_paths(env);
		if (!paths)
			exit(1);
		exec_cmd(cmds, paths, env);
	}
	cmds = ft_split(av[3], ' ');
	if (!cmds || !cmds[0])
		throw_error(NULL);
	paths = get_paths(env);
	if (!paths)
		exit(1);
	exec_cmd(cmds, paths, env);
}

static void	pipex(char **av, char **env, t_fds fds, int pid1)
{
	int	pid2;

	if (pid1 == 0)
	{
		dup2(fds.infile, STDIN_FILENO);
		dup2(fds.fd[1], STDOUT_FILENO);
		close(fds.fd[0]);
		close(fds.fd[1]);
		process_exec(av, env, pid1);
	}
	pid2 = fork();
	if (pid2 < 0)
		throw_error(NULL);
	if (pid2 == 0)
	{
		dup2(fds.fd[0], STDIN_FILENO);
		dup2(fds.outfile, STDOUT_FILENO);
		close(fds.fd[0]);
		close(fds.fd[1]);
		process_exec(av, env, pid1);
	}
	close(fds.fd[0]);
	close(fds.fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	t_fds	fds;
	int		pid1;

	ft_bzero(&fds, sizeof(fds));
	if (ac != 5)
	{
		ft_putendl_fd("Incorrect number of arguments", 2);
		exit(1);
	}
	fds.outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fds.outfile < 0)
		throw_error(NULL);
	fds.infile = open(av[1], O_RDONLY);
	if (fds.infile < 0)
		throw_error(NULL);
	if (pipe(fds.fd) == -1)
		throw_error(NULL);
	pid1 = fork();
	if (pid1 < 0)
		throw_error(NULL);
	pipex(av, env, fds, pid1);
	exit(0);
}
