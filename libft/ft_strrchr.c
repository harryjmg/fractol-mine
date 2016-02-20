/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:02:51 by hgueguen          #+#    #+#             */
/*   Updated: 2013/12/01 20:30:25 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int lastc;

	i = 0;
	lastc = -1;
	while (s[i] != 0)
	{
		if (s[i] == c)
			lastc = i;
		i++;
	}
	if (lastc != -1)
		return (char*)(s + lastc);
	if (c == 0)
		return ((char*)(s + i));
	return (NULL);
}
