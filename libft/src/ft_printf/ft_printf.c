/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 12:32:07 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 14:54:30 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdarg.h>

static int	print_format(const char *format, int i, va_list ap)
{
	if (format[i] == 'c')
		return (print_char(va_arg(ap, int)));
	else if (format[i] == 's')
		return (print_str(va_arg(ap, char *)));
	else if (format[i] == 'p')
		return (print_ptr(va_arg(ap, uintptr_t)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (print_num(va_arg(ap, int)));
	else if (format[i] == 'u')
		return (print_unsigned(va_arg(ap, unsigned int)));
	else if (format[i] == 'x')
		return (print_hex_lower(va_arg(ap, int)));
	else if (format[i] == 'X')
		return (print_hex_upper(va_arg(ap, int)));
	else if (format[i] == '%')
		return (print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		print_count;

	i = 0;
	print_count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			print_count++;
		}
		else
		{
			print_count += print_format(format, i + 1, ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (print_count);
}
