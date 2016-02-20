/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 21:11:27 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 22:23:34 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	i = 0;
	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL)
		return (ft_strcpy(NULL, (char *)s2));
	str = ft_realloc((char *)s1, ft_strlen(s1) + ft_strlen(s2) + 1);
	while (str[i])
		i++;
	ft_strcpy(str + i, s2);
	return (str);
}
