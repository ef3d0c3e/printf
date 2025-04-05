/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

ssize_t
	ft_vprintf(
	const char *restrict format,
	va_list ap)
{
	t_buffer	buf;
	ssize_t		written;

	printf_buffer_init_fd(&buf, STDOUT_FILENO, 0);
	printf_internal(&buf, format, ap);
	written = printf_buffer_flush(&buf);
	return (written);
}

ssize_t
	ft_printf(
	const char *restrict format,
	...)
{
	ssize_t	written;
	va_list	ap;

	va_start(ap, format);
	written = ft_vprintf(format, ap);
	va_end(ap);
	return (written);
}

ssize_t
	ft_vdprintf(
	int fd,
	const char *restrict format,
	va_list ap)
{
	t_buffer	buf;
	ssize_t		written;

	printf_buffer_init_fd(&buf, fd, 0);
	printf_internal(&buf, format, ap);
	written = printf_buffer_flush(&buf);
	return (written);
}

ssize_t
	ft_dprintf(
	int fd,
	const char *restrict format,
	...)
{
	ssize_t	written;
	va_list	ap;

	va_start(ap, format);
	written = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (written);
}
