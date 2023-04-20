/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:18:54 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/03/03 02:18:56 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbargs(char *str)
{
	int i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_cmpchr("cspdiuxX%", str[i + 1]))
		{
			n++;
			i++;
		}
		else if (str[i] == '%' && !ft_cmpchr("cspdiuxX%", str[i + 1]))
			return (-1);
		i++;
	}
	return (n);
}

int	putarg(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char*), 1));
	else if (c == 'p')
		if (ft_putstr_fd("0x", 1) == 2)
			return (ft_putnbrul_base_fd(va_arg(ap, long), "0123456789abcdef", 1) + 2);
		else
			return (-1);
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (c == 'u')
		return (ft_putnbru_base_fd(va_arg(ap, int), "0123456789", 1));
	else if (c == 'x')
		return (ft_putnbru_base_fd(va_arg(ap, int), "0123456789abcdef", 1));
	else if (c == 'X')
		return (ft_putnbru_base_fd(va_arg(ap, int), "0123456789ABCDEF", 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	check_ret(int ret, int wrote)
{
	if (wrote != -1)
		return (ret + wrote);
	else
		return (wrote);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	if (nbargs((char*)str) == -1)
		return (-1);
	va_start(ap, str);
	while (str && nbargs((char*)str))
	{
		ret = check_ret(ret, write(1, str, ft_strchr(str, '%') - str));
		if (ret == -1)
			return (-1);
		str += ft_strchr(str, '%') - str;
		str++;
		ret = check_ret(ret, putarg(ap, *(str++)));
		if (ret == -1)
			return (-1);
	}
	ret = check_ret(ret, ft_putstr_fd((char*)str, 1));
	return (ret);
}
