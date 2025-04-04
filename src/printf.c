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
	dispatch(t_buffer *buf, t_args *args, const char **s, va_list list)
{
	va_list	cpy;
	size_t	i;

	va_copy(cpy, list);
	i = 0;
	while (++i < (size_t)args->positional)
		(void)va_arg(cpy, int);
	if (printf_compare(s, "s"))
		printf("String");
	if (printf_compare(s, "d") || printf_compare(s, "i"))
		printf_print_int(buf, args, va_arg(cpy, int));
	if (printf_compare(s, "x"))
		printf_print_hex(buf, args, va_arg(cpy, unsigned int),
			"0123456789abcdef0x");
	if (printf_compare(s, "X"))
		printf_print_hex(buf, args, va_arg(cpy, unsigned int),
			"0123456789ABCDEF0X");
	va_end(cpy);
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
