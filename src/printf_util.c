#include "buffer.h"

void
	printf_pad(t_buffer *buf, char pad, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf_buffer_write(buf, &pad, 1);
		++i;
	}
}
