/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:54:55 by mokhames          #+#    #+#             */
/*   Updated: 2021/09/14 19:03:02 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	if (!s[0])
		return (0);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static void	ft_get_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t	i;

	*next_word += *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*next_word;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_nb_words(s, c))
	{
		ft_get_next_word(&next_word, &next_word_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_word, next_word_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
