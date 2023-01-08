/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:11:49 by briferre          #+#    #+#             */
/*   Updated: 2022/08/08 17:57:55 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_after_porcentage(char *string, va_list list, int i, int *cont)
{
	if (string[i] == 'c')
		(*cont) += print_c((char)va_arg(list, int));
	else if (string[i] == 's')
		(*cont) += print_s(list);
	else if (string[i] == 'p')
		print_p((unsigned long)va_arg(list, void *), 0, cont);
	else if (string[i] == 'd')
		(*cont) += print_d(va_arg(list, int));
	else if (string[i] == 'i')
		(*cont) += print_i(va_arg(list, int));
	else if (string[i] == 'u')
		print_u(va_arg(list, unsigned int), 0, cont);
	else if (string[i] == 'x')
		print_x(va_arg(list, int), 0, 0, cont);
	else if (string[i] == 'X')
		print_x(va_arg(list, int), 1, 0, cont);
	else if (string[i] == '%')
		(*cont) += ft_putstr("%%", 1);
	else
		(*cont) += ft_putstr("Erro de conversão\n", 19);
}

int	ft_printf(const char *string, ...)
{
	int			i;
	int			cont;
	va_list		list;

	if (!string)
		return (0);
	va_start(list, string);
	i = -1;
	cont = 0;
	while (string[++i])
	{
		if (string[i++] == '%')
			ft_after_porcentage((char *)string, list, i, &cont);
		else
			cont += ft_putstr((char *)&string[--i], 1);
	}
	va_end(list);
	return (cont);
}
