/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 12:32:07 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 14:32:26 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"
#include <stdarg.h>

static int	print_format_fd(const int fd, const char *format, int i, va_list ap)
{
	if (format[i] == 'c')
		return (print_char_fd(va_arg(ap, int), fd));
	else if (format[i] == 's')
		return (print_str_fd(va_arg(ap, char *), fd));
	else if (format[i] == 'p')
		return (print_ptr_fd(va_arg(ap, uintptr_t), fd));
	else if (format[i] == 'd' || format[i] == 'i')
		return (print_num_fd(va_arg(ap, int), fd));
	else if (format[i] == 'u')
		return (print_unsigned_fd(va_arg(ap, unsigned int), fd));
	else if (format[i] == 'x')
		return (print_hex_lower_fd(va_arg(ap, int), fd));
	else if (format[i] == 'X')
		return (print_hex_upper_fd(va_arg(ap, int), fd));
	else if (format[i] == '%')
		return (print_percent_fd(fd));
	return (0);
}

int	ft_printf_fd(const int fd, const char *format, ...)
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
			write(fd, &format[i], 1);
			print_count++;
		}
		else
		{
			print_count += print_format_fd(fd, format, i + 1, ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (print_count);
}
