/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# ifdef FT_PRINTF_USE_STDIO
#  include <stdio.h>
# endif // FT_PRINTF_USE_STDIO

ssize_t
ft_printf(
	const char *restrict format,
	...);
ssize_t
ft_dprintf(
	int fd,
	const char *restrict format,
	...);
ssize_t
ft_sprintf(
	char *restrict str,
	const char *restrict format,
	...);
ssize_t
ft_snprintf(
	char *restrict str,
	size_t size,
	const char *restrict format,
	...);
ssize_t
ft_vprintf(
	const char *restrict format,
	va_list ap);
ssize_t
ft_vdprintf(
	int fd,
	const char *restrict format,
	va_list ap);
ssize_t
ft_vsprintf(
	char *restrict str,
	const char *restrict format,
	va_list ap);
ssize_t
ft_vsnprintf(
	char *restrict str,
	size_t size,
	const char *restrict format,
	va_list ap);
ssize_t
ft_asprintf(
	char **restrict strp,
	const char *restrict fmt,
	...);

# ifdef FT_PRINTF_USE_STDIO

ssize_t
fprintf(
	FILE *restrict stream,
	const char *restrict format,
	...);
ssize_t
ft_vfprintf(
	FILE *restrict stream,
	const char *restrict format,
	va_list ap);
ssize_t
ft_vasprintf(
	char **restrict strp,
	const char *restrict fmt,
	va_list ap);
# endif // FT_PRINTF_USE_STDIO

#endif // FT_PRINTF_H
