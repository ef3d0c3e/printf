/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_o.c                                         :+:      :+:    :+:   */
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
	len -= (x == 0 && args->precision.value == 0 && !args->flags.alternate);
	while (x >= 8)
	{
		++len;
		x /= 8;
	}
	return (len);
}

/** @brief Prints the integer value */
static inline void
	print_value(t_buffer *buf, unsigned long long int x)
{
	static const char	*set = "01234567";

	if (!x)
		printf_buffer_write(buf, set, 1);
	if (x >= 8)
		print_value(buf, x / 8);
	if (x)
		printf_buffer_write(buf, &set[(x % 8)], 1);
}

void
	printf_print_llo(
		t_buffer *buf,
		const t_args *args,
		unsigned long long int x)
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
	if (args->flags.alternate && x && !zeroes)
		zeroes ++;
	if (args->flags.adjust != ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len - zeroes);
	printf_pad(buf, '0', zeroes);
	if (args->precision.value || x || args->flags.alternate)
		print_value(buf, x);
	if (args->flags.adjust == ADJUST_LEFT)
		printf_pad(buf, ' ', args->width.value - len - zeroes);
}
