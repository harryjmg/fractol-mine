/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 21:33:58 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 21:53:41 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_word(const char *s, char c)
{
	int			k;
	int			nb_words;

	k = 0;
	nb_words = 0;
	while (s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		if (s[k] != c && s[k] != '\0')
			nb_words++;
		while (s[k] != c && s[k] != '\0')
			k++;
	}
	return (nb_words);
}

static int		len_word(const char *str, int i, char c)
{
	int			max;

	max = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		max++;
		i++;
	}
	return (max);
}

static int		norme(const char *str, int k, char c)
{
	while (str[k] == c)
		k++;
	return (k);
}

char			**ft_strsplit(const char *str, char c)
{
	char		**split;
	int			i[2];
	int			k;

	i[0] = 0;
	k = 0;
	if (str == NULL)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_nb_word(str, c) + 1));
	while (i[0] < ft_nb_word(str, c))
	{
		k = norme(str, k, c);
		i[1] = 0;
		split[i[0]] = (char *)malloc(sizeof(char) * (len_word(str, k, c) + 1));
		while (str[k] != '\0' && str[k] != c)
		{
			split[i[0]][i[1]] = str[k];
			k++;
			i[1]++;
		}
		split[i[0]][i[1]] = '\0';
		i[0]++;
	}
	split[i[0]] = NULL;
	return (split);
}
