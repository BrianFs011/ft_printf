/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:14:18 by briferre          #+#    #+#             */
/*   Updated: 2023/01/06 17:49:13 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *string, ...);
int		ft_putstr(char *string, int size);
int		ft_unsigned_itoa(unsigned int num);
void	ft_num_to_letter_x(unsigned int hexa, int i, int upper_case, int *cont);
void	ft_num_to_letter_p(unsigned long hexa, int i, int *cont);
int		print_d(int num);
int		print_c(char caracter);
int		print_s(va_list list);
void	print_p(unsigned long pointer, int recursion, int *cont);
void	print_x(unsigned int hexa, int upper_case, int recursion, int *cont);
void	print_u(unsigned int unsi_deci, int first, int *cont);
int		print_i(int num);

#endif