#include "printf.h"
#include "args.h"

char
	*ft_strchr(const char *s, int c)
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
	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

ssize_t
	printf_internal(t_buffer *buf, const char *fmt, va_list pa)
{
	const char	*p;
	const char	*s;
	t_args		args;

	p = fmt;
	while (*p)
	{
		s = ft_strchr(p, '%');
		if (!s)
			break ;
		if (s[1] == '%')
		{
			printf_buffer_write(buf, p, s - p + 1);
			p = s + 2;
		}
		else
		{
			printf_buffer_write(buf, p, s - p);
			p = s + 1;
			printf_parse_positional_conversion(&p, &args);
			printf_parse_flags(&p, &args);
			asm("int $3");
		}
	}
	printf_buffer_write(buf, p, ft_strlen(p));
	printf_buffer_flush(buf);
	return (buf->written_bytes);
}
