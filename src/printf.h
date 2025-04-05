/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H

# include "buffer.h"
# include "args.h"
# include "util.h"

/**
 * @brief Internal printf function
 *
 * @param buf Write buffer
 * @param format Format string
 * @param args Arguments
 */
void
printf_internal(t_buffer *buf, const char *format, va_list args);

/** @brief `long long int` printing as decimal: `lld` or `lli` */
void
printf_print_lld(
	t_buffer *buf,
	const t_args *args,
	long long int value);
/** @brief `unsigned long long int` printing as decimal: `llu` */
void
printf_print_llu(
	t_buffer *buf,
	const t_args *args,
	unsigned long long int value);
/** @brief `unsigned long long int` printing as hex: `x` or `X` */
void
printf_print_llx(
	t_buffer *buf,
	const t_args *args,
	unsigned long long int value,
	int capital);
/** @brief `unsigned long long int` printing as octal: `o` */
void
printf_print_llo(
	t_buffer *buf,
	const t_args *args,
	unsigned long long int value);
/** @brief string printing: `s` */
void
printf_print_string(
	t_buffer *buf,
	const t_args *args,
	const char *c);
/** @brief `unsigned char` printing: `c` */
void
printf_print_char(
	t_buffer *buf,
	const t_args *args,
	unsigned char c);

#endif // PRINTF_H
