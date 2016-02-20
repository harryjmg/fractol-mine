/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:12:17 by hgueguen          #+#    #+#             */
/*   Updated: 2013/12/01 20:29:59 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t len_dst;
	size_t len_src;
	size_t expected;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (n <= len_dst)
		expected = n + len_src;
	else
	{
		expected = len_dst + len_src;
		ft_strncat(dst, src, n - len_dst - 1);
	}
	return (expected);
}
