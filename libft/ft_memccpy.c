/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:26:38 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 22:36:41 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	char	*ss1;
	char	*ss2;

	ss1 = (char*)s1;
	ss2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		ss1[i] = ss2[i];
		if (ss2[i] == c)
			return ((void *)(ss1 + i + 1));
		i++;
	}
	return (NULL);
}
