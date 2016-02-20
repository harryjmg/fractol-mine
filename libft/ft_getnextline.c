/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llavigne <llavigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:09:28 by llavigne          #+#    #+#             */
/*   Updated: 2014/05/12 14:42:03 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char *str, int count)
{
	char	*tmp;

	tmp = ft_strcpy(NULL, str + count + 1);
	if (str)
		free(str);
	return (tmp);
}

int			ft_getnextline(int fd, char **line)
{
	static char	*str = NULL;
	char		buf[BUFF_SIZE + 2];
	int			count;

	ft_bzero(buf, BUFF_SIZE + 2);
	while (read(fd, buf, BUFF_SIZE))
	{
		str = ft_strjoin(str, buf);
		if (ft_strocchr(buf, '\n'))
			break ;
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (str && !(count = (str[0] || ft_strocchr(buf, '\n')) ? 0 : -1))
	{
		if ((!ft_strocchr(str, '\n')))
			str = ft_strjoin(str, "\n");
		while (str[count] != '\n' && str[count])
			count++;
		str[count] = '\0';
		*line = ft_strcpy(*line, str);
		str = ft_free(str, count);
	}
	return (count = (str == NULL || count == -1 ? 0 : 1));
}
