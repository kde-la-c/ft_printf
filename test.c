#include "ft_printf.h"

/*int	nbargs(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if(str[i] == '%')
		{
			i++;
			if (str[i] == '%' && ft_cmpchr("cspdiuxX%", str[i]))
		{
			n++;
			i++;
		}
		else if (str[i] == '%' && !ft_cmpchr("cspdiuxX%", str[i + 1]))
			return (-1);
		i++;
	}
	return (n);
}*/

int	putarg(va_list ap, char c)
{
	int	ret;
	int	xd;

	ret = 0;
	if (c == 'c')
	{
		xd = va_arg(ap, int);
		ret = ft_putchar_fd(xd, 1);
	}
	else if (c == 's')
		ret = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
	{
		ret = ret + write(1, "0x", 2);
		ret += ft_putnbr_base_fd(va_arg(ap, size_t), "0123456789abcdef", 1); //handle
	}
	else if (c == 'd' || c == 'i')
	{
		xd = va_arg(ap, int);
		if(xd <= -1)
		{
			ret = ret + write(1, "-", 1);
			ret = ft_putnbr_base_fd((unsigned)(xd * -1), "0123456789", 1);
		}
		else
			ret = ret + ft_putnbr_base_fd(xd, "0123456789", 1); // por que el fd hace falta???
	}
	else if (c == 'u')
		ret = ft_putnbr_base_fd(va_arg(ap, unsigned int),"0123456789", 1); //handle negatives no porque es unsigned jeje
	else if (c == 'x')
		ret = ft_putnbr_base_fd(va_arg(ap, unsigned), "0123456789abcdef", 1); //handle negatives
	else if (c == 'X')
		ret = ft_putnbr_base_fd(va_arg(ap, unsigned), "0123456789ABCDEF", 1); //handle negatives
	else if (c == '%')
		ret = ft_putchar_fd('%', 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;
	int		i;


	i = 0;
	ret = 0;
	va_start(ap, str);
	while (str[i])
	{
		if(str[i] == '%')
		{
			i++;
			if (!ft_cmpchr("cspdiuxX%", str[i]))
				return (-1);
			else if (str[i] == '%')
				ret = ret + write(1, "%", 1);
			else if (ft_cmpchr("cspdiuxX%", str[i]))
				ret = ret + putarg(ap, str[i]);
		}
		else if (str[i] != '%')
			ret = ret + write(1, &str[i], 1);
		i++;

	}
	while (nbargs((char)str))  //try iterating str with i
	{
		if (*str)
		{
			ret += write(1, str, ft_strchr(str, '%') - str);
			str += ft_strchr(str, '%') - str;
			str++;
		}
		ret += putarg(ap, *str);
		str++;
	}
	ret += ft_putstr_fd(va_arg(ap, char ), 1);
	va_end(ap);
	return (ret);
}

/*int	main()
{
	int		ft;
	int		nat;
	char	*base = "hola%%%i\n";
	int		i = 55;
	// char	*str = "HOLLA";

	printf("nat :\n");
	nat = printf(base, i);
	printf("%i\n", nat);
	printf("-----\n");
	printf("ft :\n");
	ft = ft_printf(base, i);
	printf("%i\n", ft);

	// i = nbargs(str);
	// printf("ret :%i\n", i);
	return 0;
}*/

int	main()
{
	int		uwu;
	char	*str = NULL;

	uwu = ft_printf("hola %s %c %d %u %p %x %X \n", str, 0, 0, 0, NULL, 0, 0);
	printf("tuyo: %d\n", uwu);
	sleep(2);
	uwu = printf("hola %s %c %d %u %p %x %X \n", str, 0, 0, 0, NULL, 0, 0);
	printf("original: %d\n", uwu);
	return (0);
}