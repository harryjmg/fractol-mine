/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 21:36:13 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 21:52:31 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static char	*ft_jocker(void)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * 1);
	s[0] = 0;
	return (s);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (ft_jocker());
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[j]))
		j--;
	str = (char*)malloc(sizeof(char) * (j - i + 1));
	k = 0;
	while (i <= j)
		str[k++] = s[i++];
	str[k] = 0;
	return (str);
}
