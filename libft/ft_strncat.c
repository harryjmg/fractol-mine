/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:00:09 by hgueguen          #+#    #+#             */
/*   Updated: 2013/12/01 20:29:50 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[j] != 0)
		j++;
	while (s2[i] != 0 && i < n)
	{
		s1[i + j] = s2[i];
		i++;
	}
	s1[i + j] = 0;
	return (s1);
}
