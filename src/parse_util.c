/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "args.h"

t_int_value
	printf_int_parser(const char **s, t_args *args)
{
	t_int_value	int_val;
	const char	**start = s;

	int_val.value = 0;
	int_val.kind = INT_LITERAL;
	if (**s == '*')
	{
		int_val.kind = INT_POSITIONAL;
		++(*s);
		start = s;
	}
	while (**s >= '0' && **s <= '9')
	{
		int_val.value = int_val.value * 10 + (**s - '0');
		++(*s);
	}
	if (int_val.kind == INT_POSITIONAL)
	{
		if (**s == '$')
		{
			int_val.kind = INT_MTH;
			++(*s);
		}
		else
		{
			int_val.value = ++args->positional_current;
			s = start;
		}
	}
	return (int_val);
}
