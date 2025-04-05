#include <stdio.h>

int
printf_test(const char *fmt, ...);

static inline int
test_char()
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 20; ++i)
	{
		snprintf(buf, 255, "%%%dX", i);
		for (int c = -255; c < 255; ++c)
			total += printf_test(buf, c);
		for (int k = 0; k < 2; ++k)
		{
			snprintf(buf, 255, "%%%c%dX", "#-"[k], i);
			for (int c = -255; c < 255; ++c)
				total += printf_test(buf, c);
		}
	}
	return (total);
}

static inline int
test_string()
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 20; ++i)
	{
		snprintf(buf, 255, "%%%ds", i);
		total += printf_test(buf, NULL);
		total += printf_test(buf, "");
		total += printf_test(buf, "foo");
		total += printf_test(buf, "bar");
		total += printf_test(buf, "baz");
		total += printf_test(buf, "lorem ipsum");
		total += printf_test(buf, "dolor sit amet");
		total += printf_test(buf, "122333444455555666666777777788888888999999999");
		for (int k = 0; k < 2; ++k)
		{
			snprintf(buf, 255, "%%%c%ds", "#-"[k], i);
			total += printf_test(buf, NULL);
			total += printf_test(buf, "");
			total += printf_test(buf, "foo");
			total += printf_test(buf, "bar");
			total += printf_test(buf, "baz");
			total += printf_test(buf, "lorem ipsum");
			total += printf_test(buf, "dolor sit amet");
			total += printf_test(buf, "122333444455555666666777777788888888999999999");
		}
	}

	for (int i = 0; i < 20; ++i)
	{
		snprintf(buf, 255, "%%.%ds", i);
		total += printf_test(buf, NULL);
		total += printf_test(buf, "");
		total += printf_test(buf, "foo");
		total += printf_test(buf, "bar");
		total += printf_test(buf, "baz");
		total += printf_test(buf, "lorem ipsum");
		total += printf_test(buf, "dolor sit amet");
		total += printf_test(buf, "122333444455555666666777777788888888999999999");
		for (int j = 0; j < 20; ++j)
		{
			snprintf(buf, 255, "%%%d.%ds", i, j);
			total += printf_test(buf, NULL);
			total += printf_test(buf, "");
			total += printf_test(buf, "foo");
			total += printf_test(buf, "bar");
			total += printf_test(buf, "baz");
			total += printf_test(buf, "lorem ipsum");
			total += printf_test(buf, "dolor sit amet");
			total += printf_test(buf, "122333444455555666666777777788888888999999999");
			for (int k = 0; k < 2; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%ds", "#-"[k], i, j);
				total += printf_test(buf, NULL);
				total += printf_test(buf, "");
				total += printf_test(buf, "foo");
				total += printf_test(buf, "bar");
				total += printf_test(buf, "baz");
				total += printf_test(buf, "lorem ipsum");
				total += printf_test(buf, "dolor sit amet");
				total += printf_test(buf, "122333444455555666666777777788888888999999999");
			}
		}
	}
	return (total);
}

int
test_str(void)
{
	return (
			test_char()
			+ test_string()
		   );
}
