/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdarg.h>

ssize_t
	ft_vsprintf(
	char *restrict str,
	const char *restrict format,
	va_list ap)
{
	t_buffer	buf;
	ssize_t		written;

	printf_buffer_init_buffer(&buf, str, (size_t) - 1);
	printf_internal(&buf, format, ap);
	written = printf_buffer_flush(&buf);
	return (written);
}

ssize_t
	ft_sprintf(
	char *restrict str,
	const char *restrict format,
	...)
{
	va_list	ap;
	ssize_t	written;

	va_start(ap, format);
	written = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (written);
}

ssize_t
	ft_vsnprintf(
	char *restrict str,
	size_t size,
	const char *restrict format,
	va_list ap)
{
	t_buffer	buf;
	ssize_t		written;

	printf_buffer_init_buffer(&buf, str, size);
	printf_internal(&buf, format, ap);
	written = printf_buffer_flush(&buf);
	return (written);
}

ssize_t
	ft_snprintf(
	char *restrict str,
	size_t size,
	const char *restrict format,
	...)
{
	va_list	ap;
	ssize_t	written;

	va_start(ap, format);
	written = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (written);
}
