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

#include <stdint.h>

int
printf_dispatch_dec_s(t_buffer *b, t_args *a, const char **s, va_list ap);
int
printf_dispatch_dec_u(t_buffer *b, t_args *a, const char **s, va_list ap);
int
printf_dispatch_hex(t_buffer *b, t_args *a, const char **s, va_list ap);
int
printf_dispatch_rest(t_buffer *b, t_args *a, const char **s, va_list ap);

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
	if (printf_dispatch_dec_s(b, a, s, ap))
	{}
	else if (printf_dispatch_dec_u(b, a, s, ap))
	{}
	else if (printf_dispatch_hex(b, a, s, ap))
	{}
	else if (printf_dispatch_rest(b, a, s, ap))
	{}
	else if (printf_compare(s, "n"))
		*va_arg(ap, int *) = b->written_bytes;
	va_end(ap);
}

static inline size_t
	parse_args(t_buffer *buf, const char **s, size_t index, va_list list)
{
	t_args		args;
	va_list		cpy;

	args.positional_current = 0;
	printf_parse_positional_conversion(s, &args);
	printf_parse_flags(s, &args);
	args.width = printf_int_parser(s, &args);
	if (**s == '.')
	{
		++(*s);
		args.precision = printf_int_parser(s, &args);
		if (args.precision.kind == INT_POSITIONAL)
			args.precision.value += index;
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
