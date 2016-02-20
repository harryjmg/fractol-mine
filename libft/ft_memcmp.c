/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:33:01 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 22:35:45 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ns1;
	char	*ns2;

	i = 0;
	ns1 = (char*)s1;
	ns2 = (char*)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && ns1[i] == ns2[i])
		i++;
	return ((unsigned char)ns1[i] - (unsigned char)ns2[i]);
}
