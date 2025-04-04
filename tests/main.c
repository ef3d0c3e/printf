#include "../src/printf.h"
#include <stdio.h>

void call(t_buffer *buf, const char *s, ...)
{
	va_list list;
	va_start(list, s);
	printf_internal(buf, s, list);
	va_end(list);
}

int main()
{
	t_buffer buf;
	printf_buffer_init_fd(&buf, 1, 0);

	call(&buf, "TEST '%*$057d'\n", 5);

	printf_buffer_flush(&buf);
	free(buf.buffer);
	return 0;
}
