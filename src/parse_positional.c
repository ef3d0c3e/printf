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

static int
	positional_cmp(const t_positional *a, const t_positional *b)
{
	if (!a->val)
		return (1);
	if (!b->val)
		return (-1);
	return (a->val->value - b->val->value);
}

static void
	positional_assign(t_positional *pos, va_list ap)
{
	size_t	i;
	size_t	j;

	qsort(pos, 3, sizeof(t_positional), (int (*)(const void *, const void *))positional_cmp);
	i = 1;
	j = 0;
	while (j < 3 && pos[j].val)
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
	t_positional	pos[3];

	pos[0].position = 0;
	pos[0].val = 0;
	pos[1].position = 1;
	pos[1].val = 0;
	pos[2].position = 2;
	pos[2].val = 0;
	if (args->positional == -1)
	{
		if (args->flags.adjust_width.kind  == INT_POSITIONAL)
		{
			pos[0].val = &args->flags.adjust_width;
			++index;
		}
		if (args->width.kind  == INT_POSITIONAL)
		{
			pos[1].val = &args->width;
			++index;
		}
		if (args->precision.kind  == INT_POSITIONAL)
		{
			pos[2].val = &args->precision;
			++index;
		}
	}
	else
	{
		if (args->flags.adjust_width.kind  == INT_MTH)
			pos[0].val = &args->flags.adjust_width;
		if (args->width.kind  == INT_MTH)
			pos[1].val = &args->width;
		if (args->precision.kind  == INT_MTH)
			pos[2].val = &args->precision;
	}
	positional_assign(pos, ap);
	return (index);
}

