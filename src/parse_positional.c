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

void
	printf_parse_positional_conversion(const char **s, t_args *args)
{
	const char *const	start = *s;
	int					value;

	args->conversion.positional = -1;
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
	args->conversion.positional = value;
}
