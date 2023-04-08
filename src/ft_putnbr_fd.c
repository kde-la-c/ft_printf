/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:54:10 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/01/24 21:54:14 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		ret += write(fd, "-2147483648", 11);
		return (ret);
	}
	if (n < 0)
	{
		n *= -1;
		ret += write(fd, "-", 1);
	}
	if (n < 10)
	{
		n += 48;
		ret += write(fd, &n, 1);
	}
	else if (n > 9)
	{
		ret += ft_putnbr_fd(n / 10, fd);
		ret += ft_putnbr_fd(n % 10, fd);
	}
	return (ret);
}
