NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -pedantic -D_GNU_SOURCE -O2
IFLAGS :=
LFLAGS :=

# Objects
SOURCES := $(wildcard src/*.c)
OBJECTS := $(addprefix objs/,$(SOURCES:.c=.o))

SOURCES_TEST := $(wildcard tests/*.c)
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
printf-tests: CFLAGS += -ggdb -fsanitize=address
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
