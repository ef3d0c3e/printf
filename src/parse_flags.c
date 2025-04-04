/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "args.h"
#include <stdio.h>

int
	parse_width(const char **s)
{
	int	width;

	width = 0;
	while (**s >= '0' && **s <= '9')
	{
		width = width * 10 + (**s - '0');
		++(*s);
	}
	return (width);
}

/** @brief Parses adjustment */
static inline void
	parse_flags_adjust(const char **s, t_args *args)
{
	if (**s == '0')
	{
		++(*s);
		if (args->flags.adjust != ADJUST_LEFT)
		{
			args->flags.adjust_width = printf_int_parser(s, args);
			args->flags.adjust = ADJUST_ZERO;
		}
		else
			(void)printf_int_parser(s, args);
	}
	else if (**s == '-')
	{
		++(*s);
		args->flags.adjust_width = printf_int_parser(s, args);
		args->flags.adjust = ADJUST_LEFT;
	}
}

void
	printf_parse_flags(const char **s, t_args *args)
{
	printf("HERE: '%s'\n", *s);
	args->flags.alternate = 0;
	args->flags.adjust = ADJUST_DEFAULT;
	args->flags.adjust_width = (t_int_value){.kind = INT_LITERAL, .value = 0};
	args->flags.sign = SIGN_DEFAULT;
	while (**s)
	{
		if (**s == '#')
			args->flags.alternate = 1;
		else if (**s == '0' || **s == '-')
			parse_flags_adjust(s, args);
		else if (**s == ' ' && args->flags.sign != SIGN_ALWAYS)
			args->flags.sign = SIGN_BLANK;
		else if (**s == '+')
			args->flags.sign = SIGN_ALWAYS;
		else
			return ;
		++(*s);
	}
}
