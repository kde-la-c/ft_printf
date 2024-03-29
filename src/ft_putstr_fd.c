/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:43:00 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/01/24 21:43:06 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	ret;

	ret = 0;
	if (!s)
		ret = write(fd, "(null)", 6);
	else
		ret = write(fd, &s[0], ft_strlen(s));
	return (ret);
}
