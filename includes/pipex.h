/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:30:41 by mokhames          #+#    #+#             */
/*   Updated: 2021/09/15 12:31:40 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../GNL/get_next_line.h"

/* functions */
void	error(void);
char	*find_path(char *cmd, char **envp);

void	cmd_call(char *argv, char **envm);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/* Bonus functions */
int		open_file(char *argv, int i);
void	arg_err(void);

#endif
