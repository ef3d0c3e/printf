/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <linogamba@pundalik.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:59:40 by lgamba            #+#    #+#             */
/*   Updated: 2025/03/17 11:59:41 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "util.h"
#include <stddef.h>

char
	*printf_strchr(const char *s, int c)
{
	const unsigned char     *mem;

	mem = (const unsigned char *)s;
	while (*mem != (unsigned char)c)
	{
		if (!*mem)
			return (0);
		++mem;
	}
	return ((char *)mem);
}

size_t
	printf_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

int
	printf_compare(const char **p, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == (*p)[i])
		++i;
	if (!s[i])
		*p = *p + i;
	return (s[i] == 0);
}
