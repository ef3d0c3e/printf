/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

static inline size_t
	strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (i < maxlen && s[i])
		++i;
	return (i);
}

void
	printf_print_string(
		t_buffer *buf,
		const t_args *args,
		const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
	{
		if (args->precision.value == -1 || args->precision.value >= 6)
		{
			s = "(null)";
			len = 6;
		}
	}
	else
		len = strnlen(s, (size_t)args->precision.value);
	if (args->flags.adjust == ADJUST_RIGHT)
		printf_pad(buf, ' ', args->width.value - len);
	printf_buffer_write(buf, s, len);
	if (args->flags.adjust == ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len);
}
