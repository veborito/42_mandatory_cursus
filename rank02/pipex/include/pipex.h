/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:11:03 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/08 17:12:49 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <sys/wait.h>

// ERROR

void	throw_error(char *error);
void	free_split(char **split);

// file descriptors

typedef struct s_fds {
	int	infile;
	int	outfile;
	int	fd[2];
	int	res;
}	t_fds;

#endif