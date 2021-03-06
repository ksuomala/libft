/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:28:54 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/25 18:26:28 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_struct	f;
	int			ret_val;

	ft_bzero((void *)&f, sizeof(t_struct));
	f.buf_size = 1001;
	f.out = (char *)malloc(sizeof(char) * f.buf_size);
	if (!f.out)
		return (-1);
	ft_bzero(f.out, f.buf_size);
	f.dup = ft_strdup(format);
	if (!f.dup)
		return (ft_fail(&f));
	va_start(f.ap, format);
	ft_start(&f);
	f.out[f.len + 1] = '\0';
	write(fd, f.out, f.len);
	ret_val = f.len;
	if (f.dup)
		free(f.dup);
	if (f.out)
		free(f.out);
	va_end(f.ap);
	return (ret_val);
}
