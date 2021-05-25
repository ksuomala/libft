/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:45:04 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/25 13:42:24 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits_s(char *s)
{
	int	i;
	int	digits;

	digits = 0;
	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			digits++;
		i++;
	}
	return (digits);
}
