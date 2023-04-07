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

int	ft_cmpchr(char *set, char c)
{
	int i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

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

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	int		n;
	char	*arg;
	va_list	ap;

	n = 2;
	i = 0;
	ret = 0;
	ft_putstr_fd((char*)str, 1);
	ret += strlen(str);
	va_start(ap, str);
	while (i < n)
	{
		arg = va_arg(ap, char*);
		ft_putstr_fd(arg, 1);
		ret += strlen(arg);
		i++;
	}
	va_end(ap);
	return (ret);
}

int	main()
{
	int		i;
	char	*str = "int :, %c%c%char :, rien :, mais :%";

	// i = ft_printf("hola", " que", " tal");
	// printf("ret :%i\n", i);

	i = nbargs(str);
	printf("ret :%i\n", i);
	return 0;
}
