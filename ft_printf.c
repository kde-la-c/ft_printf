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

/* int	_putarg(va_list ap, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = ft_putchar_fd((char)arg, 1);
	else if (c == 's')
		ret = ft_putstr_fd((char*)arg, 1);
	else if (c == 'p')
	{
		ret = ft_putstr_fd("0x", 1);
		ret += ft_putnbr_base_fd((int)arg, "0123456789abcdef", 1); //handle prefix
	}
	else if (c == 'd')
		ret = ft_putnbr_fd((int)arg, 1);
	else if (c == 'i')
		ret = ft_putnbr_fd((int)arg, 1);
	else if (c == 'u')
		ret = ft_putnbr_fd((int)arg, 1); //handle negatives
	else if (c == 'x')
		ret = ft_putnbr_base_fd((int)arg, "0123456789abcdef", 1); //handle negatives
	else if (c == 'X')
		ret = ft_putnbr_base_fd((int)arg, "0123456789ABCDEF", 1); //handle negatives
	else if (c == '%')
		ret = ft_putchar_fd('%', 1);
	return (ret);
} */

int	putarg(va_list ap, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		ret = ft_putstr_fd(va_arg(ap, char*), 1);
	else if (c == 'p')
	{
		ret = ft_putstr_fd("0x", 1);
		ret += ft_putnbr_base_fd(va_arg(ap, int), "0123456789abcdef", 1);
	}
	else if (c == 'd')
		ret = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'i')
		ret = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ret = ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (c == 'x')
		ret = ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", 1);
	else if (c == 'X')
		ret = ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 1);
	else if (c == '%')
		ret = ft_putchar_fd('%', 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	if (nbargs((char*)str) == -1)
		return (-1);
	va_start(ap, str);
	while (str)
	{
		if (nbargs((char*)str))
		{
			ret += write(1, str, ft_strchr(str, '%') - str);
			str += ft_strchr(str, '%') - str;
			str++;
			ret += putarg(ap, *str);
			str++;
		}
		else
		{
			ret += ft_putstr_fd((char*)str, 1);
			str += ft_strlen(str);
		}
	}
	va_end(ap);
	return (ret);
}

// "hola %i que %s tal"

/* int	ft_printf(const char *str, ...)
{
	int		ret;
	void	*arg;
	va_list	ap;

	ret = 0;
	if (nbargs((char*)str) == -1)
		return (-1);
	va_start(ap, str);
	while (nbargs((char*)str) && str)  //try iterating str with i
	{
		if (*str != '%')
		{
			ret += write(1, str, ft_strchr(str, '%') - str);
			str += ft_strchr(str, '%') - (str - 1);
			str++;
		}
		else if (*(str - 1) == '%' && *(str) == '%')
		{
			str++;
			ret += ft_putchar_fd(*(str++), 1);
		}
		else
		{
			str++;
			arg = va_arg(ap, void*);
			ret += putarg(arg, *(str++));
		}
	}
	va_end(ap);
	ret += ft_putstr_fd((char*)str, 1);
	return (ret);
} */
