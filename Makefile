NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Wconversion -pedantic -D_GNU_SOURCE -O2
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

objs/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Library
$(NAME): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

bonus: $(OBJECTS)
	$(AR) rcs $(NAME) $(OBJECTS)

libftprintf.so: CFLAGS += -shared -fPIC
libftprintf.so:
	$(CC) $(CFLAGS) $(IFLAGS) $(SOURCES) -o $@ $(LFLAGS)


.PHONY: all
all: $(NAME) bonus

.PHONY: clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) libftprintf.so
	$(RM) printf-tests

.PHONY: re
re: fclean all
