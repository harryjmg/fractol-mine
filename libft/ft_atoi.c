/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:21:48 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 21:42:48 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int acc;
	int sign;

	acc = 0;
	i = 0;
	sign = 1;
	while (str[i] > 0 && str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != 0 && ft_isdigit(str[i]) == 1)
	{
		acc += (str[i] - 48);
		i++;
		if (str[i] != 0 && ft_isdigit(str[i]) == 1)
			acc *= 10;
	}
	return (acc * sign);
}
