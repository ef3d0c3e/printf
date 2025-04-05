#include <limits.h>
#include <stdio.h>

int
printf_test(const char *fmt, ...);

int
test_ptr(void)
{
	char	buf[255];
	int		total = 0;

	snprintf(buf, 255, "%%p");
	total += printf_test(buf, 0);
	total += printf_test(buf, 1);
	total += printf_test(buf, -1);
	total += printf_test(buf, 10);
	total += printf_test(buf, -10);
	total += printf_test(buf, 100);
	total += printf_test(buf, -100);
	total += printf_test(buf, 123456);
	total += printf_test(buf, -123456);
	total += printf_test(buf, SCHAR_MIN);
	total += printf_test(buf, SCHAR_MAX);
	total += printf_test(buf, UCHAR_MAX);
	total += printf_test(buf, SHRT_MIN);
	total += printf_test(buf, SHRT_MAX);
	total += printf_test(buf, INT_MIN);
	total += printf_test(buf, INT_MAX);
	total += printf_test(buf, UINT_MAX);
	total += printf_test(buf, LONG_MIN);
	total += printf_test(buf, ULONG_MAX);
	total += printf_test(buf, LONG_LONG_MIN);
	total += printf_test(buf, LONG_LONG_MAX);
	total += printf_test(buf, ULONG_LONG_MAX);

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dp", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);

		snprintf(buf, 255, "%%-%dp", i);
		total += printf_test(buf, 0);
		total += printf_test(buf, 1);
		total += printf_test(buf, -1);
		total += printf_test(buf, 10);
		total += printf_test(buf, -10);
		total += printf_test(buf, 100);
		total += printf_test(buf, -100);
		total += printf_test(buf, 123456);
		total += printf_test(buf, -123456);
		total += printf_test(buf, SCHAR_MIN);
		total += printf_test(buf, SCHAR_MAX);
		total += printf_test(buf, UCHAR_MAX);
		total += printf_test(buf, SHRT_MIN);
		total += printf_test(buf, SHRT_MAX);
		total += printf_test(buf, INT_MIN);
		total += printf_test(buf, INT_MAX);
		total += printf_test(buf, UINT_MAX);
		total += printf_test(buf, LONG_MIN);
		total += printf_test(buf, ULONG_MAX);
		total += printf_test(buf, LONG_LONG_MIN);
		total += printf_test(buf, LONG_LONG_MAX);
		total += printf_test(buf, ULONG_LONG_MAX);
	}

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dp", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);

			snprintf(buf, 255, "%%-%d.%dp", j, i);
			total += printf_test(buf, 0);
			total += printf_test(buf, 1);
			total += printf_test(buf, -1);
			total += printf_test(buf, 10);
			total += printf_test(buf, -10);
			total += printf_test(buf, 100);
			total += printf_test(buf, -100);
			total += printf_test(buf, 123456);
			total += printf_test(buf, -123456);
			total += printf_test(buf, SCHAR_MIN);
			total += printf_test(buf, SCHAR_MAX);
			total += printf_test(buf, UCHAR_MAX);
			total += printf_test(buf, SHRT_MIN);
			total += printf_test(buf, SHRT_MAX);
			total += printf_test(buf, INT_MIN);
			total += printf_test(buf, INT_MAX);
			total += printf_test(buf, UINT_MAX);
			total += printf_test(buf, LONG_MIN);
			total += printf_test(buf, ULONG_MAX);
			total += printf_test(buf, LONG_LONG_MIN);
			total += printf_test(buf, LONG_LONG_MAX);
			total += printf_test(buf, ULONG_LONG_MAX);
		}
	}
	return (total);
}
