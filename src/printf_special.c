/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <errno.h>
#include <string.h>

/** @brief Print errno value in alternate mode when `strerrorname_np` fails */
static inline void
	print_errno_default(t_buffer *buf, int err)
{
	if (err >= 10)
		print_errno_default(buf, err / 10);
	printf_buffer_write(buf, &"0123456789"[err % 10], 1);
}

void
	printf_print_m(
		t_buffer *buf,
		const t_args *args)
{
	const int	err = errno;
	const char	*s;

	if (args->flags.alternate)
		s = strerrorname_np(err);
	else
		s = strerror(err);
	if (!s && args->flags.alternate)
		print_errno_default(buf, err);
	else if (s)
		printf_buffer_write(buf, s, printf_strlen(s));
}
