NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -pedantic -D_GNU_SOURCE -O2
IFLAGS :=
LFLAGS :=

# Objects
SOURCES := \
	src/printf_char.c \
	src/parse_positional.c \
	src/ft_printf_buffer.c \
	src/printf_string.c \
	src/printf_o.c \
	src/realloc.c \
	src/ft_printf_stdio.c \
	src/printf_d.c \
	src/ft_printf_fd.c \
	src/printf_p.c \
	src/util.c \
	src/memcpy_unaligned.c \
	src/buffer_init.c \
	src/printf_u.c \
	src/printf_x.c \
	src/buffer_write.c \
	src/printf.c \
	src/memcpy_aligned.c \
	src/parse_flags.c \
	src/ft_printf_malloc.c \
	src/parse_util.c \
	src/printf_dispatch.c \
	src/printf_util.c \
	src/printf_special.c
OBJECTS := $(addprefix objs/,$(SOURCES:.c=.o))

SOURCES_TEST := \
	tests/test_str.c \
	tests/test_decimal.c \
	tests/test_internal_buffer.c \
	tests/main.c \
	tests/test_octal.c \
	tests/test_ptr.c \
	tests/test_errno.c \
	tests/test_ext_buffer.c \
	tests/test_hex.c \
	tests/test_n.c
OBJECTS_TEST := $(addprefix objs/,$(SOURCES_TEST:.c=.o))

objs/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Library
$(NAME): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

libftprintf.so: CFLAGS += -shared -fPIC
libftprintf.so:
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCES) -o $@ $(LFLAGS)

# Tests
printf-tests: IFLAGS += -I./src
printf-tests: LFLAGS += $(NAME)
printf-tests: CFLAGS += -ggdb -fsanitize=address -DFT_PRINTF_USE_STDIO
printf-tests: $(NAME) $(OBJECTS_TEST)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_TEST) $(LFLAGS)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS_TEST)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) libftprintf.so
	$(RM) printf-tests

.PHONY: re
re: fclean all
