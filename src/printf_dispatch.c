/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dispatch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "args.h"
#include "util.h"

#include <stdint.h>

/** @brief Printf dispatch for signed decimal printing */
int
	printf_dispatch_dec_s(
	t_buffer *b,
	t_args *a,
	const char **s,
	va_list ap)
{
	if (printf_compare(s, "hhd") || printf_compare(s, "hhi"))
		printf_print_lld(b, a, (signed char)va_arg(ap, int));
	else if (printf_compare(s, "hd") || printf_compare(s, "hi"))
		printf_print_lld(b, a, (signed short)va_arg(ap, int));
	else if (printf_compare(s, "lld") || printf_compare(s, "lli"))
		printf_print_lld(b, a, va_arg(ap, long long int));
	else if (printf_compare(s, "ld") || printf_compare(s, "li"))
		printf_print_lld(b, a, va_arg(ap, long int));
	else if (printf_compare(s, "zd") || printf_compare(s, "zi"))
		printf_print_lld(b, a, va_arg(ap, ssize_t));
	else if (printf_compare(s, "jd") || printf_compare(s, "ji"))
		printf_print_lld(b, a, va_arg(ap, intmax_t));
	else if (printf_compare(s, "d") || printf_compare(s, "i"))
		printf_print_lld(b, a, va_arg(ap, int));
	else
		return (0);
	return (1);
}

/** @brief Printf dispatch for unsigned decimal printing */
int
	printf_dispatch_dec_u(
	t_buffer *b,
	t_args *a,
	const char **s,
	va_list ap)
{
	if (printf_compare(s, "hhu"))
		printf_print_llu(b, a, (unsigned char)va_arg(ap, unsigned int));
	else if (printf_compare(s, "hu"))
		printf_print_llu(b, a, (unsigned short)va_arg(ap, unsigned int));
	else if (printf_compare(s, "llu"))
		printf_print_llu(b, a, va_arg(ap, unsigned long long int));
	else if (printf_compare(s, "lu"))
		printf_print_llu(b, a, va_arg(ap, unsigned long int));
	else if (printf_compare(s, "zu"))
		printf_print_llu(b, a, va_arg(ap, size_t));
	else if (printf_compare(s, "ju"))
		printf_print_llu(b, a, va_arg(ap, uintmax_t));
	else if (printf_compare(s, "u"))
		printf_print_llu(b, a, va_arg(ap, unsigned int));
	else
		return (0);
	return (1);
}

/** @brief Printf dispatch for hexadecimal printing */
int
	printf_dispatch_hex(
	t_buffer *b,
	t_args *a,
	const char **s,
	va_list ap)
{
	if (printf_compare(s, "hhx"))
		printf_print_llx(b, a, (unsigned char)va_arg(ap, unsigned int), 0);
	else if (printf_compare(s, "hx"))
		printf_print_llx(b, a, (unsigned short)va_arg(ap, unsigned int), 0);
	else if (printf_compare(s, "llx"))
		printf_print_llx(b, a, va_arg(ap, unsigned long long int), 0);
	else if (printf_compare(s, "lx"))
		printf_print_llx(b, a, va_arg(ap, unsigned long int), 0);
	else if (printf_compare(s, "zx"))
		printf_print_llx(b, a, va_arg(ap, size_t), 0);
	else if (printf_compare(s, "jx"))
		printf_print_llx(b, a, va_arg(ap, uintmax_t), 0);
	else if (printf_compare(s, "x"))
		printf_print_llx(b, a, va_arg(ap, unsigned int), 0);
	else if (printf_compare(s, "hhX"))
		printf_print_llx(b, a, (unsigned char)va_arg(ap, unsigned int), 1);
	else if (printf_compare(s, "hX"))
		printf_print_llx(b, a, (unsigned short)va_arg(ap, unsigned int), 1);
	else if (printf_compare(s, "llX"))
		printf_print_llx(b, a, va_arg(ap, unsigned long long int), 1);
	else if (printf_compare(s, "lX"))
		printf_print_llx(b, a, va_arg(ap, unsigned long int), 1);
	else if (printf_compare(s, "zX"))
		printf_print_llx(b, a, va_arg(ap, size_t), 1);
	else if (printf_compare(s, "jX"))
		printf_print_llx(b, a, va_arg(ap, uintmax_t), 1);
	else if (printf_compare(s, "X"))
		printf_print_llx(b, a, va_arg(ap, unsigned int), 1);
	else if (printf_compare(s, "p"))
		printf_print_p(b, a, va_arg(ap, void *));
	else
		return (0);
	return (1);
}

/** @brief Printf dispatch for other conversions */
int
	printf_dispatch_rest(
	t_buffer *b,
	t_args *a,
	const char **s,
	va_list ap)
{
	if (printf_compare(s, "hho"))
		printf_print_llo(b, a, (unsigned char)va_arg(ap, unsigned int));
	else if (printf_compare(s, "ho"))
		printf_print_llo(b, a, (unsigned short)va_arg(ap, unsigned int));
	else if (printf_compare(s, "llo"))
		printf_print_llo(b, a, va_arg(ap, unsigned long long int));
	else if (printf_compare(s, "lo"))
		printf_print_llo(b, a, va_arg(ap, unsigned long int));
	else if (printf_compare(s, "zo"))
		printf_print_llo(b, a, va_arg(ap, size_t));
	else if (printf_compare(s, "jo"))
		printf_print_llo(b, a, va_arg(ap, uintmax_t));
	else if (printf_compare(s, "o"))
		printf_print_llo(b, a, va_arg(ap, unsigned int));
	else if (printf_compare(s, "c"))
		printf_print_char(b, a, va_arg(ap, int));
	else if (printf_compare(s, "s"))
		printf_print_string(b, a, va_arg(ap, const char *));
	else
		return (0);
	return (1);
}
