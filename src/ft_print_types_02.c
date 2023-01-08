/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:06:24 by briferre          #+#    #+#             */
/*   Updated: 2022/08/03 13:33:03 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(unsigned int unsi_deci, int first, int *cont)
{
	char	caracter;

	if (first == 0 && unsi_deci == 0)
	{
		(*cont) += ft_putstr("0", 1);
		return ;
	}
	if (unsi_deci == 0)
		return ;
	print_u((unsi_deci / 10), ++first, cont);
	caracter = ((unsi_deci % 10) + '0');
	(*cont) += ft_putstr(&caracter, 1);
}

int	print_i(int num)
{
	return (print_d(num));
}
