/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <hgueguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:09:22 by hgueguen          #+#    #+#             */
/*   Updated: 2014/04/20 22:31:39 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int unit;

	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	unit = n % 10;
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(unit + '0', fd);
}
