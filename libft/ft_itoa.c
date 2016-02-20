/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:18:43 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 22:38:35 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_aux(char *s, size_t n, size_t i, int sign)
{
	int		unit;

	while (n > 9)
	{
		unit = n % 10;
		n /= 10;
		s[i] = unit + '0';
		i--;
	}
	s[i] = n + '0';
	if (sign == -1)
		s[--i] = '-';
}

static char	*ft_jocker(void)
{
	char	*s;

	s = ft_strdup("-2147483648");
	return (s);
}

static char	*ft_itoa_core(int n)
{
	size_t	nb;
	size_t	i;
	int		sign;
	char	*s;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
		i++;
	}
	nb = n;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	i += 1;
	s = (char*)malloc(sizeof(char) * i + 1);
	s[i--] = 0;
	ft_itoa_aux(s, n, i, sign);
	return (s);
}

char		*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_jocker());
	else
		return (ft_itoa_core(n));
}
