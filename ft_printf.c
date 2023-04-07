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

void	putarg(void *arg, char c)
{
	if (c == 'c')
		ft_putchar_fd((char)arg, 1);
	else if (c == 's')
		ft_putstr_fd(arg, 1);
	else if (c == 'p')
		c = 'p';
	else if (c == 'd')
		ft_putnbr_fd((int)arg, 1); //adjust to decimal
	else if (c == 'i')
		ft_putnbr_fd((int)arg, 1);
	else if (c == 'u')
		ft_putnbr_fd((unsigned int)arg, 1);
	else if (c == 'x')
		c = 'x';
	else if (c == 'X')
		c = 'X';
	else if (c == '%')
		c = '%';
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
			write(1, str, ft_strchr(str, '%') - str);
			str += ft_strchr(str, '%') - str;
			str++;
		}
		arg = va_arg(ap, void*);
		putarg(arg, *str);
		str++;
		i++;
	}
	va_end(ap);
	ft_putstr_fd((char*)str, 1);
	return (ret);
}

int	main()
{
	int		i;
	// char	*str = "ho.la.";

	i = ft_printf("hola %d, %s", 123, "woaw");
	// printf("ret :%li\n", ft_strchr(str, '.') - str);

	// i = nbargs(str);
	// printf("ret :%i\n", i);
	return 0;
}
