/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_positional.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "args.h"
#include <stdlib.h>

void
	printf_parse_positional_conversion(const char **s, t_args *args)
{
	const char *const	start = *s;
	int					value;

	args->positional = -1;
	value = 0;
	while (**s >= '0' && **s <= '9')
	{
		value = value * 10 + (**s - '0');
		++(*s);
	}
	if (**s != '$')
	{
		*s = start;
		return ;
	}
	++(*s);
	args->positional = value;
}

/** @brief Swaps two positional arguments */
static inline void
	positional_swap(t_positional *a, t_positional *b)
{
	t_positional	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void
	positional_assign(t_positional *pos, va_list ap)
{
	size_t	i;
	size_t	j;

	if (pos[1].val && !pos[0].val)
		positional_swap(pos + 0, pos + 1);
	else if (pos[1].val && pos[0].val->value < pos[1].val->value)
		positional_swap(pos + 0, pos + 1);
	i = 1;
	j = 0;
	while (j < 2 && pos[j].val)
	{
		if ((size_t)pos[j].val->value == i)
		{
			pos[j].val->value = va_arg(ap, int);
			++j;
		}
		else
			va_arg(ap, int);
		++i;
	}
}

size_t
	printf_parse_positional(
		size_t index,
		t_args *args,
		va_list ap)
{
	t_positional	pos[2];

	pos[0].position = 1;
	pos[0].val = 0;
	pos[1].position = 2;
	pos[1].val = 0;
	if (args->positional == -1)
	{
		if (args->width.kind == INT_POSITIONAL)
			pos[0].val = &args->width;
		if (args->precision.kind == INT_POSITIONAL)
			pos[1].val = &args->precision;
		index += (args->width.kind == INT_POSITIONAL)
			+ (args->precision.kind == INT_POSITIONAL);
	}
	else
	{
		if (args->width.kind == INT_MTH)
			pos[0].val = &args->width;
		if (args->precision.kind == INT_MTH)
			pos[1].val = &args->precision;
	}
	positional_assign(pos, ap);
	return (index);
}
