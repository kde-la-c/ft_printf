/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischrrep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:06:48 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/04/08 21:06:51 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ischrrep(char *str)
{
	int		i;
	int		j;
	char	*set;

	i = 0;
	set = malloc(ft_strlen(str) + 1);
	set[0] = str[0];
	while (str[i])
	{
		j = 0;
		while (set[j] && j < i)
			if (str[i] != set[j++])
				set[i] = str[i];
			else
				return (1);
		i++;
	}
	free(set);
	return (0);
}
