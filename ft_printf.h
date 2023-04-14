/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:22:47 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/03/03 02:22:50 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *, ...);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);

int		ft_cmpchr(char *set, char c);
int		ft_putnbr_base_fd(int nbr, char *base, int fd);
int		ft_ischrrep(char *str);

#endif
