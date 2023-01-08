/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:17:38 by briferre          #+#    #+#             */
/*   Updated: 2022/08/03 11:51:02 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(int num)
{
	int		size;
	char	*string;

	string = ft_itoa(num);
	if (!string)
		return (0);
	size = ft_strlen(string);
	ft_putstr(string, size);
	free(string);
	return (size);
}

int	print_c(char caracter)
{
	write (1, &caracter, 1);
	return (1);
}

int	print_s(va_list list)
{
	char	*string;
	int		size;

	string = va_arg(list, char *);
	if (!string)
	{
		size = ft_putstr("(null)", 6);
		return (6);
	}
	size = ft_strlen(string);
	ft_putstr(string, size);
	return (size);
}

void	print_x(unsigned int hexa, int upper_case, int recursion, int *cont)
{
	int				i;
	char			*aux;

	if (hexa == 0 && recursion == 0 && ft_putstr("0", 1))
	{
		(*cont) += 1;
		return ;
	}
	if (hexa == 0)
		return ;
	print_x((hexa / 16), upper_case, ++recursion, cont);
	i = 9;
	while (++i <= 15)
		ft_num_to_letter_x(hexa, i, upper_case, cont);
	if (!((hexa >= 10 && hexa <= 15) || (hexa % 16 >= 10 && hexa % 16 <= 15)))
	{
		aux = ft_itoa(hexa % 16);
		(*cont) += ft_putstr(aux, 1);
		free(aux);
	}
}

void	print_p(unsigned long hexa, int recursion, int *cont)
{
	int				i;
	char			*aux;

	if (hexa == 0 && recursion == 0)
	{
		(*cont) += ft_putstr("(nil)", 5);
		return ;
	}
	if (hexa == 0)
	{
		(*cont) += ft_putstr("0x", 2);
		return ;
	}
	print_p((hexa / 16), ++recursion, cont);
	i = 9;
	while (++i <= 15)
		ft_num_to_letter_p(hexa, i, cont);
	if (!((hexa >= 10 && hexa <= 15) || (hexa % 16 >= 10 && hexa % 16 <= 15)))
	{
		aux = ft_itoa(hexa % 16);
		(*cont) += ft_putstr(aux, 1);
		free(aux);
	}
}
