/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_malloc.c                                 :+:      :+:    :+:   */
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
	ft_vasprintf(
	char **restrict strp,
	const char *restrict fmt,
	va_list ap)
{
	t_buffer	buf;
	ssize_t		written;

	printf_buffer_init_malloc(&buf, 256);
	printf_internal(&buf, fmt, ap);
	written = printf_buffer_flush(&buf);
	*strp = buf.buffer;
	return (written);
}

ssize_t
	ft_asprintf(
	char **restrict strp,
	const char *restrict fmt,
	...)
{
	va_list	ap;
	ssize_t	written;

	va_start(ap, fmt);
	written = ft_vasprintf(strp, fmt, ap);
	va_end(ap);
	return (written);
}
