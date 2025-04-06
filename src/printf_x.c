/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

/** @brief Gets total length, with formatting applied */
static inline int
	ull_len(const t_args *args, unsigned long long int x)
{
	int	len;

	len = 1;
	len -= (x == 0 && args->precision.value == 0);
	while (x >= 16)
	{
		++len;
		x /= 16;
	}
	return (len);
}

/** @brief Prints the integer value */
static inline void
	print_value(t_buffer *buf, unsigned long long int x, int capital)
{
	static const char	*set = "0123456789abcdef0123456789ABCDEF";

	if (!x)
		printf_buffer_write(buf, set + capital * 16, 1);
	if (x >= 16)
		print_value(buf, x / 16, capital);
	if (x)
		printf_buffer_write(buf, &set[(x % 16) + capital * 16], 1);
}

void
	printf_print_llx(
		t_buffer *buf,
		const t_args *args,
		unsigned long long int x,
		int capital)
{
	const int	len = ull_len(args, x);
	int			zeroes;

	zeroes = printf_max(0, args->precision.value - len);
	if (args->flags.adjust == ADJUST_ZERO)
	{
		if (args->precision.value != -1)
			zeroes *= (x || args->precision.value != 0);
		else
			zeroes = printf_max(0, args->width.value - len);
	}
	if (args->flags.adjust != ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len - zeroes
			- args->flags.alternate * 2 * !!x);
	if (args->flags.alternate && x && capital)
		printf_buffer_write(buf, "0X", 2);
	else if (args->flags.alternate && x && !capital)
		printf_buffer_write(buf, "0x", 2);
	printf_pad(buf, '0', zeroes);
	if (args->precision.value || x)
		print_value(buf, x, capital);
	if (args->flags.adjust == ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len - zeroes
			- args->flags.alternate * 2 * !!x);
}
