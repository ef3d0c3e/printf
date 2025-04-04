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

void
	printf_parse_flags(const char **s, t_args *args)
{
	args->flags.alternate = 0;
	args->flags.adjust = ADJUST_DEFAULT;
	args->flags.sign = SIGN_DEFAULT;
	while (**s)
	{
		if (**s == '#')
			args->flags.alternate = 1;
		else if (**s == ' ' && args->flags.sign != SIGN_ALWAYS)
			args->flags.sign = SIGN_BLANK;
		else if (**s == '+')
			args->flags.sign = SIGN_ALWAYS;
		else
			break ;
		++(*s);
	}
	while (**s)
	{
		if (**s == '0' && args->flags.adjust != ADJUST_LEFT)
			args->flags.adjust = ADJUST_ZERO;
		else if (**s == '-')
			args->flags.adjust = ADJUST_LEFT;
		else
			break ;
		++(*s);
	}
}
