/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:23:47 by mokhames          #+#    #+#             */
/*   Updated: 2021/09/14 18:55:15 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent_process(int *p, char **argv, char **envm)
{
	int	sfile;

	sfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (sfile == -1)
		error();
	dup2(p[0], 0);
	dup2(sfile, 1);
	close(p[1]);
	cmd_call(argv[3], envm);
}

void	child_process(int *p, char **argv, char **envm)
{
	int	ffile;

	ffile = open(argv[1], O_RDONLY, 0777);
	if (ffile == -1)
		error();
	dup2(p[1], 1);
	dup2(ffile, 0);
	close(p[1]);
	cmd_call(argv[2], envm);
}

int	main(int argc, char **argv, char **envm)
{
	pid_t	pid;
	int		p[2];

	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (0);
	}
	if (pipe(p) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
		child_process(p, argv, envm);
	waitpid(pid, NULL, 0);
	parent_process(p, argv, envm);
	close(p[0]);
	close(p[1]);
	return (0);
}
