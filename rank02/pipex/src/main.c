/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:12:33 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/07 17:29:14 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **env)
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

int	exec_cmd(char **cmds, char **paths, char **env)
{
	int		i;
	char	*path_cmd;
	char	*cmd;

	i = 0;
	cmd = ft_strjoin("/", cmds[0]);
	if (!cmd)
		return (1);
	while (paths[i])
	{
		path_cmd = ft_strjoin(paths[i], cmd);
		if (!path_cmd)
			return (1);
		if (access(path_cmd, F_OK) == 0)
			execve(path_cmd, cmds, env);
		i++;
		free(path_cmd);
	}
	free(cmd);
	perror("Command not found ");
	return (1);
}

int	pipex(char **av, char **env, int pid)
{
	char	**paths;
	char	**cmds;

	if (pid == 0)
	{
		cmds = ft_split(av[2], ' ');
		if (!cmds)
			exit(1);
		paths = get_paths(env);
		if (!paths)
			exit(1);
		return (exec_cmd(cmds, paths, env));
	}
	cmds = ft_split(av[3], ' ');
	if (!cmds)
		exit(1);
	paths = get_paths(env);
	if (!paths)
		exit(1);
	if (exec_cmd(cmds, paths, env) == 1)
		exit(1);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	pid1;
	int	infile;
	int	outfile;
	int	res;

	pipe(fd);
	if (ac != 5)
	{
		ft_putendl_fd("Incorrect number of arguments", 2);
		exit(1);
	}
	infile = open(av[1], O_RDONLY, 0777);
	if (infile < 0)
	{
		perror(NULL);
		exit(1);
	}
	if (ac == 5)
	{
		outfile = open(av[4], O_CREAT | O_RDWR, 0777);
		if (outfile < 0)
		{
			perror(NULL);
			exit(1);
		}
		pid1 = fork();
		if (pid1 == 0)
		{
			close(fd[0]);
			dup2(infile, 0);
			dup2(fd[1], 1);
			res = pipex(av, env, pid1);
			write(fd[1], &res, sizeof(int));
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], 0);
			dup2(outfile, 1);
			if (read(fd[0], &res, sizeof(int)) == -1)
			{
				perror(NULL);
				exit(1);
			}
			if (res == 1)
				exit(1);
			pipex(av, env, pid1);
			close(fd[0]);
			wait(NULL);
		}
	}
	exit(0);
}
