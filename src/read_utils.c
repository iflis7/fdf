/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:30:39 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/21 17:11:51 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_digit_base(char c, int base)
{
	const char	*digits;
	int			i;

	digits = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_prefixed(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (1);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}

int	ft_isnumber(char *str, int base)
{
	size_t	i;
	size_t	digits;

	i = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_prefixed(&str[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_digit_base(str[i++], base) >= 0)
		digits++;
	if (!str[i] && digits)
		return (1);
	return (0);
}

int	ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_prefixed(&str[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign = -1;
		sign = 1;
	}
	while (ft_digit_base(str[i], base) >= 0)
		result = result * base + ft_digit_base(str[i++], base);
	return ((int)(result * sign));
}
