/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:00:12 by hsaadi            #+#    #+#             */
/*   Updated: 2022/06/16 14:06:32 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_base(const char c)
{
	int	nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	nb;
	int	i;

	nb = 0;
	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	while (i >= 0 && test_base(*str) < str_base)
	{
		nb = nb * str_base + i;
		str++;
		i = test_base(*str);
	}
	return (sign * nb);
}
