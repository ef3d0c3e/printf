/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
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

static inline void
	dispatch(t_buffer *b, t_args *a, const char **s, va_list list)
{
	va_list	ap;
	size_t	i;

	if (printf_compare(s, "m"))
	{
		printf_print_m(b, a);
		return ;
	}
	va_copy(ap, list);
	i = 0;
	while (++i < (size_t)a->positional)
		(void)va_arg(ap, int);
	// decimal
	if (printf_compare(s, "hhd") || printf_compare(s, "hhi"))
		printf_print_lld(b, a, (signed char)va_arg(ap, int));
	else if (printf_compare(s, "hd") || printf_compare(s, "hi"))
		printf_print_lld(b, a, (signed short)va_arg(ap, int));
	else if (printf_compare(s, "lld") || printf_compare(s, "lli"))
		printf_print_lld(b, a, va_arg(ap, long long int));
	if (printf_compare(s, "ld") || printf_compare(s, "li"))
		printf_print_lld(b, a, va_arg(ap, long int));
	else if (printf_compare(s, "d") || printf_compare(s, "i"))
		printf_print_lld(b, a, va_arg(ap, int));
	// unsigned
	else if (printf_compare(s, "hhu"))
		printf_print_llu(b, a, (unsigned char)va_arg(ap, unsigned int));
	else if (printf_compare(s, "hu"))
		printf_print_llu(b, a, (unsigned short)va_arg(ap, unsigned int));
	else if (printf_compare(s, "llu"))
		printf_print_llu(b, a, va_arg(ap, unsigned long long int));
	if (printf_compare(s, "lu"))
		printf_print_llu(b, a, va_arg(ap, unsigned long int));
	else if (printf_compare(s, "u"))
		printf_print_llu(b, a, va_arg(ap, unsigned int));
	// hex
	else if (printf_compare(s, "hhx"))
		printf_print_llx(b, a, (unsigned char)va_arg(ap, unsigned int), 0);
	else if (printf_compare(s, "hx"))
		printf_print_llx(b, a, (unsigned short)va_arg(ap, unsigned int), 0);
	else if (printf_compare(s, "llx"))
		printf_print_llx(b, a, va_arg(ap, unsigned long long int), 0);
	if (printf_compare(s, "lx"))
		printf_print_llx(b, a, va_arg(ap, unsigned long int), 0);
	else if (printf_compare(s, "x"))
		printf_print_llx(b, a, va_arg(ap, unsigned int), 0);
	else if (printf_compare(s, "hhX"))
		printf_print_llx(b, a, (unsigned char)va_arg(ap, unsigned int), 1);
	else if (printf_compare(s, "hX"))
		printf_print_llx(b, a, (unsigned short)va_arg(ap, unsigned int), 1);
	else if (printf_compare(s, "llX"))
		printf_print_llx(b, a, va_arg(ap, unsigned long long int), 1);
	if (printf_compare(s, "lX"))
		printf_print_llx(b, a, va_arg(ap, unsigned long int), 1);
	else if (printf_compare(s, "X"))
		printf_print_llx(b, a, va_arg(ap, unsigned int), 1);
	// octal
	else if (printf_compare(s, "hho"))
		printf_print_llo(b, a, (unsigned char)va_arg(ap, unsigned int));
	else if (printf_compare(s, "ho"))
		printf_print_llo(b, a, (unsigned short)va_arg(ap, unsigned int));
	else if (printf_compare(s, "llo"))
		printf_print_llo(b, a, va_arg(ap, unsigned long long int));
	if (printf_compare(s, "lo"))
		printf_print_llo(b, a, va_arg(ap, unsigned long int));
	else if (printf_compare(s, "o"))
		printf_print_llo(b, a, va_arg(ap, unsigned int));
	// string/char
	else if (printf_compare(s, "c"))
		printf_print_char(b, a, va_arg(ap, int));
	else if (printf_compare(s, "s"))
		printf_print_string(b, a, va_arg(ap, const char *));
	va_end(ap);
}

static inline size_t
	parse_args(t_buffer *buf, const char **s, size_t index, va_list list)
{
	t_args		args;
	va_list		cpy;

	printf_parse_positional_conversion(s, &args);
	printf_parse_flags(s, &args);
	args.width = printf_int_parser(s, &args);
	if (**s == '.')
	{
		++(*s);
		args.precision = printf_int_parser(s, &args);
	}
	else
		args.precision = (t_int_value){.kind = INT_LITERAL, .value = -1};
	va_copy(cpy, list);
	index = printf_parse_positional(index, &args, cpy);
	va_end(cpy);
	if (args.positional == -1)
		args.positional = ++index;
	dispatch(buf, &args, s, list);
	return (index);
}

void
	printf_internal(t_buffer *buf, const char *fmt, va_list pa)
{
	const char	*p;
	const char	*s;
	size_t		index;

	index = 0;
	p = fmt;
	while (*p)
	{
		s = printf_strchr(p, '%');
		if (!s)
			break ;
		if (s[1] == '%')
		{
			printf_buffer_write(buf, p, s - p + 1);
			p = s + 2;
		}
		else
		{
			printf_buffer_write(buf, p, s - p);
			p = s + 1;
			index = parse_args(buf, &p, index, pa);
		}
	}
	printf_buffer_write(buf, p, printf_strlen(p));
	printf_buffer_flush(buf);
}
