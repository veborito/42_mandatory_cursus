/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:12:33 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/02 18:36:53 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h> 
#include <sys/wait.h>

int	main(int ac, char **av)
{
	int	id1;
	int	fd[2];

	(void)ac;
	(void)av;

	if (pipe(fd) == -1)
		printf("Error opening the pipe\n");
	id1 = fork();
	exit(0);
}
