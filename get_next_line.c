/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:50:19 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/25 15:23:38 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcut(char **s)
{
	char			*ret;
	char			*tmp;
	int				i;

	i = 0;
	if (*s == NULL)
		return (NULL);
	while (s[0][i] != '\n' && s[0][i] != '\0')
		i++;
	if (s[0][i] == '\0')
	{
		if (i == 0)
			return (NULL);
		ret = ft_strdup(s[0]);
		ft_strdel(&s[0]);
		return (ret);
	}
	ret = ft_strsub(*s, 0, i);
	if (s[0][i + 1] == '\0')
		tmp = NULL;
	else
		tmp = ft_strdup(*s + i + 1);
	free(s[0]);
	*s = tmp;
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*s[FD_SIZE];

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while (!ft_strchr(buf, '\n'))
	{
		ft_bzero(buf, BUFF_SIZE);
		if (read(fd, buf, BUFF_SIZE) < 0)
			return (-1);
		if (s[fd] == NULL)
			s[fd] = ft_strnew(0);
		s[fd] = ft_strfjoin(s[fd], buf);
	}
	*line = ft_strcut(&s[fd]);
	if (*line)
		return (1);
	return (0);
}
