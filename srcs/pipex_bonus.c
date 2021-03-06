/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:29:53 by mokhames          #+#    #+#             */
/*   Updated: 2021/09/14 17:04:22 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		cmd_call(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t	id;
	int		fd[2];
	char	*line;

	if (argc < 6)
		arg_err();
	if (pipe(fd) == -1)
		error();
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		while (get_next_line(0, &line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envm)
{
	int	i;
	int	fin;
	int	fout;

	if (argc < 5)
		arg_err();
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		fout = open_file(argv[argc - 1], 0);
		here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		fout = open_file(argv[argc - 1], 1);
		fin = open_file(argv[1], 2);
		dup2(fin, 0);
	}
	while (i < argc - 2)
		child_process(argv[i++], envm);
	dup2(fout, 1);
	cmd_call(argv[argc - 2], envm);
	return (0);
}
