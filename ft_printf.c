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

int	putarg(void *arg, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = ft_putchar_fd((char)arg, 1);
	else if (c == 's')
		ret = ft_putstr_fd(arg, 1);
	else if (c == 'p')
		c = 'p';
	else if (c == 'd')
		ret = ft_putnbr_fd((int)arg, 1);
	else if (c == 'i')
		ret = ft_putnbr_fd((int)arg, 1);
	else if (c == 'u')
		ret = ft_putnbr_fd((unsigned int)arg, 1);
	else if (c == 'x')
		ret = ft_putnbr_base_fd((int)arg, "0123456789abcdef", 1);
	else if (c == 'X')
		ret = ft_putnbr_base_fd((int)arg, "0123456789ABCDEF", 1);
	else if (c == '%')
		ret = ft_putchar_fd('%', 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	int		n;
	void	*arg;
	va_list	ap;

	i = 0;
	ret = 0;
	n = nbargs((char*)str);
	if (n == -1)
		return (n);
	va_start(ap, str);
	while (i < n)
	{
		if (*str)
		{
			ret += write(1, str, ft_strchr(str, '%') - str);
			str += ft_strchr(str, '%') - str;
			str++;
		}
		arg = va_arg(ap, void*);
		ret += putarg(arg, *str);
		str++;
		i++;
	}
	va_end(ap);
	ret += ft_putstr_fd((char*)str, 1);
	return (ret);
}

int	main()
{
	int		i;
	// char	*str = "ho.la.";

	i = ft_printf("hola %s, %s\n", "woaw", "!!!!!!!!!!!!!");
	printf("i :%i\n", i);
	// printf("ret :%li\n", ft_strchr(str, '.') - str);

	// i = nbargs(str);
	// printf("ret :%i\n", i);
	return 0;
}
