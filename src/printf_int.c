/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "args.h"
#include "buffer.h"
#include "printf.h"

static inline int
	int_len(int x)
{
	int len;

	len = 1;
	while (x >= 10 || x <= -10)
	{
		++len;
		x /= 10;
	}
	return (len);
}

void
	printf_print_int(
		t_buffer *buf,
		const t_args *args,
		int value)
{
	//printf_buffer_write(buf, const char *s, size_t len)
	printf("int\n\n\n");
}
