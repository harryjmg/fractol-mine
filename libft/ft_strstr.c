/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:40:17 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 22:05:26 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == 0)
		return (char*)(str);
	while (str[i] != 0)
	{
		while (to_find[j] == str[i + j])
		{
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
