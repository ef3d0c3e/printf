/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stdio.c                                  :+:      :+:    :+:   */
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
	ft_vfprintf(
	FILE *restrict stream,
	const char *restrict format,
	va_list ap)
{
	t_buffer	buf;
	ssize_t		written;

	printf_buffer_init_stdio(&buf, stream);
	printf_internal(&buf, format, ap);
	written = printf_buffer_flush(&buf);
	return (written);
}

ssize_t
	ft_fprintf(
	FILE *restrict stream,
	const char *restrict format,
	...)
{
	va_list	ap;
	ssize_t	written;

	va_start(ap, format);
	written = ft_vfprintf(stream, format, ap);
	va_end(ap);
	return (written);
}
