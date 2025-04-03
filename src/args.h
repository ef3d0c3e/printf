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

/******************************************************************************/
/* Arguments definitions                                                      */
/******************************************************************************/

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

enum e_int_value_kind
{
	/** @brief Literal value: `5d` will use 5 as the width */
	INT_LITERAL,
	/** @brief Uses the next argument as value: `*d` will use the first
	 * provided argument as width */
	INT_POSITIONAL,
	/** @brief Uses the next m-th argument: `*3$d` will use the third argument
	 * as width */
	INT_MTH,
};

/** @brief Integer value */
typedef struct s_int_value
{
	/** @brief The kind of integer value */
	enum e_int_value_kind	kind;
	/** @brief The value, see the kind for usage */
	int						value;
}	t_int_value;

/** @brief The conversion specifier */
struct s_conversion
{
	/** @brief Type of argument */
	const char			*specifier;
	/** @brief Position of the value to convert, -1 if unspecified */
	int					positional;
};

/** @brief The formatting flags */
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
	/** @brief Current position in the positional values */
	int					positional_current;
	/** @brief The conversion specifier */
	struct s_conversion	conversion;
	/** @brief Printf flags */
	struct s_args_flags	flags;
}	t_args;

/******************************************************************************/
/* Arguments parsers                                                          */
/******************************************************************************/

/**
 * @brief Parses the positional conversion specifier, e.g `%m$`
 *
 * @param s Specifier
 * @param args Args to be parsed
 */
void
printf_parse_positional_conversion(const char **s, t_args *args);
/**
 * @brief Parses flags from specifier
 *
 * @param s Specifier
 * @param args Args to be parsed
 */
void
printf_parse_flags(const char **s, t_args *args);

/******************************************************************************/
/* Uttility parsers                                                           */
/******************************************************************************/

/**
 * @brief Parses integer value, either given literally or via `m$` and `*`
 *
 * @param **s Specifiers
 * @param args Args to be parsed
 *
 * @returns The parsed int value. In case `s` is not a valid integer, a literal
 * with value `0` is returned.
 */
t_int_value
printf_int_parser(const char **s, t_args *args);

#endif // ARGS_H
