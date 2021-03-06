/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:54:59 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/25 13:48:13 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlength(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*ret;

	l = ft_intlength(n);
	ret = ft_strnew(l);
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		if (n == -2147483648)
		{
			ret[1] = '2';
			n = -147483648;
		}
		n = n * -1;
	}
	l--;
	while (l >= 0 && ret[l] != '-' && ret[l] != '2')
	{
		ret[l] = n % 10 + 48;
		n = n / 10;
		l--;
	}
	return (ret);
}
