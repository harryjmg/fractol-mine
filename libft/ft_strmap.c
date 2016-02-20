/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:48:39 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 22:23:09 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * ft_strlen(s));
	i = 0;
	while (s[i] != 0)
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
