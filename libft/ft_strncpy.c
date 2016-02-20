/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:38:02 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 21:56:55 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		end;

	i = 0;
	end = 0;
	while (n != 0)
	{
		if (end == 0)
		{
			s1[i] = s2[i];
			if (s2[i] == 0)
				end = 1;
		}
		else
			s1[i] = 0;
		i++;
		n--;
	}
	return (s1);
}
