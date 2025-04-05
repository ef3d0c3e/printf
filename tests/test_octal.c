#include <limits.h>
#include <stdio.h>

int
printf_test(const char *fmt, ...);

static inline int
test_oct_hhd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dhho", i);
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

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dhho", "#0- +"[k], i);
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

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dhho", j, i);
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

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dhho", "#- +"[k], j, i);
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
	}
	return (total);
}

static inline int
test_oct_hd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dho", i);
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

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dho", "#0- +"[k], i);
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

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dho", j, i);
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

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dho", "#- +"[k], j, i);
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
	}
	return (total);
}

static inline int
test_oct_d(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%do", i);
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

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%do", "#0- +"[k], i);
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

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%do", j, i);
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

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%do", "#- +"[k], j, i);
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
	}
	return (total);
}

static inline int
test_oct_ld(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dlo", i);
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

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dlo", "#0- +"[k], i);
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

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dlo", j, i);
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

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dlo", "#- +"[k], j, i);
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
	}
	return (total);
}

static inline int
test_oct_lld(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dllo", i);
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

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dllo", "#0- +"[k], i);
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

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dllo", j, i);
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

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dllo", "#- +"[k], j, i);
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
	}
	return (total);
}

static inline int
test_oct_zd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%dzo", i);
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

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%dzo", "#0- +"[k], i);
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

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%dzo", j, i);
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

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%dzo", "#- +"[k], j, i);
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
	}
	return (total);
}

static inline int
test_oct_jd(void)
{
	char	buf[255];
	int		total = 0;

	for (int i = 0; i < 15; ++i)
	{
		snprintf(buf, 255, "%%%djo", i);
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

		for (int k = 0; k < 5; ++k)
		{
			snprintf(buf, 255, "%%%c%djo", "#0- +"[k], i);
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

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			snprintf(buf, 255, "%%%d.%djo", j, i);
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

			for (int k = 0; k < 4; ++k)
			{
				snprintf(buf, 255, "%%%c%d.%djo", "#- +"[k], j, i);
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
	}
	return (total);
}

int
test_octal(void)
{
	return (
			test_oct_hhd()
			+ test_oct_hd()
			+ test_oct_d()
			+ test_oct_ld()
			+ test_oct_lld()
			+ test_oct_zd()
			+ test_oct_jd()
		   );
}
