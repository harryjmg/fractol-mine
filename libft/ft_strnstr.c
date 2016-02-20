/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:26:04 by hgueguen          #+#    #+#             */
/*   Updated: 2013/12/01 20:30:53 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (to_find[j] == 0)
		return (char*)(str);
	while (str[i] != 0)
	{
		if (i >= n)
			return (NULL);
		while (to_find[j] == str[i + j])
		{
			if (i + j >= n)
				return (NULL);
			if (to_find[j + 1] == 0)
			{
				return (char*)(str + i);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
