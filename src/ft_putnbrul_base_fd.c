/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrul_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:00:26 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/04/08 19:00:36 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbrul_base_fd(unsigned long long nbr, char *base, int fd)
{
	unsigned long long	blen;
	int				ret;

	ret = 0;
	blen = ft_strlen(base);
	if (blen < 2 || ft_ischrrep(base))
		return (0);
	if (nbr < blen)
		ret += write(fd, &base[nbr], 1);
	else if (nbr >= blen)
	{
		ret += ft_putnbrul_base_fd(nbr / blen, base, fd);
		ret += ft_putnbrul_base_fd(nbr % blen, base, fd);
	}
	return (ret);
}
