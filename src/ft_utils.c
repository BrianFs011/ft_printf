/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:29:37 by briferre          #+#    #+#             */
/*   Updated: 2022/08/09 08:57:37 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *string, int size)
{
	write (1, string, size);
	return (size);
}

int	ft_unsigned_itoa(unsigned int num)
{
	int				i;
	char			*string;

	if (num == 0)
		return (0);
	ft_unsigned_itoa(num / 10);
	string = ft_itoa(num % 10);
	i = ft_putstr(string, ft_strlen(string));
	free(string);
	return (i);
}

void	ft_num_to_letter_x(unsigned int hexa, int i, int uc, int *cont)
{
	char	letter;

	if (uc)
		letter = i - 10 + 'A';
	else
		letter = i - 10 + 'a';
	if ((hexa == (unsigned int)i) || (hexa % 16 == (unsigned int)i))
		(*cont) += ft_putstr(&letter, 1);
}

void	ft_num_to_letter_p(unsigned long hexa, int i, int *cont)
{
	char	letter;

	if (hexa == (unsigned long)i || hexa % 16 == (unsigned long)i)
	{
		letter = i - 10 + 'a';
		(*cont) += ft_putstr(&letter, 1);
	}
}
