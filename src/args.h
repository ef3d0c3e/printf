/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARGS_H
# define ARGS_H

enum e_adjust_flags
{
	/** @brief No adjustement flags */
	ADJUST_DEFAULT,
	/** @brief Left-padded with `0`: `0` */
	ADJUST_ZERO,
	/** @brief Left-padded with blanks: `-` */
	ADJUST_LEFT,
};

enum e_sign_flags
{
	/** @brief No signs for positrive numbers */
	SIGN_DEFAULT,
	/** @brief Displays a blank for positive numbers: ` ` */
	SIGN_BLANK,
	/** @brief Display a `+` for positive numbers: `+` */
	SIGN_ALWAYS,
};

struct s_args_flags
{
	/** @brief Alternate conversion: `#` */
	int					alternate;
	/** @brief Zero padded: `0`, or left adjusted: `-` */
	enum e_adjust_flags	adjust;
	/** @brief Adjustement width */
	int					adjust_width;
	/** @brief Controls how the sign is displayed for positive numbers */
	enum e_sign_flags	sign;
};

/**
 * @brief Arguments for formatting options
 */
typedef struct s_args
{
	/** @brief Type of argument */
	const char			*arg;
	/** @brief Printf flags */
	struct s_args_flags	flags;
	union {
		
	};
}	t_args;

/**
 * @brief Parses flags from specifier
 *
 * @param s Specifier
 * @param args Args to be parsed
 */
void
printf_parse_flags(const char **s, t_args *args);

#endif // ARGS_H
