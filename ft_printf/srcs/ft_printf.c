/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:02:37 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/25 18:41:20 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0' && *str != '%')
		i++;
	return (i);
}

static int	ft_is_spec(t_struct *f)
{
	int	i;

	i = 1;
	while (!ft_strchr(SPEC, f->dup[f->i + i]))
	{
		if (!ft_strchr(FLAG, f->dup[f->i + i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_start(t_struct *f)
{
	while (f->dup[f->i] != '\0')
	{
		if (f->dup[f->i] == '%')
		{
			if (ft_is_spec(f))
			{
				f->spe = (t_flags *)malloc(sizeof(t_flags));
				if (!f->spe)
					return (0);
				if (!ft_parse(f))
					return (0);
				if (f->spe)
					free(f->spe);
			}
		}
		else
			ft_chrtobuf(f, f->dup[f->i], 1);
		f->i++;
	}
	return (1);
}

int	ft_snprintf(char *s, size_t n, const char *format, ...)
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
	if (!ft_start(&f))
		return (ft_fail(&f));
	f.out[f.len + 1] = '\0';
	s = ft_strncpy(s, f.out, n);
	ret_val = f.len;
	if (f.dup)
		free(f.dup);
	if (f.out)
		free(f.out);
	va_end(f.ap);
	return (ret_val);
}

int	ft_printf(const char *format, ...)
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
	write(1, f.out, f.len);
	ret_val = f.len;
	if (f.dup)
		free(f.dup);
	if (f.out)
		free(f.out);
	va_end(f.ap);
	return (ret_val);
}
